// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from go2_interfaces:msg/WirelessController.idl
// generated code does not contain a copyright notice

#ifndef GO2_INTERFACES__MSG__DETAIL__WIRELESS_CONTROLLER__BUILDER_HPP_
#define GO2_INTERFACES__MSG__DETAIL__WIRELESS_CONTROLLER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "go2_interfaces/msg/detail/wireless_controller__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace go2_interfaces
{

namespace msg
{

namespace builder
{

class Init_WirelessController_keys
{
public:
  explicit Init_WirelessController_keys(::go2_interfaces::msg::WirelessController & msg)
  : msg_(msg)
  {}
  ::go2_interfaces::msg::WirelessController keys(::go2_interfaces::msg::WirelessController::_keys_type arg)
  {
    msg_.keys = std::move(arg);
    return std::move(msg_);
  }

private:
  ::go2_interfaces::msg::WirelessController msg_;
};

class Init_WirelessController_ry
{
public:
  explicit Init_WirelessController_ry(::go2_interfaces::msg::WirelessController & msg)
  : msg_(msg)
  {}
  Init_WirelessController_keys ry(::go2_interfaces::msg::WirelessController::_ry_type arg)
  {
    msg_.ry = std::move(arg);
    return Init_WirelessController_keys(msg_);
  }

private:
  ::go2_interfaces::msg::WirelessController msg_;
};

class Init_WirelessController_rx
{
public:
  explicit Init_WirelessController_rx(::go2_interfaces::msg::WirelessController & msg)
  : msg_(msg)
  {}
  Init_WirelessController_ry rx(::go2_interfaces::msg::WirelessController::_rx_type arg)
  {
    msg_.rx = std::move(arg);
    return Init_WirelessController_ry(msg_);
  }

private:
  ::go2_interfaces::msg::WirelessController msg_;
};

class Init_WirelessController_ly
{
public:
  explicit Init_WirelessController_ly(::go2_interfaces::msg::WirelessController & msg)
  : msg_(msg)
  {}
  Init_WirelessController_rx ly(::go2_interfaces::msg::WirelessController::_ly_type arg)
  {
    msg_.ly = std::move(arg);
    return Init_WirelessController_rx(msg_);
  }

private:
  ::go2_interfaces::msg::WirelessController msg_;
};

class Init_WirelessController_lx
{
public:
  Init_WirelessController_lx()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_WirelessController_ly lx(::go2_interfaces::msg::WirelessController::_lx_type arg)
  {
    msg_.lx = std::move(arg);
    return Init_WirelessController_ly(msg_);
  }

private:
  ::go2_interfaces::msg::WirelessController msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::go2_interfaces::msg::WirelessController>()
{
  return go2_interfaces::msg::builder::Init_WirelessController_lx();
}

}  // namespace go2_interfaces

#endif  // GO2_INTERFACES__MSG__DETAIL__WIRELESS_CONTROLLER__BUILDER_HPP_
