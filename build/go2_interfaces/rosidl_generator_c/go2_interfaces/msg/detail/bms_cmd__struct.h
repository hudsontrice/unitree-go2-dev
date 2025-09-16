// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from go2_interfaces:msg/BmsCmd.idl
// generated code does not contain a copyright notice

#ifndef GO2_INTERFACES__MSG__DETAIL__BMS_CMD__STRUCT_H_
#define GO2_INTERFACES__MSG__DETAIL__BMS_CMD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/BmsCmd in the package go2_interfaces.
typedef struct go2_interfaces__msg__BmsCmd
{
  uint8_t off;
  uint8_t reserve[3];
} go2_interfaces__msg__BmsCmd;

// Struct for a sequence of go2_interfaces__msg__BmsCmd.
typedef struct go2_interfaces__msg__BmsCmd__Sequence
{
  go2_interfaces__msg__BmsCmd * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} go2_interfaces__msg__BmsCmd__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GO2_INTERFACES__MSG__DETAIL__BMS_CMD__STRUCT_H_
