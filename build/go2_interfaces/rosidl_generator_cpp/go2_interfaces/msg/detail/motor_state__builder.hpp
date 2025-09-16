// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from go2_interfaces:msg/MotorState.idl
// generated code does not contain a copyright notice

#ifndef GO2_INTERFACES__MSG__DETAIL__MOTOR_STATE__BUILDER_HPP_
#define GO2_INTERFACES__MSG__DETAIL__MOTOR_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "go2_interfaces/msg/detail/motor_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace go2_interfaces
{

namespace msg
{

namespace builder
{

class Init_MotorState_reserve
{
public:
  explicit Init_MotorState_reserve(::go2_interfaces::msg::MotorState & msg)
  : msg_(msg)
  {}
  ::go2_interfaces::msg::MotorState reserve(::go2_interfaces::msg::MotorState::_reserve_type arg)
  {
    msg_.reserve = std::move(arg);
    return std::move(msg_);
  }

private:
  ::go2_interfaces::msg::MotorState msg_;
};

class Init_MotorState_lost
{
public:
  explicit Init_MotorState_lost(::go2_interfaces::msg::MotorState & msg)
  : msg_(msg)
  {}
  Init_MotorState_reserve lost(::go2_interfaces::msg::MotorState::_lost_type arg)
  {
    msg_.lost = std::move(arg);
    return Init_MotorState_reserve(msg_);
  }

private:
  ::go2_interfaces::msg::MotorState msg_;
};

class Init_MotorState_temperature
{
public:
  explicit Init_MotorState_temperature(::go2_interfaces::msg::MotorState & msg)
  : msg_(msg)
  {}
  Init_MotorState_lost temperature(::go2_interfaces::msg::MotorState::_temperature_type arg)
  {
    msg_.temperature = std::move(arg);
    return Init_MotorState_lost(msg_);
  }

private:
  ::go2_interfaces::msg::MotorState msg_;
};

class Init_MotorState_ddq_raw
{
public:
  explicit Init_MotorState_ddq_raw(::go2_interfaces::msg::MotorState & msg)
  : msg_(msg)
  {}
  Init_MotorState_temperature ddq_raw(::go2_interfaces::msg::MotorState::_ddq_raw_type arg)
  {
    msg_.ddq_raw = std::move(arg);
    return Init_MotorState_temperature(msg_);
  }

private:
  ::go2_interfaces::msg::MotorState msg_;
};

class Init_MotorState_dq_raw
{
public:
  explicit Init_MotorState_dq_raw(::go2_interfaces::msg::MotorState & msg)
  : msg_(msg)
  {}
  Init_MotorState_ddq_raw dq_raw(::go2_interfaces::msg::MotorState::_dq_raw_type arg)
  {
    msg_.dq_raw = std::move(arg);
    return Init_MotorState_ddq_raw(msg_);
  }

private:
  ::go2_interfaces::msg::MotorState msg_;
};

class Init_MotorState_q_raw
{
public:
  explicit Init_MotorState_q_raw(::go2_interfaces::msg::MotorState & msg)
  : msg_(msg)
  {}
  Init_MotorState_dq_raw q_raw(::go2_interfaces::msg::MotorState::_q_raw_type arg)
  {
    msg_.q_raw = std::move(arg);
    return Init_MotorState_dq_raw(msg_);
  }

private:
  ::go2_interfaces::msg::MotorState msg_;
};

class Init_MotorState_tau_est
{
public:
  explicit Init_MotorState_tau_est(::go2_interfaces::msg::MotorState & msg)
  : msg_(msg)
  {}
  Init_MotorState_q_raw tau_est(::go2_interfaces::msg::MotorState::_tau_est_type arg)
  {
    msg_.tau_est = std::move(arg);
    return Init_MotorState_q_raw(msg_);
  }

private:
  ::go2_interfaces::msg::MotorState msg_;
};

class Init_MotorState_ddq
{
public:
  explicit Init_MotorState_ddq(::go2_interfaces::msg::MotorState & msg)
  : msg_(msg)
  {}
  Init_MotorState_tau_est ddq(::go2_interfaces::msg::MotorState::_ddq_type arg)
  {
    msg_.ddq = std::move(arg);
    return Init_MotorState_tau_est(msg_);
  }

private:
  ::go2_interfaces::msg::MotorState msg_;
};

class Init_MotorState_dq
{
public:
  explicit Init_MotorState_dq(::go2_interfaces::msg::MotorState & msg)
  : msg_(msg)
  {}
  Init_MotorState_ddq dq(::go2_interfaces::msg::MotorState::_dq_type arg)
  {
    msg_.dq = std::move(arg);
    return Init_MotorState_ddq(msg_);
  }

private:
  ::go2_interfaces::msg::MotorState msg_;
};

class Init_MotorState_q
{
public:
  explicit Init_MotorState_q(::go2_interfaces::msg::MotorState & msg)
  : msg_(msg)
  {}
  Init_MotorState_dq q(::go2_interfaces::msg::MotorState::_q_type arg)
  {
    msg_.q = std::move(arg);
    return Init_MotorState_dq(msg_);
  }

private:
  ::go2_interfaces::msg::MotorState msg_;
};

class Init_MotorState_mode
{
public:
  Init_MotorState_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotorState_q mode(::go2_interfaces::msg::MotorState::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_MotorState_q(msg_);
  }

private:
  ::go2_interfaces::msg::MotorState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::go2_interfaces::msg::MotorState>()
{
  return go2_interfaces::msg::builder::Init_MotorState_mode();
}

}  // namespace go2_interfaces

#endif  // GO2_INTERFACES__MSG__DETAIL__MOTOR_STATE__BUILDER_HPP_
