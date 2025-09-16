// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from go2_interfaces:msg/UwbSwitch.idl
// generated code does not contain a copyright notice

#ifndef GO2_INTERFACES__MSG__DETAIL__UWB_SWITCH__BUILDER_HPP_
#define GO2_INTERFACES__MSG__DETAIL__UWB_SWITCH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "go2_interfaces/msg/detail/uwb_switch__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace go2_interfaces
{

namespace msg
{

namespace builder
{

class Init_UwbSwitch_enabled
{
public:
  Init_UwbSwitch_enabled()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::go2_interfaces::msg::UwbSwitch enabled(::go2_interfaces::msg::UwbSwitch::_enabled_type arg)
  {
    msg_.enabled = std::move(arg);
    return std::move(msg_);
  }

private:
  ::go2_interfaces::msg::UwbSwitch msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::go2_interfaces::msg::UwbSwitch>()
{
  return go2_interfaces::msg::builder::Init_UwbSwitch_enabled();
}

}  // namespace go2_interfaces

#endif  // GO2_INTERFACES__MSG__DETAIL__UWB_SWITCH__BUILDER_HPP_
