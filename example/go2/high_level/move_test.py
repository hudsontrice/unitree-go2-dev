import time
from unitree_sdk2py.core.channel import ChannelFactoryInitialize, ChannelSubscriber
from unitree_sdk2py.go2.sport.sport_client import SportClient
from unitree_sdk2py.idl.unitree_go.msg.dds_ import SportModeState_

IFACE = "enp3s0"  # change if needed

# Candidate topics for state (same logic as reader)
SPORT_STATE_TOPICS = [
	"rt/sportmodestate", "sportmodestate", "rt/sportmode/state", "rt/highstate", "highstate"
]

def stream_velocity(sc: SportClient, duration: float, vx: float=0.0, vy: float=0.0, vyaw: float=0.0, hz: float=30.0):
	"""Continuously send Move commands to maintain smooth motion.
	Note: The Move API is a velocity command that decays unless refreshed.
	vyaw is yaw rate (rad/s). Positive usually spins left (CCW) viewed from above.
	"""
	period = 1.0 / hz
	end_t = time.time() + duration
	while time.time() < end_t:
		sc.Move(vx, vy, vyaw)
		time.sleep(period)

def get_state_subscriber():
	for t in SPORT_STATE_TOPICS:
		try:
			sub = ChannelSubscriber(t, SportModeState_)
			sub.Init()
			# quick probe
			sample = sub.Read(0.05)
			return sub, t
		except Exception:
			continue
	return None, None

def read_position(sub):
	if sub is None:
		return None
	s = sub.Read(0.0)
	if s and hasattr(s, 'position'):
		# position[0], position[1] -> planar x,y (assumed) in meters
		return (s.position[0], s.position[1])
	return None

def move_and_return(sc: SportClient, sub, desc: str, fwd_args: dict, back_args: dict, tol=0.05):
	"""Execute a motion then mirror it to return near start.
	If state available, we keep correcting until within tol meters or timeout.
	fwd_args/back_args: kwargs to stream_velocity (vx, vy, vyaw, duration,...)
	"""
	print(desc)
	start_pos = read_position(sub)
	stream_velocity(sc, **fwd_args)
	sc.StopMove(); time.sleep(0.2)
	stream_velocity(sc, **back_args)
	sc.StopMove(); time.sleep(0.2)
	if start_pos:
		# corrective loop (planar)
		t_end = time.time() + 2.0
		while time.time() < t_end:
			cur = read_position(sub)
			if not cur:
				break
			dx = cur[0] - start_pos[0]
			dy = cur[1] - start_pos[1]
			dist = (dx*dx + dy*dy)**0.5
			if dist < tol:
				break
			# small corrective command
			sc.Move(-dx*0.8, -dy*0.8, 0.0)
			time.sleep(0.05)
		sc.StopMove(); time.sleep(0.1)

def spin_and_unspin(sc: SportClient, duration=2.0, rate=0.6):
	print(f"Spin left {rate} rad/s for {duration}s then reverse")
	stream_velocity(sc, duration=duration, vyaw=rate)
	sc.StopMove(); time.sleep(0.2)
	stream_velocity(sc, duration=duration, vyaw=-rate)
	sc.StopMove(); time.sleep(0.3)

def main():
	ChannelFactoryInitialize(0, IFACE)
	sc = SportClient(); sc.SetTimeout(5); sc.Init()
	print("Stand up"); sc.StandUp(); time.sleep(2.0)

	# Optional: set speed level / gait
	try:
		sc.SpeedLevel(1)
	except Exception:
		pass

	state_sub, topic = get_state_subscriber()
	if topic:
		print(f"[INFO] State topic: {topic}")
	else:
		print("[WARN] No state topic lock; will use timed symmetry only.")

	# Spin test (yaw symmetry)
	spin_and_unspin(sc, duration=2.0, rate=0.6)

	# Forward then back
	move_and_return(
		sc, state_sub,
		desc="Forward 0.3 m/s 2s then return",
		fwd_args={"duration":2.0, "vx":0.3},
		back_args={"duration":2.0, "vx":-0.3}
	)

	# Lateral left then right
	move_and_return(
		sc, state_sub,
		desc="Left 0.2 m/s 2s then return",
		fwd_args={"duration":2.0, "vy":0.2},
		back_args={"duration":2.0, "vy":-0.2}
	)

	print("Lie down"); sc.StandDown(); time.sleep(2.0)
	print("Damp"); sc.Damp(); print("Done.")

if __name__ == "__main__":
	main()