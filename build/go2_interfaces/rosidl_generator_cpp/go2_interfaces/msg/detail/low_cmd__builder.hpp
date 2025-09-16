// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from go2_interfaces:msg/LowCmd.idl
// generated code does not contain a copyright notice

#ifndef GO2_INTERFACES__MSG__DETAIL__LOW_CMD__BUILDER_HPP_
#define GO2_INTERFACES__MSG__DETAIL__LOW_CMD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "go2_interfaces/msg/detail/low_cmd__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace go2_interfaces
{

namespace msg
{

namespace builder
{

class Init_LowCmd_crc
{
public:
  explicit Init_LowCmd_crc(::go2_interfaces::msg::LowCmd & msg)
  : msg_(msg)
  {}
  ::go2_interfaces::msg::LowCmd crc(::go2_interfaces::msg::LowCmd::_crc_type arg)
  {
    msg_.crc = std::move(arg);
    return std::move(msg_);
  }

private:
  ::go2_interfaces::msg::LowCmd msg_;
};

class Init_LowCmd_reserve
{
public:
  explicit Init_LowCmd_reserve(::go2_interfaces::msg::LowCmd & msg)
  : msg_(msg)
  {}
  Init_LowCmd_crc reserve(::go2_interfaces::msg::LowCmd::_reserve_type arg)
  {
    msg_.reserve = std::move(arg);
    return Init_LowCmd_crc(msg_);
  }

private:
  ::go2_interfaces::msg::LowCmd msg_;
};

class Init_LowCmd_gpio
{
public:
  explicit Init_LowCmd_gpio(::go2_interfaces::msg::LowCmd & msg)
  : msg_(msg)
  {}
  Init_LowCmd_reserve gpio(::go2_interfaces::msg::LowCmd::_gpio_type arg)
  {
    msg_.gpio = std::move(arg);
    return Init_LowCmd_reserve(msg_);
  }

private:
  ::go2_interfaces::msg::LowCmd msg_;
};

class Init_LowCmd_fan
{
public:
  explicit Init_LowCmd_fan(::go2_interfaces::msg::LowCmd & msg)
  : msg_(msg)
  {}
  Init_LowCmd_gpio fan(::go2_interfaces::msg::LowCmd::_fan_type arg)
  {
    msg_.fan = std::move(arg);
    return Init_LowCmd_gpio(msg_);
  }

private:
  ::go2_interfaces::msg::LowCmd msg_;
};

class Init_LowCmd_led
{
public:
  explicit Init_LowCmd_led(::go2_interfaces::msg::LowCmd & msg)
  : msg_(msg)
  {}
  Init_LowCmd_fan led(::go2_interfaces::msg::LowCmd::_led_type arg)
  {
    msg_.led = std::move(arg);
    return Init_LowCmd_fan(msg_);
  }

private:
  ::go2_interfaces::msg::LowCmd msg_;
};

class Init_LowCmd_wireless_remote
{
public:
  explicit Init_LowCmd_wireless_remote(::go2_interfaces::msg::LowCmd & msg)
  : msg_(msg)
  {}
  Init_LowCmd_led wireless_remote(::go2_interfaces::msg::LowCmd::_wireless_remote_type arg)
  {
    msg_.wireless_remote = std::move(arg);
    return Init_LowCmd_led(msg_);
  }

private:
  ::go2_interfaces::msg::LowCmd msg_;
};

class Init_LowCmd_bms_cmd
{
public:
  explicit Init_LowCmd_bms_cmd(::go2_interfaces::msg::LowCmd & msg)
  : msg_(msg)
  {}
  Init_LowCmd_wireless_remote bms_cmd(::go2_interfaces::msg::LowCmd::_bms_cmd_type arg)
  {
    msg_.bms_cmd = std::move(arg);
    return Init_LowCmd_wireless_remote(msg_);
  }

private:
  ::go2_interfaces::msg::LowCmd msg_;
};

class Init_LowCmd_motor_cmd
{
public:
  explicit Init_LowCmd_motor_cmd(::go2_interfaces::msg::LowCmd & msg)
  : msg_(msg)
  {}
  Init_LowCmd_bms_cmd motor_cmd(::go2_interfaces::msg::LowCmd::_motor_cmd_type arg)
  {
    msg_.motor_cmd = std::move(arg);
    return Init_LowCmd_bms_cmd(msg_);
  }

private:
  ::go2_interfaces::msg::LowCmd msg_;
};

class Init_LowCmd_bandwidth
{
public:
  explicit Init_LowCmd_bandwidth(::go2_interfaces::msg::LowCmd & msg)
  : msg_(msg)
  {}
  Init_LowCmd_motor_cmd bandwidth(::go2_interfaces::msg::LowCmd::_bandwidth_type arg)
  {
    msg_.bandwidth = std::move(arg);
    return Init_LowCmd_motor_cmd(msg_);
  }

private:
  ::go2_interfaces::msg::LowCmd msg_;
};

class Init_LowCmd_version
{
public:
  explicit Init_LowCmd_version(::go2_interfaces::msg::LowCmd & msg)
  : msg_(msg)
  {}
  Init_LowCmd_bandwidth version(::go2_interfaces::msg::LowCmd::_version_type arg)
  {
    msg_.version = std::move(arg);
    return Init_LowCmd_bandwidth(msg_);
  }

private:
  ::go2_interfaces::msg::LowCmd msg_;
};

class Init_LowCmd_sn
{
public:
  explicit Init_LowCmd_sn(::go2_interfaces::msg::LowCmd & msg)
  : msg_(msg)
  {}
  Init_LowCmd_version sn(::go2_interfaces::msg::LowCmd::_sn_type arg)
  {
    msg_.sn = std::move(arg);
    return Init_LowCmd_version(msg_);
  }

private:
  ::go2_interfaces::msg::LowCmd msg_;
};

class Init_LowCmd_frame_reserve
{
public:
  explicit Init_LowCmd_frame_reserve(::go2_interfaces::msg::LowCmd & msg)
  : msg_(msg)
  {}
  Init_LowCmd_sn frame_reserve(::go2_interfaces::msg::LowCmd::_frame_reserve_type arg)
  {
    msg_.frame_reserve = std::move(arg);
    return Init_LowCmd_sn(msg_);
  }

private:
  ::go2_interfaces::msg::LowCmd msg_;
};

class Init_LowCmd_level_flag
{
public:
  explicit Init_LowCmd_level_flag(::go2_interfaces::msg::LowCmd & msg)
  : msg_(msg)
  {}
  Init_LowCmd_frame_reserve level_flag(::go2_interfaces::msg::LowCmd::_level_flag_type arg)
  {
    msg_.level_flag = std::move(arg);
    return Init_LowCmd_frame_reserve(msg_);
  }

private:
  ::go2_interfaces::msg::LowCmd msg_;
};

class Init_LowCmd_head
{
public:
  Init_LowCmd_head()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LowCmd_level_flag head(::go2_interfaces::msg::LowCmd::_head_type arg)
  {
    msg_.head = std::move(arg);
    return Init_LowCmd_level_flag(msg_);
  }

private:
  ::go2_interfaces::msg::LowCmd msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::go2_interfaces::msg::LowCmd>()
{
  return go2_interfaces::msg::builder::Init_LowCmd_head();
}

}  // namespace go2_interfaces

#endif  // GO2_INTERFACES__MSG__DETAIL__LOW_CMD__BUILDER_HPP_
