// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from go2_interfaces:msg/BmsState.idl
// generated code does not contain a copyright notice

#ifndef GO2_INTERFACES__MSG__DETAIL__BMS_STATE__BUILDER_HPP_
#define GO2_INTERFACES__MSG__DETAIL__BMS_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "go2_interfaces/msg/detail/bms_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace go2_interfaces
{

namespace msg
{

namespace builder
{

class Init_BmsState_cell_vol
{
public:
  explicit Init_BmsState_cell_vol(::go2_interfaces::msg::BmsState & msg)
  : msg_(msg)
  {}
  ::go2_interfaces::msg::BmsState cell_vol(::go2_interfaces::msg::BmsState::_cell_vol_type arg)
  {
    msg_.cell_vol = std::move(arg);
    return std::move(msg_);
  }

private:
  ::go2_interfaces::msg::BmsState msg_;
};

class Init_BmsState_mcu_ntc
{
public:
  explicit Init_BmsState_mcu_ntc(::go2_interfaces::msg::BmsState & msg)
  : msg_(msg)
  {}
  Init_BmsState_cell_vol mcu_ntc(::go2_interfaces::msg::BmsState::_mcu_ntc_type arg)
  {
    msg_.mcu_ntc = std::move(arg);
    return Init_BmsState_cell_vol(msg_);
  }

private:
  ::go2_interfaces::msg::BmsState msg_;
};

class Init_BmsState_bq_ntc
{
public:
  explicit Init_BmsState_bq_ntc(::go2_interfaces::msg::BmsState & msg)
  : msg_(msg)
  {}
  Init_BmsState_mcu_ntc bq_ntc(::go2_interfaces::msg::BmsState::_bq_ntc_type arg)
  {
    msg_.bq_ntc = std::move(arg);
    return Init_BmsState_mcu_ntc(msg_);
  }

private:
  ::go2_interfaces::msg::BmsState msg_;
};

class Init_BmsState_cycle
{
public:
  explicit Init_BmsState_cycle(::go2_interfaces::msg::BmsState & msg)
  : msg_(msg)
  {}
  Init_BmsState_bq_ntc cycle(::go2_interfaces::msg::BmsState::_cycle_type arg)
  {
    msg_.cycle = std::move(arg);
    return Init_BmsState_bq_ntc(msg_);
  }

private:
  ::go2_interfaces::msg::BmsState msg_;
};

class Init_BmsState_current
{
public:
  explicit Init_BmsState_current(::go2_interfaces::msg::BmsState & msg)
  : msg_(msg)
  {}
  Init_BmsState_cycle current(::go2_interfaces::msg::BmsState::_current_type arg)
  {
    msg_.current = std::move(arg);
    return Init_BmsState_cycle(msg_);
  }

private:
  ::go2_interfaces::msg::BmsState msg_;
};

class Init_BmsState_soc
{
public:
  explicit Init_BmsState_soc(::go2_interfaces::msg::BmsState & msg)
  : msg_(msg)
  {}
  Init_BmsState_current soc(::go2_interfaces::msg::BmsState::_soc_type arg)
  {
    msg_.soc = std::move(arg);
    return Init_BmsState_current(msg_);
  }

private:
  ::go2_interfaces::msg::BmsState msg_;
};

class Init_BmsState_status
{
public:
  explicit Init_BmsState_status(::go2_interfaces::msg::BmsState & msg)
  : msg_(msg)
  {}
  Init_BmsState_soc status(::go2_interfaces::msg::BmsState::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_BmsState_soc(msg_);
  }

private:
  ::go2_interfaces::msg::BmsState msg_;
};

class Init_BmsState_version_low
{
public:
  explicit Init_BmsState_version_low(::go2_interfaces::msg::BmsState & msg)
  : msg_(msg)
  {}
  Init_BmsState_status version_low(::go2_interfaces::msg::BmsState::_version_low_type arg)
  {
    msg_.version_low = std::move(arg);
    return Init_BmsState_status(msg_);
  }

private:
  ::go2_interfaces::msg::BmsState msg_;
};

class Init_BmsState_version_high
{
public:
  Init_BmsState_version_high()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BmsState_version_low version_high(::go2_interfaces::msg::BmsState::_version_high_type arg)
  {
    msg_.version_high = std::move(arg);
    return Init_BmsState_version_low(msg_);
  }

private:
  ::go2_interfaces::msg::BmsState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::go2_interfaces::msg::BmsState>()
{
  return go2_interfaces::msg::builder::Init_BmsState_version_high();
}

}  // namespace go2_interfaces

#endif  // GO2_INTERFACES__MSG__DETAIL__BMS_STATE__BUILDER_HPP_
