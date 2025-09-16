// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from go2_interfaces:msg/SportModeCmd.idl
// generated code does not contain a copyright notice

#ifndef GO2_INTERFACES__MSG__DETAIL__SPORT_MODE_CMD__STRUCT_H_
#define GO2_INTERFACES__MSG__DETAIL__SPORT_MODE_CMD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'bms_cmd'
#include "go2_interfaces/msg/detail/bms_cmd__struct.h"
// Member 'path_point'
#include "go2_interfaces/msg/detail/path_point__struct.h"

/// Struct defined in msg/SportModeCmd in the package go2_interfaces.
typedef struct go2_interfaces__msg__SportModeCmd
{
  uint8_t mode;
  uint8_t gait_type;
  uint8_t speed_level;
  float foot_raise_height;
  float body_height;
  float position[2];
  float euler[3];
  float velocity[2];
  float yaw_speed;
  go2_interfaces__msg__BmsCmd bms_cmd;
  go2_interfaces__msg__PathPoint path_point[30];
} go2_interfaces__msg__SportModeCmd;

// Struct for a sequence of go2_interfaces__msg__SportModeCmd.
typedef struct go2_interfaces__msg__SportModeCmd__Sequence
{
  go2_interfaces__msg__SportModeCmd * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} go2_interfaces__msg__SportModeCmd__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GO2_INTERFACES__MSG__DETAIL__SPORT_MODE_CMD__STRUCT_H_
