// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from go2_interfaces:msg/MotorStates.idl
// generated code does not contain a copyright notice

#ifndef GO2_INTERFACES__MSG__DETAIL__MOTOR_STATES__STRUCT_HPP_
#define GO2_INTERFACES__MSG__DETAIL__MOTOR_STATES__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'states'
#include "go2_interfaces/msg/detail/motor_state__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__go2_interfaces__msg__MotorStates __attribute__((deprecated))
#else
# define DEPRECATED__go2_interfaces__msg__MotorStates __declspec(deprecated)
#endif

namespace go2_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MotorStates_
{
  using Type = MotorStates_<ContainerAllocator>;

  explicit MotorStates_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit MotorStates_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _states_type =
    std::vector<go2_interfaces::msg::MotorState_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<go2_interfaces::msg::MotorState_<ContainerAllocator>>>;
  _states_type states;

  // setters for named parameter idiom
  Type & set__states(
    const std::vector<go2_interfaces::msg::MotorState_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<go2_interfaces::msg::MotorState_<ContainerAllocator>>> & _arg)
  {
    this->states = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    go2_interfaces::msg::MotorStates_<ContainerAllocator> *;
  using ConstRawPtr =
    const go2_interfaces::msg::MotorStates_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<go2_interfaces::msg::MotorStates_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<go2_interfaces::msg::MotorStates_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      go2_interfaces::msg::MotorStates_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<go2_interfaces::msg::MotorStates_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      go2_interfaces::msg::MotorStates_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<go2_interfaces::msg::MotorStates_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<go2_interfaces::msg::MotorStates_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<go2_interfaces::msg::MotorStates_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__go2_interfaces__msg__MotorStates
    std::shared_ptr<go2_interfaces::msg::MotorStates_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__go2_interfaces__msg__MotorStates
    std::shared_ptr<go2_interfaces::msg::MotorStates_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MotorStates_ & other) const
  {
    if (this->states != other.states) {
      return false;
    }
    return true;
  }
  bool operator!=(const MotorStates_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MotorStates_

// alias to use template instance with default allocator
using MotorStates =
  go2_interfaces::msg::MotorStates_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace go2_interfaces

#endif  // GO2_INTERFACES__MSG__DETAIL__MOTOR_STATES__STRUCT_HPP_
