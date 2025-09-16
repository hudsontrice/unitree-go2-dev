// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from go2_interfaces:msg/MotorStates.idl
// generated code does not contain a copyright notice

#ifndef GO2_INTERFACES__MSG__DETAIL__MOTOR_STATES__STRUCT_H_
#define GO2_INTERFACES__MSG__DETAIL__MOTOR_STATES__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'states'
#include "go2_interfaces/msg/detail/motor_state__struct.h"

/// Struct defined in msg/MotorStates in the package go2_interfaces.
typedef struct go2_interfaces__msg__MotorStates
{
  go2_interfaces__msg__MotorState__Sequence states;
} go2_interfaces__msg__MotorStates;

// Struct for a sequence of go2_interfaces__msg__MotorStates.
typedef struct go2_interfaces__msg__MotorStates__Sequence
{
  go2_interfaces__msg__MotorStates * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} go2_interfaces__msg__MotorStates__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GO2_INTERFACES__MSG__DETAIL__MOTOR_STATES__STRUCT_H_
