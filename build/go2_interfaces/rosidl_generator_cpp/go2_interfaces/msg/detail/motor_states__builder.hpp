// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from go2_interfaces:msg/MotorStates.idl
// generated code does not contain a copyright notice

#ifndef GO2_INTERFACES__MSG__DETAIL__MOTOR_STATES__BUILDER_HPP_
#define GO2_INTERFACES__MSG__DETAIL__MOTOR_STATES__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "go2_interfaces/msg/detail/motor_states__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace go2_interfaces
{

namespace msg
{

namespace builder
{

class Init_MotorStates_states
{
public:
  Init_MotorStates_states()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::go2_interfaces::msg::MotorStates states(::go2_interfaces::msg::MotorStates::_states_type arg)
  {
    msg_.states = std::move(arg);
    return std::move(msg_);
  }

private:
  ::go2_interfaces::msg::MotorStates msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::go2_interfaces::msg::MotorStates>()
{
  return go2_interfaces::msg::builder::Init_MotorStates_states();
}

}  // namespace go2_interfaces

#endif  // GO2_INTERFACES__MSG__DETAIL__MOTOR_STATES__BUILDER_HPP_
