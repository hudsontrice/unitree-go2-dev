// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from go2_interfaces:msg/UwbState.idl
// generated code does not contain a copyright notice

#ifndef GO2_INTERFACES__MSG__DETAIL__UWB_STATE__STRUCT_H_
#define GO2_INTERFACES__MSG__DETAIL__UWB_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/UwbState in the package go2_interfaces.
typedef struct go2_interfaces__msg__UwbState
{
  uint8_t version[2];
  uint8_t channel;
  uint8_t joy_mode;
  float orientation_est;
  float pitch_est;
  float distance_est;
  float yaw_est;
  float tag_roll;
  float tag_pitch;
  float tag_yaw;
  float base_roll;
  float base_pitch;
  float base_yaw;
  float joystick[2];
  uint8_t error_state;
  uint8_t buttons;
  uint8_t enabled_from_app;
} go2_interfaces__msg__UwbState;

// Struct for a sequence of go2_interfaces__msg__UwbState.
typedef struct go2_interfaces__msg__UwbState__Sequence
{
  go2_interfaces__msg__UwbState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} go2_interfaces__msg__UwbState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GO2_INTERFACES__MSG__DETAIL__UWB_STATE__STRUCT_H_
