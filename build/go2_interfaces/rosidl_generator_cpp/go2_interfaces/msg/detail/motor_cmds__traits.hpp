// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from go2_interfaces:msg/MotorCmds.idl
// generated code does not contain a copyright notice

#ifndef GO2_INTERFACES__MSG__DETAIL__MOTOR_CMDS__TRAITS_HPP_
#define GO2_INTERFACES__MSG__DETAIL__MOTOR_CMDS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "go2_interfaces/msg/detail/motor_cmds__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'cmds'
#include "go2_interfaces/msg/detail/motor_cmd__traits.hpp"

namespace go2_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const MotorCmds & msg,
  std::ostream & out)
{
  out << "{";
  // member: cmds
  {
    if (msg.cmds.size() == 0) {
      out << "cmds: []";
    } else {
      out << "cmds: [";
      size_t pending_items = msg.cmds.size();
      for (auto item : msg.cmds) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MotorCmds & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: cmds
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.cmds.size() == 0) {
      out << "cmds: []\n";
    } else {
      out << "cmds:\n";
      for (auto item : msg.cmds) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MotorCmds & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace go2_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use go2_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const go2_interfaces::msg::MotorCmds & msg,
  std::ostream & out, size_t indentation = 0)
{
  go2_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use go2_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const go2_interfaces::msg::MotorCmds & msg)
{
  return go2_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<go2_interfaces::msg::MotorCmds>()
{
  return "go2_interfaces::msg::MotorCmds";
}

template<>
inline const char * name<go2_interfaces::msg::MotorCmds>()
{
  return "go2_interfaces/msg/MotorCmds";
}

template<>
struct has_fixed_size<go2_interfaces::msg::MotorCmds>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<go2_interfaces::msg::MotorCmds>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<go2_interfaces::msg::MotorCmds>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // GO2_INTERFACES__MSG__DETAIL__MOTOR_CMDS__TRAITS_HPP_
