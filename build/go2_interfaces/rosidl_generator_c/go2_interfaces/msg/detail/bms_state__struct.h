// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from go2_interfaces:msg/BmsState.idl
// generated code does not contain a copyright notice

#ifndef GO2_INTERFACES__MSG__DETAIL__BMS_STATE__STRUCT_H_
#define GO2_INTERFACES__MSG__DETAIL__BMS_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/BmsState in the package go2_interfaces.
typedef struct go2_interfaces__msg__BmsState
{
  uint8_t version_high;
  uint8_t version_low;
  uint8_t status;
  uint8_t soc;
  int32_t current;
  uint16_t cycle;
  int8_t bq_ntc[2];
  int8_t mcu_ntc[2];
  uint16_t cell_vol[15];
} go2_interfaces__msg__BmsState;

// Struct for a sequence of go2_interfaces__msg__BmsState.
typedef struct go2_interfaces__msg__BmsState__Sequence
{
  go2_interfaces__msg__BmsState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} go2_interfaces__msg__BmsState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GO2_INTERFACES__MSG__DETAIL__BMS_STATE__STRUCT_H_
