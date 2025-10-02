#!/usr/bin/env python3
"""Spin the Go2 robot one full 360° turn in place.

Strategy:
1. Stand up.
2. Stream yaw rate commands (Move vx=vy=0, vyaw>0) at 30 Hz.
3. If sport state topic available, integrate IMU yaw to stop near +360° (2π rad) from start.
4. Otherwise estimate duration = target_angle / rate and time it.
5. Stop, optionally counter-correct small overshoot, then stand down & damp.

Adjustables near top of file.
"""
import time, math, sys
from unitree_sdk2py.core.channel import ChannelFactoryInitialize, ChannelSubscriber
from unitree_sdk2py.go2.sport.sport_client import SportClient
from unitree_sdk2py.idl.unitree_go.msg.dds_ import SportModeState_

# ----------------- User Tunables -----------------
IFACE = sys.argv[1] if len(sys.argv) > 1 else "enp3s0"
YAW_RATE = 0.6          # rad/s commanded spin rate
COMMAND_HZ = 30.0       # command streaming rate
TARGET_DEG = 360.0      # desired spin in degrees
ALLOW_OVERSHOOT_DEG = 5 # acceptable overshoot window
STATE_TOPICS = ["rt/sportmodestate", "sportmodestate", "rt/sportmode/state", "rt/highstate", "highstate"]
SPIN_DIRECTION = 1      # +1 CCW, -1 CW (change to -1 for opposite)
POST_CORRECT = True     # attempt minor correction if overshoot big

# --------------------------------------------------

def get_state_sub():
	for t in STATE_TOPICS:
		try:
			sub = ChannelSubscriber(t, SportModeState_)
			sub.Init()
			# quick probe
			sample = sub.Read(0.05)
			return sub, t
		except Exception:
			continue
	return None, None

def normalize_angle(a):
	"""Wrap to (-pi, pi]."""
	while a <= -math.pi:
		a += 2*math.pi
	while a > math.pi:
		a -= 2*math.pi
	return a

def main():
	print(f"Interface: {IFACE}")
	ChannelFactoryInitialize(0, IFACE)
	sc = SportClient(); sc.SetTimeout(5); sc.Init()
	print("Stand up...")
	sc.StandUp(); time.sleep(2.0)

	# Activation sequence to ensure gait engine accepts velocity commands
	try:
		sc.BalanceStand(); print("BalanceStand sent")
		time.sleep(0.8)
	except Exception:
		pass
	try:
		sc.SpeedLevel(1); print("SpeedLevel(1) sent")
	except Exception:
		pass
	# Warm-up: tiny forward/back pulses (some firmware needs initial trigger)
	print("Warm-up forward/back pulses")
	for _ in range(10):
		sc.Move(0.15,0,0); time.sleep(0.05)
	for _ in range(10):
		sc.Move(-0.10,0,0); time.sleep(0.05)
	sc.StopMove(); time.sleep(0.3)

	# If still no movement later, we can optionally toggle FreeWalk
	def try_enable_freewalk():
		try:
			code = sc.FreeWalk()
			print(f"FreeWalk code={code}")
		except Exception as e:
			print("FreeWalk enable failed", e)

	try:
		sc.SpeedLevel(1)
	except Exception:
		pass

	sub, topic = get_state_sub()
	if topic:
		print(f"[INFO] Using state topic: {topic}")
	else:
		print("[WARN] No state topic; will time the spin (less precise).")

	target_rad = math.radians(TARGET_DEG)
	cmd_period = 1.0/COMMAND_HZ
	start_yaw = None
	last_yaw = None
	accumulated = 0.0
	start_time = time.time()

	# Helper to read yaw from IMU RPY (assuming rpy[2] is yaw)
	def read_yaw():
		if not sub:
			return None
		s = sub.Read(0.0)
		if not s:
			return None
		imu = getattr(s, 'imu_state', None)
		if not imu:
			return None
		# yaw is rpy[2]
		return imu.rpy[2]

	print(f"Spinning {TARGET_DEG} deg at {YAW_RATE} rad/s ...")
	no_motion_counter = 0
	try:
		while True:
			now = time.time()
			yaw = read_yaw()
			# Initialize yaw reference
			if yaw is not None and start_yaw is None:
				start_yaw = yaw
				last_yaw = yaw
			# Integrate if we have yaw data
			if yaw is not None and last_yaw is not None:
				dyaw = normalize_angle(yaw - last_yaw)
				accumulated += dyaw * SPIN_DIRECTION  # adjust sign if spinning opposite
				last_yaw = yaw
			else:
				# No yaw available; break when time-based estimate reaches target
				if not sub:
					est = (now - start_time) * abs(YAW_RATE)
					if est >= target_rad:
						break
			# Detect lack of motion (if yaw available but not changing)
			if yaw is not None and last_yaw is not None and abs(accumulated) < 0.02:
				no_motion_counter += 1
				if no_motion_counter == int(COMMAND_HZ * 1.0):  # ~1s
					print("[WARN] No yaw change detected; attempting FreeWalk enable")
					try_enable_freewalk()
				if no_motion_counter > int(COMMAND_HZ * 2.0):  # ~2s
					print("[WARN] Still no yaw change; injecting small forward velocity during spin")
					sc.Move(0.1, 0.0, SPIN_DIRECTION * YAW_RATE)
					time.sleep(cmd_period)
					continue
			# Check target
			if accumulated >= target_rad:
				break
			# Send command
			sc.Move(0.0, 0.0, SPIN_DIRECTION * YAW_RATE)
			time.sleep(cmd_period)
	finally:
		sc.StopMove(); time.sleep(0.2)

	spun_deg = math.degrees(accumulated) if start_yaw is not None else TARGET_DEG
	print(f"Approx spun: {spun_deg:.1f} deg")

	# Optional minor correction
	if sub and POST_CORRECT and start_yaw is not None:
		error_rad = target_rad - accumulated
		error_deg = math.degrees(error_rad)
		if abs(error_deg) > ALLOW_OVERSHOOT_DEG and abs(error_deg) < 45:
			direction = 1 if error_rad > 0 else -1
			corr_rate = 0.4
			corr_time = abs(error_rad) / corr_rate
			print(f"Correction: {error_deg:.1f} deg (rate {corr_rate} rad/s for {corr_time:.2f}s)")
			end_corr = time.time() + corr_time
			while time.time() < end_corr:
				sc.Move(0,0,direction*corr_rate)
				time.sleep(cmd_period)
			sc.StopMove(); time.sleep(0.2)
			# Read final yaw
			final_yaw = read_yaw()
			if final_yaw is not None:
				total_final = normalize_angle(final_yaw - start_yaw) * SPIN_DIRECTION
				print(f"Final corrected spin: {math.degrees(total_final):.1f} deg")

	print("Stand down..."); sc.StandDown(); time.sleep(2.0)
	print("Damp..."); sc.Damp(); print("Done.")

if __name__ == "__main__":
	main()
