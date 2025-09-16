// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from go2_interfaces:msg/PathPoint.idl
// generated code does not contain a copyright notice

#ifndef GO2_INTERFACES__MSG__DETAIL__PATH_POINT__BUILDER_HPP_
#define GO2_INTERFACES__MSG__DETAIL__PATH_POINT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "go2_interfaces/msg/detail/path_point__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace go2_interfaces
{

namespace msg
{

namespace builder
{

class Init_PathPoint_vyaw
{
public:
  explicit Init_PathPoint_vyaw(::go2_interfaces::msg::PathPoint & msg)
  : msg_(msg)
  {}
  ::go2_interfaces::msg::PathPoint vyaw(::go2_interfaces::msg::PathPoint::_vyaw_type arg)
  {
    msg_.vyaw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::go2_interfaces::msg::PathPoint msg_;
};

class Init_PathPoint_vy
{
public:
  explicit Init_PathPoint_vy(::go2_interfaces::msg::PathPoint & msg)
  : msg_(msg)
  {}
  Init_PathPoint_vyaw vy(::go2_interfaces::msg::PathPoint::_vy_type arg)
  {
    msg_.vy = std::move(arg);
    return Init_PathPoint_vyaw(msg_);
  }

private:
  ::go2_interfaces::msg::PathPoint msg_;
};

class Init_PathPoint_vx
{
public:
  explicit Init_PathPoint_vx(::go2_interfaces::msg::PathPoint & msg)
  : msg_(msg)
  {}
  Init_PathPoint_vy vx(::go2_interfaces::msg::PathPoint::_vx_type arg)
  {
    msg_.vx = std::move(arg);
    return Init_PathPoint_vy(msg_);
  }

private:
  ::go2_interfaces::msg::PathPoint msg_;
};

class Init_PathPoint_yaw
{
public:
  explicit Init_PathPoint_yaw(::go2_interfaces::msg::PathPoint & msg)
  : msg_(msg)
  {}
  Init_PathPoint_vx yaw(::go2_interfaces::msg::PathPoint::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_PathPoint_vx(msg_);
  }

private:
  ::go2_interfaces::msg::PathPoint msg_;
};

class Init_PathPoint_y
{
public:
  explicit Init_PathPoint_y(::go2_interfaces::msg::PathPoint & msg)
  : msg_(msg)
  {}
  Init_PathPoint_yaw y(::go2_interfaces::msg::PathPoint::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_PathPoint_yaw(msg_);
  }

private:
  ::go2_interfaces::msg::PathPoint msg_;
};

class Init_PathPoint_x
{
public:
  explicit Init_PathPoint_x(::go2_interfaces::msg::PathPoint & msg)
  : msg_(msg)
  {}
  Init_PathPoint_y x(::go2_interfaces::msg::PathPoint::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_PathPoint_y(msg_);
  }

private:
  ::go2_interfaces::msg::PathPoint msg_;
};

class Init_PathPoint_t_from_start
{
public:
  Init_PathPoint_t_from_start()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PathPoint_x t_from_start(::go2_interfaces::msg::PathPoint::_t_from_start_type arg)
  {
    msg_.t_from_start = std::move(arg);
    return Init_PathPoint_x(msg_);
  }

private:
  ::go2_interfaces::msg::PathPoint msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::go2_interfaces::msg::PathPoint>()
{
  return go2_interfaces::msg::builder::Init_PathPoint_t_from_start();
}

}  // namespace go2_interfaces

#endif  // GO2_INTERFACES__MSG__DETAIL__PATH_POINT__BUILDER_HPP_
