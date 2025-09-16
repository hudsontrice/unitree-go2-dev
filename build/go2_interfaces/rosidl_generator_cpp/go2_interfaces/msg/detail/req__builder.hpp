// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from go2_interfaces:msg/Req.idl
// generated code does not contain a copyright notice

#ifndef GO2_INTERFACES__MSG__DETAIL__REQ__BUILDER_HPP_
#define GO2_INTERFACES__MSG__DETAIL__REQ__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "go2_interfaces/msg/detail/req__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace go2_interfaces
{

namespace msg
{

namespace builder
{

class Init_Req_body
{
public:
  explicit Init_Req_body(::go2_interfaces::msg::Req & msg)
  : msg_(msg)
  {}
  ::go2_interfaces::msg::Req body(::go2_interfaces::msg::Req::_body_type arg)
  {
    msg_.body = std::move(arg);
    return std::move(msg_);
  }

private:
  ::go2_interfaces::msg::Req msg_;
};

class Init_Req_uuid
{
public:
  Init_Req_uuid()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Req_body uuid(::go2_interfaces::msg::Req::_uuid_type arg)
  {
    msg_.uuid = std::move(arg);
    return Init_Req_body(msg_);
  }

private:
  ::go2_interfaces::msg::Req msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::go2_interfaces::msg::Req>()
{
  return go2_interfaces::msg::builder::Init_Req_uuid();
}

}  // namespace go2_interfaces

#endif  // GO2_INTERFACES__MSG__DETAIL__REQ__BUILDER_HPP_
