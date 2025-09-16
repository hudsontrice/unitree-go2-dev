// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from go2_interfaces:msg/BmsCmd.idl
// generated code does not contain a copyright notice

#ifndef GO2_INTERFACES__MSG__DETAIL__BMS_CMD__BUILDER_HPP_
#define GO2_INTERFACES__MSG__DETAIL__BMS_CMD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "go2_interfaces/msg/detail/bms_cmd__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace go2_interfaces
{

namespace msg
{

namespace builder
{

class Init_BmsCmd_reserve
{
public:
  explicit Init_BmsCmd_reserve(::go2_interfaces::msg::BmsCmd & msg)
  : msg_(msg)
  {}
  ::go2_interfaces::msg::BmsCmd reserve(::go2_interfaces::msg::BmsCmd::_reserve_type arg)
  {
    msg_.reserve = std::move(arg);
    return std::move(msg_);
  }

private:
  ::go2_interfaces::msg::BmsCmd msg_;
};

class Init_BmsCmd_off
{
public:
  Init_BmsCmd_off()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BmsCmd_reserve off(::go2_interfaces::msg::BmsCmd::_off_type arg)
  {
    msg_.off = std::move(arg);
    return Init_BmsCmd_reserve(msg_);
  }

private:
  ::go2_interfaces::msg::BmsCmd msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::go2_interfaces::msg::BmsCmd>()
{
  return go2_interfaces::msg::builder::Init_BmsCmd_off();
}

}  // namespace go2_interfaces

#endif  // GO2_INTERFACES__MSG__DETAIL__BMS_CMD__BUILDER_HPP_
