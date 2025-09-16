// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from go2_interfaces:msg/MotorCmds.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "go2_interfaces/msg/detail/motor_cmds__rosidl_typesupport_introspection_c.h"
#include "go2_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "go2_interfaces/msg/detail/motor_cmds__functions.h"
#include "go2_interfaces/msg/detail/motor_cmds__struct.h"


// Include directives for member types
// Member `cmds`
#include "go2_interfaces/msg/motor_cmd.h"
// Member `cmds`
#include "go2_interfaces/msg/detail/motor_cmd__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void go2_interfaces__msg__MotorCmds__rosidl_typesupport_introspection_c__MotorCmds_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  go2_interfaces__msg__MotorCmds__init(message_memory);
}

void go2_interfaces__msg__MotorCmds__rosidl_typesupport_introspection_c__MotorCmds_fini_function(void * message_memory)
{
  go2_interfaces__msg__MotorCmds__fini(message_memory);
}

size_t go2_interfaces__msg__MotorCmds__rosidl_typesupport_introspection_c__size_function__MotorCmds__cmds(
  const void * untyped_member)
{
  const go2_interfaces__msg__MotorCmd__Sequence * member =
    (const go2_interfaces__msg__MotorCmd__Sequence *)(untyped_member);
  return member->size;
}

const void * go2_interfaces__msg__MotorCmds__rosidl_typesupport_introspection_c__get_const_function__MotorCmds__cmds(
  const void * untyped_member, size_t index)
{
  const go2_interfaces__msg__MotorCmd__Sequence * member =
    (const go2_interfaces__msg__MotorCmd__Sequence *)(untyped_member);
  return &member->data[index];
}

void * go2_interfaces__msg__MotorCmds__rosidl_typesupport_introspection_c__get_function__MotorCmds__cmds(
  void * untyped_member, size_t index)
{
  go2_interfaces__msg__MotorCmd__Sequence * member =
    (go2_interfaces__msg__MotorCmd__Sequence *)(untyped_member);
  return &member->data[index];
}

void go2_interfaces__msg__MotorCmds__rosidl_typesupport_introspection_c__fetch_function__MotorCmds__cmds(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const go2_interfaces__msg__MotorCmd * item =
    ((const go2_interfaces__msg__MotorCmd *)
    go2_interfaces__msg__MotorCmds__rosidl_typesupport_introspection_c__get_const_function__MotorCmds__cmds(untyped_member, index));
  go2_interfaces__msg__MotorCmd * value =
    (go2_interfaces__msg__MotorCmd *)(untyped_value);
  *value = *item;
}

void go2_interfaces__msg__MotorCmds__rosidl_typesupport_introspection_c__assign_function__MotorCmds__cmds(
  void * untyped_member, size_t index, const void * untyped_value)
{
  go2_interfaces__msg__MotorCmd * item =
    ((go2_interfaces__msg__MotorCmd *)
    go2_interfaces__msg__MotorCmds__rosidl_typesupport_introspection_c__get_function__MotorCmds__cmds(untyped_member, index));
  const go2_interfaces__msg__MotorCmd * value =
    (const go2_interfaces__msg__MotorCmd *)(untyped_value);
  *item = *value;
}

bool go2_interfaces__msg__MotorCmds__rosidl_typesupport_introspection_c__resize_function__MotorCmds__cmds(
  void * untyped_member, size_t size)
{
  go2_interfaces__msg__MotorCmd__Sequence * member =
    (go2_interfaces__msg__MotorCmd__Sequence *)(untyped_member);
  go2_interfaces__msg__MotorCmd__Sequence__fini(member);
  return go2_interfaces__msg__MotorCmd__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember go2_interfaces__msg__MotorCmds__rosidl_typesupport_introspection_c__MotorCmds_message_member_array[1] = {
  {
    "cmds",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(go2_interfaces__msg__MotorCmds, cmds),  // bytes offset in struct
    NULL,  // default value
    go2_interfaces__msg__MotorCmds__rosidl_typesupport_introspection_c__size_function__MotorCmds__cmds,  // size() function pointer
    go2_interfaces__msg__MotorCmds__rosidl_typesupport_introspection_c__get_const_function__MotorCmds__cmds,  // get_const(index) function pointer
    go2_interfaces__msg__MotorCmds__rosidl_typesupport_introspection_c__get_function__MotorCmds__cmds,  // get(index) function pointer
    go2_interfaces__msg__MotorCmds__rosidl_typesupport_introspection_c__fetch_function__MotorCmds__cmds,  // fetch(index, &value) function pointer
    go2_interfaces__msg__MotorCmds__rosidl_typesupport_introspection_c__assign_function__MotorCmds__cmds,  // assign(index, value) function pointer
    go2_interfaces__msg__MotorCmds__rosidl_typesupport_introspection_c__resize_function__MotorCmds__cmds  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers go2_interfaces__msg__MotorCmds__rosidl_typesupport_introspection_c__MotorCmds_message_members = {
  "go2_interfaces__msg",  // message namespace
  "MotorCmds",  // message name
  1,  // number of fields
  sizeof(go2_interfaces__msg__MotorCmds),
  go2_interfaces__msg__MotorCmds__rosidl_typesupport_introspection_c__MotorCmds_message_member_array,  // message members
  go2_interfaces__msg__MotorCmds__rosidl_typesupport_introspection_c__MotorCmds_init_function,  // function to initialize message memory (memory has to be allocated)
  go2_interfaces__msg__MotorCmds__rosidl_typesupport_introspection_c__MotorCmds_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t go2_interfaces__msg__MotorCmds__rosidl_typesupport_introspection_c__MotorCmds_message_type_support_handle = {
  0,
  &go2_interfaces__msg__MotorCmds__rosidl_typesupport_introspection_c__MotorCmds_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_go2_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, go2_interfaces, msg, MotorCmds)() {
  go2_interfaces__msg__MotorCmds__rosidl_typesupport_introspection_c__MotorCmds_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, go2_interfaces, msg, MotorCmd)();
  if (!go2_interfaces__msg__MotorCmds__rosidl_typesupport_introspection_c__MotorCmds_message_type_support_handle.typesupport_identifier) {
    go2_interfaces__msg__MotorCmds__rosidl_typesupport_introspection_c__MotorCmds_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &go2_interfaces__msg__MotorCmds__rosidl_typesupport_introspection_c__MotorCmds_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
