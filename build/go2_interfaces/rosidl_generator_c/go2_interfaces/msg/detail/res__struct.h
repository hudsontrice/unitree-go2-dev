// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from go2_interfaces:msg/Res.idl
// generated code does not contain a copyright notice

#ifndef GO2_INTERFACES__MSG__DETAIL__RES__STRUCT_H_
#define GO2_INTERFACES__MSG__DETAIL__RES__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'uuid'
// Member 'body'
#include "rosidl_runtime_c/string.h"
// Member 'data'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/Res in the package go2_interfaces.
typedef struct go2_interfaces__msg__Res
{
  rosidl_runtime_c__String uuid;
  rosidl_runtime_c__uint8__Sequence data;
  rosidl_runtime_c__String body;
} go2_interfaces__msg__Res;

// Struct for a sequence of go2_interfaces__msg__Res.
typedef struct go2_interfaces__msg__Res__Sequence
{
  go2_interfaces__msg__Res * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} go2_interfaces__msg__Res__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GO2_INTERFACES__MSG__DETAIL__RES__STRUCT_H_
