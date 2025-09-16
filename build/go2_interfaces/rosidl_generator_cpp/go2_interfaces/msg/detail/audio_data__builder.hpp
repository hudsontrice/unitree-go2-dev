// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from go2_interfaces:msg/AudioData.idl
// generated code does not contain a copyright notice

#ifndef GO2_INTERFACES__MSG__DETAIL__AUDIO_DATA__BUILDER_HPP_
#define GO2_INTERFACES__MSG__DETAIL__AUDIO_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "go2_interfaces/msg/detail/audio_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace go2_interfaces
{

namespace msg
{

namespace builder
{

class Init_AudioData_data
{
public:
  explicit Init_AudioData_data(::go2_interfaces::msg::AudioData & msg)
  : msg_(msg)
  {}
  ::go2_interfaces::msg::AudioData data(::go2_interfaces::msg::AudioData::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::go2_interfaces::msg::AudioData msg_;
};

class Init_AudioData_time_frame
{
public:
  Init_AudioData_time_frame()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AudioData_data time_frame(::go2_interfaces::msg::AudioData::_time_frame_type arg)
  {
    msg_.time_frame = std::move(arg);
    return Init_AudioData_data(msg_);
  }

private:
  ::go2_interfaces::msg::AudioData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::go2_interfaces::msg::AudioData>()
{
  return go2_interfaces::msg::builder::Init_AudioData_time_frame();
}

}  // namespace go2_interfaces

#endif  // GO2_INTERFACES__MSG__DETAIL__AUDIO_DATA__BUILDER_HPP_
