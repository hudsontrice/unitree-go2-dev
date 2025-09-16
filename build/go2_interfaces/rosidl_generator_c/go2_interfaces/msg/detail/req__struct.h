// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from go2_interfaces:msg/Req.idl
// generated code does not contain a copyright notice

#ifndef GO2_INTERFACES__MSG__DETAIL__REQ__STRUCT_H_
#define GO2_INTERFACES__MSG__DETAIL__REQ__STRUCT_H_

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

/// Struct defined in msg/Req in the package go2_interfaces.
typedef struct go2_interfaces__msg__Req
{
  rosidl_runtime_c__String uuid;
  rosidl_runtime_c__String body;
} go2_interfaces__msg__Req;

// Struct for a sequence of go2_interfaces__msg__Req.
typedef struct go2_interfaces__msg__Req__Sequence
{
  go2_interfaces__msg__Req * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} go2_interfaces__msg__Req__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GO2_INTERFACES__MSG__DETAIL__REQ__STRUCT_H_
