// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from go2_interfaces:msg/MotorCmds.idl
// generated code does not contain a copyright notice

#ifndef GO2_INTERFACES__MSG__DETAIL__MOTOR_CMDS__STRUCT_HPP_
#define GO2_INTERFACES__MSG__DETAIL__MOTOR_CMDS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'cmds'
#include "go2_interfaces/msg/detail/motor_cmd__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__go2_interfaces__msg__MotorCmds __attribute__((deprecated))
#else
# define DEPRECATED__go2_interfaces__msg__MotorCmds __declspec(deprecated)
#endif

namespace go2_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MotorCmds_
{
  using Type = MotorCmds_<ContainerAllocator>;

  explicit MotorCmds_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit MotorCmds_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _cmds_type =
    std::vector<go2_interfaces::msg::MotorCmd_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<go2_interfaces::msg::MotorCmd_<ContainerAllocator>>>;
  _cmds_type cmds;

  // setters for named parameter idiom
  Type & set__cmds(
    const std::vector<go2_interfaces::msg::MotorCmd_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<go2_interfaces::msg::MotorCmd_<ContainerAllocator>>> & _arg)
  {
    this->cmds = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    go2_interfaces::msg::MotorCmds_<ContainerAllocator> *;
  using ConstRawPtr =
    const go2_interfaces::msg::MotorCmds_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<go2_interfaces::msg::MotorCmds_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<go2_interfaces::msg::MotorCmds_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      go2_interfaces::msg::MotorCmds_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<go2_interfaces::msg::MotorCmds_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      go2_interfaces::msg::MotorCmds_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<go2_interfaces::msg::MotorCmds_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<go2_interfaces::msg::MotorCmds_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<go2_interfaces::msg::MotorCmds_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__go2_interfaces__msg__MotorCmds
    std::shared_ptr<go2_interfaces::msg::MotorCmds_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__go2_interfaces__msg__MotorCmds
    std::shared_ptr<go2_interfaces::msg::MotorCmds_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MotorCmds_ & other) const
  {
    if (this->cmds != other.cmds) {
      return false;
    }
    return true;
  }
  bool operator!=(const MotorCmds_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MotorCmds_

// alias to use template instance with default allocator
using MotorCmds =
  go2_interfaces::msg::MotorCmds_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace go2_interfaces

#endif  // GO2_INTERFACES__MSG__DETAIL__MOTOR_CMDS__STRUCT_HPP_
