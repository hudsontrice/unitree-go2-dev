// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from go2_interfaces:msg/TimeSpec.idl
// generated code does not contain a copyright notice

#ifndef GO2_INTERFACES__MSG__DETAIL__TIME_SPEC__BUILDER_HPP_
#define GO2_INTERFACES__MSG__DETAIL__TIME_SPEC__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "go2_interfaces/msg/detail/time_spec__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace go2_interfaces
{

namespace msg
{

namespace builder
{

class Init_TimeSpec_nanosec
{
public:
  explicit Init_TimeSpec_nanosec(::go2_interfaces::msg::TimeSpec & msg)
  : msg_(msg)
  {}
  ::go2_interfaces::msg::TimeSpec nanosec(::go2_interfaces::msg::TimeSpec::_nanosec_type arg)
  {
    msg_.nanosec = std::move(arg);
    return std::move(msg_);
  }

private:
  ::go2_interfaces::msg::TimeSpec msg_;
};

class Init_TimeSpec_sec
{
public:
  Init_TimeSpec_sec()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TimeSpec_nanosec sec(::go2_interfaces::msg::TimeSpec::_sec_type arg)
  {
    msg_.sec = std::move(arg);
    return Init_TimeSpec_nanosec(msg_);
  }

private:
  ::go2_interfaces::msg::TimeSpec msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::go2_interfaces::msg::TimeSpec>()
{
  return go2_interfaces::msg::builder::Init_TimeSpec_sec();
}

}  // namespace go2_interfaces

#endif  // GO2_INTERFACES__MSG__DETAIL__TIME_SPEC__BUILDER_HPP_
