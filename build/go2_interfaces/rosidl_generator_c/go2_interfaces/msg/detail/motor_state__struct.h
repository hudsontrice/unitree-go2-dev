// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from go2_interfaces:msg/MotorState.idl
// generated code does not contain a copyright notice

#ifndef GO2_INTERFACES__MSG__DETAIL__MOTOR_STATE__STRUCT_H_
#define GO2_INTERFACES__MSG__DETAIL__MOTOR_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/MotorState in the package go2_interfaces.
typedef struct go2_interfaces__msg__MotorState
{
  uint8_t mode;
  float q;
  float dq;
  float ddq;
  float tau_est;
  float q_raw;
  float dq_raw;
  float ddq_raw;
  int8_t temperature;
  uint32_t lost;
  uint32_t reserve[2];
} go2_interfaces__msg__MotorState;

// Struct for a sequence of go2_interfaces__msg__MotorState.
typedef struct go2_interfaces__msg__MotorState__Sequence
{
  go2_interfaces__msg__MotorState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} go2_interfaces__msg__MotorState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GO2_INTERFACES__MSG__DETAIL__MOTOR_STATE__STRUCT_H_
