// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from go2_interfaces:msg/WebRtcReq.idl
// generated code does not contain a copyright notice

#ifndef GO2_INTERFACES__MSG__DETAIL__WEB_RTC_REQ__STRUCT_H_
#define GO2_INTERFACES__MSG__DETAIL__WEB_RTC_REQ__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'topic'
// Member 'parameter'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/WebRtcReq in the package go2_interfaces.
/**
  * message header id. if 0, it will be assigned automatically
 */
typedef struct go2_interfaces__msg__WebRtcReq
{
  int64_t id;
  /// topic name on dog's side including rt/ prefix
  rosidl_runtime_c__String topic;
  /// api_id, see https://wiki.theroboverse.com/en/unitree-go2-app-console-commands#sending-commands-to-go2
  int64_t api_id;
  /// payload for specific api_id
  rosidl_runtime_c__String parameter;
  /// priority of the message. 0 non-priority, 1 priority
  uint8_t priority;
} go2_interfaces__msg__WebRtcReq;

// Struct for a sequence of go2_interfaces__msg__WebRtcReq.
typedef struct go2_interfaces__msg__WebRtcReq__Sequence
{
  go2_interfaces__msg__WebRtcReq * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} go2_interfaces__msg__WebRtcReq__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GO2_INTERFACES__MSG__DETAIL__WEB_RTC_REQ__STRUCT_H_
