// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from go2_interfaces:msg/UwbState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "go2_interfaces/msg/detail/uwb_state__rosidl_typesupport_introspection_c.h"
#include "go2_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "go2_interfaces/msg/detail/uwb_state__functions.h"
#include "go2_interfaces/msg/detail/uwb_state__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void go2_interfaces__msg__UwbState__rosidl_typesupport_introspection_c__UwbState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  go2_interfaces__msg__UwbState__init(message_memory);
}

void go2_interfaces__msg__UwbState__rosidl_typesupport_introspection_c__UwbState_fini_function(void * message_memory)
{
  go2_interfaces__msg__UwbState__fini(message_memory);
}

size_t go2_interfaces__msg__UwbState__rosidl_typesupport_introspection_c__size_function__UwbState__version(
  const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * go2_interfaces__msg__UwbState__rosidl_typesupport_introspection_c__get_const_function__UwbState__version(
  const void * untyped_member, size_t index)
{
  const uint8_t * member =
    (const uint8_t *)(untyped_member);
  return &member[index];
}

void * go2_interfaces__msg__UwbState__rosidl_typesupport_introspection_c__get_function__UwbState__version(
  void * untyped_member, size_t index)
{
  uint8_t * member =
    (uint8_t *)(untyped_member);
  return &member[index];
}

void go2_interfaces__msg__UwbState__rosidl_typesupport_introspection_c__fetch_function__UwbState__version(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    go2_interfaces__msg__UwbState__rosidl_typesupport_introspection_c__get_const_function__UwbState__version(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void go2_interfaces__msg__UwbState__rosidl_typesupport_introspection_c__assign_function__UwbState__version(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    go2_interfaces__msg__UwbState__rosidl_typesupport_introspection_c__get_function__UwbState__version(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

size_t go2_interfaces__msg__UwbState__rosidl_typesupport_introspection_c__size_function__UwbState__joystick(
  const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * go2_interfaces__msg__UwbState__rosidl_typesupport_introspection_c__get_const_function__UwbState__joystick(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * go2_interfaces__msg__UwbState__rosidl_typesupport_introspection_c__get_function__UwbState__joystick(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void go2_interfaces__msg__UwbState__rosidl_typesupport_introspection_c__fetch_function__UwbState__joystick(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    go2_interfaces__msg__UwbState__rosidl_typesupport_introspection_c__get_const_function__UwbState__joystick(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void go2_interfaces__msg__UwbState__rosidl_typesupport_introspection_c__assign_function__UwbState__joystick(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    go2_interfaces__msg__UwbState__rosidl_typesupport_introspection_c__get_function__UwbState__joystick(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember go2_interfaces__msg__UwbState__rosidl_typesupport_introspection_c__UwbState_message_member_array[17] = {
  {
    "version",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(go2_interfaces__msg__UwbState, version),  // bytes offset in struct
    NULL,  // default value
    go2_interfaces__msg__UwbState__rosidl_typesupport_introspection_c__size_function__UwbState__version,  // size() function pointer
    go2_interfaces__msg__UwbState__rosidl_typesupport_introspection_c__get_const_function__UwbState__version,  // get_const(index) function pointer
    go2_interfaces__msg__UwbState__rosidl_typesupport_introspection_c__get_function__UwbState__version,  // get(index) function pointer
    go2_interfaces__msg__UwbState__rosidl_typesupport_introspection_c__fetch_function__UwbState__version,  // fetch(index, &value) function pointer
    go2_interfaces__msg__UwbState__rosidl_typesupport_introspection_c__assign_function__UwbState__version,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "channel",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(go2_interfaces__msg__UwbState, channel),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "joy_mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(go2_interfaces__msg__UwbState, joy_mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "orientation_est",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(go2_interfaces__msg__UwbState, orientation_est),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pitch_est",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(go2_interfaces__msg__UwbState, pitch_est),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "distance_est",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(go2_interfaces__msg__UwbState, distance_est),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "yaw_est",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(go2_interfaces__msg__UwbState, yaw_est),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "tag_roll",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(go2_interfaces__msg__UwbState, tag_roll),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "tag_pitch",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(go2_interfaces__msg__UwbState, tag_pitch),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "tag_yaw",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(go2_interfaces__msg__UwbState, tag_yaw),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "base_roll",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(go2_interfaces__msg__UwbState, base_roll),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "base_pitch",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(go2_interfaces__msg__UwbState, base_pitch),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "base_yaw",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(go2_interfaces__msg__UwbState, base_yaw),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "joystick",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(go2_interfaces__msg__UwbState, joystick),  // bytes offset in struct
    NULL,  // default value
    go2_interfaces__msg__UwbState__rosidl_typesupport_introspection_c__size_function__UwbState__joystick,  // size() function pointer
    go2_interfaces__msg__UwbState__rosidl_typesupport_introspection_c__get_const_function__UwbState__joystick,  // get_const(index) function pointer
    go2_interfaces__msg__UwbState__rosidl_typesupport_introspection_c__get_function__UwbState__joystick,  // get(index) function pointer
    go2_interfaces__msg__UwbState__rosidl_typesupport_introspection_c__fetch_function__UwbState__joystick,  // fetch(index, &value) function pointer
    go2_interfaces__msg__UwbState__rosidl_typesupport_introspection_c__assign_function__UwbState__joystick,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "error_state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(go2_interfaces__msg__UwbState, error_state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "buttons",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(go2_interfaces__msg__UwbState, buttons),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "enabled_from_app",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(go2_interfaces__msg__UwbState, enabled_from_app),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers go2_interfaces__msg__UwbState__rosidl_typesupport_introspection_c__UwbState_message_members = {
  "go2_interfaces__msg",  // message namespace
  "UwbState",  // message name
  17,  // number of fields
  sizeof(go2_interfaces__msg__UwbState),
  go2_interfaces__msg__UwbState__rosidl_typesupport_introspection_c__UwbState_message_member_array,  // message members
  go2_interfaces__msg__UwbState__rosidl_typesupport_introspection_c__UwbState_init_function,  // function to initialize message memory (memory has to be allocated)
  go2_interfaces__msg__UwbState__rosidl_typesupport_introspection_c__UwbState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t go2_interfaces__msg__UwbState__rosidl_typesupport_introspection_c__UwbState_message_type_support_handle = {
  0,
  &go2_interfaces__msg__UwbState__rosidl_typesupport_introspection_c__UwbState_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_go2_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, go2_interfaces, msg, UwbState)() {
  if (!go2_interfaces__msg__UwbState__rosidl_typesupport_introspection_c__UwbState_message_type_support_handle.typesupport_identifier) {
    go2_interfaces__msg__UwbState__rosidl_typesupport_introspection_c__UwbState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &go2_interfaces__msg__UwbState__rosidl_typesupport_introspection_c__UwbState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
