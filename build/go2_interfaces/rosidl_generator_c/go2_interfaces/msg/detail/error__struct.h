// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from go2_interfaces:msg/Error.idl
// generated code does not contain a copyright notice

#ifndef GO2_INTERFACES__MSG__DETAIL__ERROR__STRUCT_H_
#define GO2_INTERFACES__MSG__DETAIL__ERROR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Error in the package go2_interfaces.
typedef struct go2_interfaces__msg__Error
{
  uint32_t source;
  uint32_t state;
} go2_interfaces__msg__Error;

// Struct for a sequence of go2_interfaces__msg__Error.
typedef struct go2_interfaces__msg__Error__Sequence
{
  go2_interfaces__msg__Error * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} go2_interfaces__msg__Error__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GO2_INTERFACES__MSG__DETAIL__ERROR__STRUCT_H_
