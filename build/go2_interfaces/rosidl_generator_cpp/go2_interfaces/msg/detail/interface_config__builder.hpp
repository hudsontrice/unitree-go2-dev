// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from go2_interfaces:msg/InterfaceConfig.idl
// generated code does not contain a copyright notice

#ifndef GO2_INTERFACES__MSG__DETAIL__INTERFACE_CONFIG__BUILDER_HPP_
#define GO2_INTERFACES__MSG__DETAIL__INTERFACE_CONFIG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "go2_interfaces/msg/detail/interface_config__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace go2_interfaces
{

namespace msg
{

namespace builder
{

class Init_InterfaceConfig_reserve
{
public:
  explicit Init_InterfaceConfig_reserve(::go2_interfaces::msg::InterfaceConfig & msg)
  : msg_(msg)
  {}
  ::go2_interfaces::msg::InterfaceConfig reserve(::go2_interfaces::msg::InterfaceConfig::_reserve_type arg)
  {
    msg_.reserve = std::move(arg);
    return std::move(msg_);
  }

private:
  ::go2_interfaces::msg::InterfaceConfig msg_;
};

class Init_InterfaceConfig_value
{
public:
  explicit Init_InterfaceConfig_value(::go2_interfaces::msg::InterfaceConfig & msg)
  : msg_(msg)
  {}
  Init_InterfaceConfig_reserve value(::go2_interfaces::msg::InterfaceConfig::_value_type arg)
  {
    msg_.value = std::move(arg);
    return Init_InterfaceConfig_reserve(msg_);
  }

private:
  ::go2_interfaces::msg::InterfaceConfig msg_;
};

class Init_InterfaceConfig_mode
{
public:
  Init_InterfaceConfig_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_InterfaceConfig_value mode(::go2_interfaces::msg::InterfaceConfig::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_InterfaceConfig_value(msg_);
  }

private:
  ::go2_interfaces::msg::InterfaceConfig msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::go2_interfaces::msg::InterfaceConfig>()
{
  return go2_interfaces::msg::builder::Init_InterfaceConfig_mode();
}

}  // namespace go2_interfaces

#endif  // GO2_INTERFACES__MSG__DETAIL__INTERFACE_CONFIG__BUILDER_HPP_
