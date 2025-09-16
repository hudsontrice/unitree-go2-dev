// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from go2_interfaces:msg/SportModeState.idl
// generated code does not contain a copyright notice

#ifndef GO2_INTERFACES__MSG__DETAIL__SPORT_MODE_STATE__STRUCT_H_
#define GO2_INTERFACES__MSG__DETAIL__SPORT_MODE_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "go2_interfaces/msg/detail/time_spec__struct.h"
// Member 'imu_state'
#include "go2_interfaces/msg/detail/imu__struct.h"

/// Struct defined in msg/SportModeState in the package go2_interfaces.
typedef struct go2_interfaces__msg__SportModeState
{
  go2_interfaces__msg__TimeSpec stamp;
  uint32_t error_code;
  go2_interfaces__msg__IMU imu_state;
  uint8_t mode;
  float progress;
  uint8_t gait_type;
  float foot_raise_height;
  float position[3];
  float body_height;
  float velocity[3];
  float yaw_speed;
  float range_obstacle[4];
  int16_t foot_force[4];
  float foot_position_body[12];
  float foot_speed_body[12];
} go2_interfaces__msg__SportModeState;

// Struct for a sequence of go2_interfaces__msg__SportModeState.
typedef struct go2_interfaces__msg__SportModeState__Sequence
{
  go2_interfaces__msg__SportModeState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} go2_interfaces__msg__SportModeState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GO2_INTERFACES__MSG__DETAIL__SPORT_MODE_STATE__STRUCT_H_
