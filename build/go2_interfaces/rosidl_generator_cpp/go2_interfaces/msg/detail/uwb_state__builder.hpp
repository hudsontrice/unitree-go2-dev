// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from go2_interfaces:msg/UwbState.idl
// generated code does not contain a copyright notice

#ifndef GO2_INTERFACES__MSG__DETAIL__UWB_STATE__BUILDER_HPP_
#define GO2_INTERFACES__MSG__DETAIL__UWB_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "go2_interfaces/msg/detail/uwb_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace go2_interfaces
{

namespace msg
{

namespace builder
{

class Init_UwbState_enabled_from_app
{
public:
  explicit Init_UwbState_enabled_from_app(::go2_interfaces::msg::UwbState & msg)
  : msg_(msg)
  {}
  ::go2_interfaces::msg::UwbState enabled_from_app(::go2_interfaces::msg::UwbState::_enabled_from_app_type arg)
  {
    msg_.enabled_from_app = std::move(arg);
    return std::move(msg_);
  }

private:
  ::go2_interfaces::msg::UwbState msg_;
};

class Init_UwbState_buttons
{
public:
  explicit Init_UwbState_buttons(::go2_interfaces::msg::UwbState & msg)
  : msg_(msg)
  {}
  Init_UwbState_enabled_from_app buttons(::go2_interfaces::msg::UwbState::_buttons_type arg)
  {
    msg_.buttons = std::move(arg);
    return Init_UwbState_enabled_from_app(msg_);
  }

private:
  ::go2_interfaces::msg::UwbState msg_;
};

class Init_UwbState_error_state
{
public:
  explicit Init_UwbState_error_state(::go2_interfaces::msg::UwbState & msg)
  : msg_(msg)
  {}
  Init_UwbState_buttons error_state(::go2_interfaces::msg::UwbState::_error_state_type arg)
  {
    msg_.error_state = std::move(arg);
    return Init_UwbState_buttons(msg_);
  }

private:
  ::go2_interfaces::msg::UwbState msg_;
};

class Init_UwbState_joystick
{
public:
  explicit Init_UwbState_joystick(::go2_interfaces::msg::UwbState & msg)
  : msg_(msg)
  {}
  Init_UwbState_error_state joystick(::go2_interfaces::msg::UwbState::_joystick_type arg)
  {
    msg_.joystick = std::move(arg);
    return Init_UwbState_error_state(msg_);
  }

private:
  ::go2_interfaces::msg::UwbState msg_;
};

class Init_UwbState_base_yaw
{
public:
  explicit Init_UwbState_base_yaw(::go2_interfaces::msg::UwbState & msg)
  : msg_(msg)
  {}
  Init_UwbState_joystick base_yaw(::go2_interfaces::msg::UwbState::_base_yaw_type arg)
  {
    msg_.base_yaw = std::move(arg);
    return Init_UwbState_joystick(msg_);
  }

private:
  ::go2_interfaces::msg::UwbState msg_;
};

class Init_UwbState_base_pitch
{
public:
  explicit Init_UwbState_base_pitch(::go2_interfaces::msg::UwbState & msg)
  : msg_(msg)
  {}
  Init_UwbState_base_yaw base_pitch(::go2_interfaces::msg::UwbState::_base_pitch_type arg)
  {
    msg_.base_pitch = std::move(arg);
    return Init_UwbState_base_yaw(msg_);
  }

private:
  ::go2_interfaces::msg::UwbState msg_;
};

class Init_UwbState_base_roll
{
public:
  explicit Init_UwbState_base_roll(::go2_interfaces::msg::UwbState & msg)
  : msg_(msg)
  {}
  Init_UwbState_base_pitch base_roll(::go2_interfaces::msg::UwbState::_base_roll_type arg)
  {
    msg_.base_roll = std::move(arg);
    return Init_UwbState_base_pitch(msg_);
  }

private:
  ::go2_interfaces::msg::UwbState msg_;
};

class Init_UwbState_tag_yaw
{
public:
  explicit Init_UwbState_tag_yaw(::go2_interfaces::msg::UwbState & msg)
  : msg_(msg)
  {}
  Init_UwbState_base_roll tag_yaw(::go2_interfaces::msg::UwbState::_tag_yaw_type arg)
  {
    msg_.tag_yaw = std::move(arg);
    return Init_UwbState_base_roll(msg_);
  }

private:
  ::go2_interfaces::msg::UwbState msg_;
};

class Init_UwbState_tag_pitch
{
public:
  explicit Init_UwbState_tag_pitch(::go2_interfaces::msg::UwbState & msg)
  : msg_(msg)
  {}
  Init_UwbState_tag_yaw tag_pitch(::go2_interfaces::msg::UwbState::_tag_pitch_type arg)
  {
    msg_.tag_pitch = std::move(arg);
    return Init_UwbState_tag_yaw(msg_);
  }

private:
  ::go2_interfaces::msg::UwbState msg_;
};

class Init_UwbState_tag_roll
{
public:
  explicit Init_UwbState_tag_roll(::go2_interfaces::msg::UwbState & msg)
  : msg_(msg)
  {}
  Init_UwbState_tag_pitch tag_roll(::go2_interfaces::msg::UwbState::_tag_roll_type arg)
  {
    msg_.tag_roll = std::move(arg);
    return Init_UwbState_tag_pitch(msg_);
  }

private:
  ::go2_interfaces::msg::UwbState msg_;
};

class Init_UwbState_yaw_est
{
public:
  explicit Init_UwbState_yaw_est(::go2_interfaces::msg::UwbState & msg)
  : msg_(msg)
  {}
  Init_UwbState_tag_roll yaw_est(::go2_interfaces::msg::UwbState::_yaw_est_type arg)
  {
    msg_.yaw_est = std::move(arg);
    return Init_UwbState_tag_roll(msg_);
  }

private:
  ::go2_interfaces::msg::UwbState msg_;
};

class Init_UwbState_distance_est
{
public:
  explicit Init_UwbState_distance_est(::go2_interfaces::msg::UwbState & msg)
  : msg_(msg)
  {}
  Init_UwbState_yaw_est distance_est(::go2_interfaces::msg::UwbState::_distance_est_type arg)
  {
    msg_.distance_est = std::move(arg);
    return Init_UwbState_yaw_est(msg_);
  }

private:
  ::go2_interfaces::msg::UwbState msg_;
};

class Init_UwbState_pitch_est
{
public:
  explicit Init_UwbState_pitch_est(::go2_interfaces::msg::UwbState & msg)
  : msg_(msg)
  {}
  Init_UwbState_distance_est pitch_est(::go2_interfaces::msg::UwbState::_pitch_est_type arg)
  {
    msg_.pitch_est = std::move(arg);
    return Init_UwbState_distance_est(msg_);
  }

private:
  ::go2_interfaces::msg::UwbState msg_;
};

class Init_UwbState_orientation_est
{
public:
  explicit Init_UwbState_orientation_est(::go2_interfaces::msg::UwbState & msg)
  : msg_(msg)
  {}
  Init_UwbState_pitch_est orientation_est(::go2_interfaces::msg::UwbState::_orientation_est_type arg)
  {
    msg_.orientation_est = std::move(arg);
    return Init_UwbState_pitch_est(msg_);
  }

private:
  ::go2_interfaces::msg::UwbState msg_;
};

class Init_UwbState_joy_mode
{
public:
  explicit Init_UwbState_joy_mode(::go2_interfaces::msg::UwbState & msg)
  : msg_(msg)
  {}
  Init_UwbState_orientation_est joy_mode(::go2_interfaces::msg::UwbState::_joy_mode_type arg)
  {
    msg_.joy_mode = std::move(arg);
    return Init_UwbState_orientation_est(msg_);
  }

private:
  ::go2_interfaces::msg::UwbState msg_;
};

class Init_UwbState_channel
{
public:
  explicit Init_UwbState_channel(::go2_interfaces::msg::UwbState & msg)
  : msg_(msg)
  {}
  Init_UwbState_joy_mode channel(::go2_interfaces::msg::UwbState::_channel_type arg)
  {
    msg_.channel = std::move(arg);
    return Init_UwbState_joy_mode(msg_);
  }

private:
  ::go2_interfaces::msg::UwbState msg_;
};

class Init_UwbState_version
{
public:
  Init_UwbState_version()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UwbState_channel version(::go2_interfaces::msg::UwbState::_version_type arg)
  {
    msg_.version = std::move(arg);
    return Init_UwbState_channel(msg_);
  }

private:
  ::go2_interfaces::msg::UwbState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::go2_interfaces::msg::UwbState>()
{
  return go2_interfaces::msg::builder::Init_UwbState_version();
}

}  // namespace go2_interfaces

#endif  // GO2_INTERFACES__MSG__DETAIL__UWB_STATE__BUILDER_HPP_
