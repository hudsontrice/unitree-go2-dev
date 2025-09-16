// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from go2_interfaces:msg/Res.idl
// generated code does not contain a copyright notice

#ifndef GO2_INTERFACES__MSG__DETAIL__RES__BUILDER_HPP_
#define GO2_INTERFACES__MSG__DETAIL__RES__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "go2_interfaces/msg/detail/res__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace go2_interfaces
{

namespace msg
{

namespace builder
{

class Init_Res_body
{
public:
  explicit Init_Res_body(::go2_interfaces::msg::Res & msg)
  : msg_(msg)
  {}
  ::go2_interfaces::msg::Res body(::go2_interfaces::msg::Res::_body_type arg)
  {
    msg_.body = std::move(arg);
    return std::move(msg_);
  }

private:
  ::go2_interfaces::msg::Res msg_;
};

class Init_Res_data
{
public:
  explicit Init_Res_data(::go2_interfaces::msg::Res & msg)
  : msg_(msg)
  {}
  Init_Res_body data(::go2_interfaces::msg::Res::_data_type arg)
  {
    msg_.data = std::move(arg);
    return Init_Res_body(msg_);
  }

private:
  ::go2_interfaces::msg::Res msg_;
};

class Init_Res_uuid
{
public:
  Init_Res_uuid()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Res_data uuid(::go2_interfaces::msg::Res::_uuid_type arg)
  {
    msg_.uuid = std::move(arg);
    return Init_Res_data(msg_);
  }

private:
  ::go2_interfaces::msg::Res msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::go2_interfaces::msg::Res>()
{
  return go2_interfaces::msg::builder::Init_Res_uuid();
}

}  // namespace go2_interfaces

#endif  // GO2_INTERFACES__MSG__DETAIL__RES__BUILDER_HPP_
