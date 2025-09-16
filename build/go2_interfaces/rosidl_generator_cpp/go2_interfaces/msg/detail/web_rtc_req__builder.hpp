// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from go2_interfaces:msg/WebRtcReq.idl
// generated code does not contain a copyright notice

#ifndef GO2_INTERFACES__MSG__DETAIL__WEB_RTC_REQ__BUILDER_HPP_
#define GO2_INTERFACES__MSG__DETAIL__WEB_RTC_REQ__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "go2_interfaces/msg/detail/web_rtc_req__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace go2_interfaces
{

namespace msg
{

namespace builder
{

class Init_WebRtcReq_priority
{
public:
  explicit Init_WebRtcReq_priority(::go2_interfaces::msg::WebRtcReq & msg)
  : msg_(msg)
  {}
  ::go2_interfaces::msg::WebRtcReq priority(::go2_interfaces::msg::WebRtcReq::_priority_type arg)
  {
    msg_.priority = std::move(arg);
    return std::move(msg_);
  }

private:
  ::go2_interfaces::msg::WebRtcReq msg_;
};

class Init_WebRtcReq_parameter
{
public:
  explicit Init_WebRtcReq_parameter(::go2_interfaces::msg::WebRtcReq & msg)
  : msg_(msg)
  {}
  Init_WebRtcReq_priority parameter(::go2_interfaces::msg::WebRtcReq::_parameter_type arg)
  {
    msg_.parameter = std::move(arg);
    return Init_WebRtcReq_priority(msg_);
  }

private:
  ::go2_interfaces::msg::WebRtcReq msg_;
};

class Init_WebRtcReq_api_id
{
public:
  explicit Init_WebRtcReq_api_id(::go2_interfaces::msg::WebRtcReq & msg)
  : msg_(msg)
  {}
  Init_WebRtcReq_parameter api_id(::go2_interfaces::msg::WebRtcReq::_api_id_type arg)
  {
    msg_.api_id = std::move(arg);
    return Init_WebRtcReq_parameter(msg_);
  }

private:
  ::go2_interfaces::msg::WebRtcReq msg_;
};

class Init_WebRtcReq_topic
{
public:
  explicit Init_WebRtcReq_topic(::go2_interfaces::msg::WebRtcReq & msg)
  : msg_(msg)
  {}
  Init_WebRtcReq_api_id topic(::go2_interfaces::msg::WebRtcReq::_topic_type arg)
  {
    msg_.topic = std::move(arg);
    return Init_WebRtcReq_api_id(msg_);
  }

private:
  ::go2_interfaces::msg::WebRtcReq msg_;
};

class Init_WebRtcReq_id
{
public:
  Init_WebRtcReq_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_WebRtcReq_topic id(::go2_interfaces::msg::WebRtcReq::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_WebRtcReq_topic(msg_);
  }

private:
  ::go2_interfaces::msg::WebRtcReq msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::go2_interfaces::msg::WebRtcReq>()
{
  return go2_interfaces::msg::builder::Init_WebRtcReq_id();
}

}  // namespace go2_interfaces

#endif  // GO2_INTERFACES__MSG__DETAIL__WEB_RTC_REQ__BUILDER_HPP_
