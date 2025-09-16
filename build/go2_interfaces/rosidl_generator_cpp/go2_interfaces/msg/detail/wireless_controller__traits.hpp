// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from go2_interfaces:msg/WirelessController.idl
// generated code does not contain a copyright notice

#ifndef GO2_INTERFACES__MSG__DETAIL__WIRELESS_CONTROLLER__TRAITS_HPP_
#define GO2_INTERFACES__MSG__DETAIL__WIRELESS_CONTROLLER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "go2_interfaces/msg/detail/wireless_controller__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace go2_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const WirelessController & msg,
  std::ostream & out)
{
  out << "{";
  // member: lx
  {
    out << "lx: ";
    rosidl_generator_traits::value_to_yaml(msg.lx, out);
    out << ", ";
  }

  // member: ly
  {
    out << "ly: ";
    rosidl_generator_traits::value_to_yaml(msg.ly, out);
    out << ", ";
  }

  // member: rx
  {
    out << "rx: ";
    rosidl_generator_traits::value_to_yaml(msg.rx, out);
    out << ", ";
  }

  // member: ry
  {
    out << "ry: ";
    rosidl_generator_traits::value_to_yaml(msg.ry, out);
    out << ", ";
  }

  // member: keys
  {
    out << "keys: ";
    rosidl_generator_traits::value_to_yaml(msg.keys, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const WirelessController & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: lx
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lx: ";
    rosidl_generator_traits::value_to_yaml(msg.lx, out);
    out << "\n";
  }

  // member: ly
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ly: ";
    rosidl_generator_traits::value_to_yaml(msg.ly, out);
    out << "\n";
  }

  // member: rx
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rx: ";
    rosidl_generator_traits::value_to_yaml(msg.rx, out);
    out << "\n";
  }

  // member: ry
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ry: ";
    rosidl_generator_traits::value_to_yaml(msg.ry, out);
    out << "\n";
  }

  // member: keys
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "keys: ";
    rosidl_generator_traits::value_to_yaml(msg.keys, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const WirelessController & msg, bool use_flow_style = false)
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
  const go2_interfaces::msg::WirelessController & msg,
  std::ostream & out, size_t indentation = 0)
{
  go2_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use go2_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const go2_interfaces::msg::WirelessController & msg)
{
  return go2_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<go2_interfaces::msg::WirelessController>()
{
  return "go2_interfaces::msg::WirelessController";
}

template<>
inline const char * name<go2_interfaces::msg::WirelessController>()
{
  return "go2_interfaces/msg/WirelessController";
}

template<>
struct has_fixed_size<go2_interfaces::msg::WirelessController>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<go2_interfaces::msg::WirelessController>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<go2_interfaces::msg::WirelessController>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // GO2_INTERFACES__MSG__DETAIL__WIRELESS_CONTROLLER__TRAITS_HPP_
