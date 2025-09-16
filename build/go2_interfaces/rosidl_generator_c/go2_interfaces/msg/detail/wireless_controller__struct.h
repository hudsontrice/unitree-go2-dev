// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from go2_interfaces:msg/WirelessController.idl
// generated code does not contain a copyright notice

#ifndef GO2_INTERFACES__MSG__DETAIL__WIRELESS_CONTROLLER__STRUCT_H_
#define GO2_INTERFACES__MSG__DETAIL__WIRELESS_CONTROLLER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/WirelessController in the package go2_interfaces.
typedef struct go2_interfaces__msg__WirelessController
{
  float lx;
  float ly;
  float rx;
  float ry;
  uint16_t keys;
} go2_interfaces__msg__WirelessController;

// Struct for a sequence of go2_interfaces__msg__WirelessController.
typedef struct go2_interfaces__msg__WirelessController__Sequence
{
  go2_interfaces__msg__WirelessController * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} go2_interfaces__msg__WirelessController__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GO2_INTERFACES__MSG__DETAIL__WIRELESS_CONTROLLER__STRUCT_H_
