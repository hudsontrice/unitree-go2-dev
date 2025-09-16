// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from go2_interfaces:msg/Error.idl
// generated code does not contain a copyright notice

#ifndef GO2_INTERFACES__MSG__DETAIL__ERROR__BUILDER_HPP_
#define GO2_INTERFACES__MSG__DETAIL__ERROR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "go2_interfaces/msg/detail/error__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace go2_interfaces
{

namespace msg
{

namespace builder
{

class Init_Error_state
{
public:
  explicit Init_Error_state(::go2_interfaces::msg::Error & msg)
  : msg_(msg)
  {}
  ::go2_interfaces::msg::Error state(::go2_interfaces::msg::Error::_state_type arg)
  {
    msg_.state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::go2_interfaces::msg::Error msg_;
};

class Init_Error_source
{
public:
  Init_Error_source()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Error_state source(::go2_interfaces::msg::Error::_source_type arg)
  {
    msg_.source = std::move(arg);
    return Init_Error_state(msg_);
  }

private:
  ::go2_interfaces::msg::Error msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::go2_interfaces::msg::Error>()
{
  return go2_interfaces::msg::builder::Init_Error_source();
}

}  // namespace go2_interfaces

#endif  // GO2_INTERFACES__MSG__DETAIL__ERROR__BUILDER_HPP_
