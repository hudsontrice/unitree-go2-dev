// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from go2_interfaces:msg/VoxelMapCompressed.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "go2_interfaces/msg/detail/voxel_map_compressed__rosidl_typesupport_introspection_c.h"
#include "go2_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "go2_interfaces/msg/detail/voxel_map_compressed__functions.h"
#include "go2_interfaces/msg/detail/voxel_map_compressed__struct.h"


// Include directives for member types
// Member `frame_id`
#include "rosidl_runtime_c/string_functions.h"
// Member `data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__VoxelMapCompressed_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  go2_interfaces__msg__VoxelMapCompressed__init(message_memory);
}

void go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__VoxelMapCompressed_fini_function(void * message_memory)
{
  go2_interfaces__msg__VoxelMapCompressed__fini(message_memory);
}

size_t go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__size_function__VoxelMapCompressed__origin(
  const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__get_const_function__VoxelMapCompressed__origin(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__get_function__VoxelMapCompressed__origin(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__fetch_function__VoxelMapCompressed__origin(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__get_const_function__VoxelMapCompressed__origin(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__assign_function__VoxelMapCompressed__origin(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__get_function__VoxelMapCompressed__origin(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

size_t go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__size_function__VoxelMapCompressed__width(
  const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__get_const_function__VoxelMapCompressed__width(
  const void * untyped_member, size_t index)
{
  const int16_t * member =
    (const int16_t *)(untyped_member);
  return &member[index];
}

void * go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__get_function__VoxelMapCompressed__width(
  void * untyped_member, size_t index)
{
  int16_t * member =
    (int16_t *)(untyped_member);
  return &member[index];
}

void go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__fetch_function__VoxelMapCompressed__width(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int16_t * item =
    ((const int16_t *)
    go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__get_const_function__VoxelMapCompressed__width(untyped_member, index));
  int16_t * value =
    (int16_t *)(untyped_value);
  *value = *item;
}

void go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__assign_function__VoxelMapCompressed__width(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int16_t * item =
    ((int16_t *)
    go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__get_function__VoxelMapCompressed__width(untyped_member, index));
  const int16_t * value =
    (const int16_t *)(untyped_value);
  *item = *value;
}

size_t go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__size_function__VoxelMapCompressed__data(
  const void * untyped_member)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return member->size;
}

const void * go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__get_const_function__VoxelMapCompressed__data(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void * go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__get_function__VoxelMapCompressed__data(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__fetch_function__VoxelMapCompressed__data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__get_const_function__VoxelMapCompressed__data(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__assign_function__VoxelMapCompressed__data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__get_function__VoxelMapCompressed__data(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

bool go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__resize_function__VoxelMapCompressed__data(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  rosidl_runtime_c__uint8__Sequence__fini(member);
  return rosidl_runtime_c__uint8__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__VoxelMapCompressed_message_member_array[7] = {
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(go2_interfaces__msg__VoxelMapCompressed, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "frame_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(go2_interfaces__msg__VoxelMapCompressed, frame_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "resolution",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(go2_interfaces__msg__VoxelMapCompressed, resolution),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "origin",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(go2_interfaces__msg__VoxelMapCompressed, origin),  // bytes offset in struct
    NULL,  // default value
    go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__size_function__VoxelMapCompressed__origin,  // size() function pointer
    go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__get_const_function__VoxelMapCompressed__origin,  // get_const(index) function pointer
    go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__get_function__VoxelMapCompressed__origin,  // get(index) function pointer
    go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__fetch_function__VoxelMapCompressed__origin,  // fetch(index, &value) function pointer
    go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__assign_function__VoxelMapCompressed__origin,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "width",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(go2_interfaces__msg__VoxelMapCompressed, width),  // bytes offset in struct
    NULL,  // default value
    go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__size_function__VoxelMapCompressed__width,  // size() function pointer
    go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__get_const_function__VoxelMapCompressed__width,  // get_const(index) function pointer
    go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__get_function__VoxelMapCompressed__width,  // get(index) function pointer
    go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__fetch_function__VoxelMapCompressed__width,  // fetch(index, &value) function pointer
    go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__assign_function__VoxelMapCompressed__width,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "src_size",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(go2_interfaces__msg__VoxelMapCompressed, src_size),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(go2_interfaces__msg__VoxelMapCompressed, data),  // bytes offset in struct
    NULL,  // default value
    go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__size_function__VoxelMapCompressed__data,  // size() function pointer
    go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__get_const_function__VoxelMapCompressed__data,  // get_const(index) function pointer
    go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__get_function__VoxelMapCompressed__data,  // get(index) function pointer
    go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__fetch_function__VoxelMapCompressed__data,  // fetch(index, &value) function pointer
    go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__assign_function__VoxelMapCompressed__data,  // assign(index, value) function pointer
    go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__resize_function__VoxelMapCompressed__data  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__VoxelMapCompressed_message_members = {
  "go2_interfaces__msg",  // message namespace
  "VoxelMapCompressed",  // message name
  7,  // number of fields
  sizeof(go2_interfaces__msg__VoxelMapCompressed),
  go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__VoxelMapCompressed_message_member_array,  // message members
  go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__VoxelMapCompressed_init_function,  // function to initialize message memory (memory has to be allocated)
  go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__VoxelMapCompressed_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__VoxelMapCompressed_message_type_support_handle = {
  0,
  &go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__VoxelMapCompressed_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_go2_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, go2_interfaces, msg, VoxelMapCompressed)() {
  if (!go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__VoxelMapCompressed_message_type_support_handle.typesupport_identifier) {
    go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__VoxelMapCompressed_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &go2_interfaces__msg__VoxelMapCompressed__rosidl_typesupport_introspection_c__VoxelMapCompressed_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
