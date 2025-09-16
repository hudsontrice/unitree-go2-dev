// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from go2_interfaces:msg/LowState.idl
// generated code does not contain a copyright notice

#ifndef GO2_INTERFACES__MSG__DETAIL__LOW_STATE__STRUCT_H_
#define GO2_INTERFACES__MSG__DETAIL__LOW_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'imu_state'
#include "go2_interfaces/msg/detail/imu__struct.h"
// Member 'motor_state'
#include "go2_interfaces/msg/detail/motor_state__struct.h"
// Member 'bms_state'
#include "go2_interfaces/msg/detail/bms_state__struct.h"

/// Struct defined in msg/LowState in the package go2_interfaces.
typedef struct go2_interfaces__msg__LowState
{
  uint8_t head[2];
  uint8_t level_flag;
  uint8_t frame_reserve;
  uint32_t sn[2];
  uint32_t version[2];
  uint16_t bandwidth;
  go2_interfaces__msg__IMU imu_state;
  go2_interfaces__msg__MotorState motor_state[20];
  go2_interfaces__msg__BmsState bms_state;
  int16_t foot_force[4];
  int16_t foot_force_est[4];
  uint32_t tick;
  uint8_t wireless_remote[40];
  uint8_t bit_flag;
  float adc_reel;
  int8_t temperature_ntc1;
  int8_t temperature_ntc2;
  float power_v;
  float power_a;
  uint16_t fan_frequency[4];
  uint32_t reserve;
  uint32_t crc;
} go2_interfaces__msg__LowState;

// Struct for a sequence of go2_interfaces__msg__LowState.
typedef struct go2_interfaces__msg__LowState__Sequence
{
  go2_interfaces__msg__LowState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} go2_interfaces__msg__LowState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GO2_INTERFACES__MSG__DETAIL__LOW_STATE__STRUCT_H_
