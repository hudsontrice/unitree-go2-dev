// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from go2_interfaces:msg/PathPoint.idl
// generated code does not contain a copyright notice

#ifndef GO2_INTERFACES__MSG__DETAIL__PATH_POINT__STRUCT_H_
#define GO2_INTERFACES__MSG__DETAIL__PATH_POINT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/PathPoint in the package go2_interfaces.
typedef struct go2_interfaces__msg__PathPoint
{
  float t_from_start;
  float x;
  float y;
  float yaw;
  float vx;
  float vy;
  float vyaw;
} go2_interfaces__msg__PathPoint;

// Struct for a sequence of go2_interfaces__msg__PathPoint.
typedef struct go2_interfaces__msg__PathPoint__Sequence
{
  go2_interfaces__msg__PathPoint * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} go2_interfaces__msg__PathPoint__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GO2_INTERFACES__MSG__DETAIL__PATH_POINT__STRUCT_H_
