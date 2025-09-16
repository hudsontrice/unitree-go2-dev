// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from go2_interfaces:msg/MotorStates.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "go2_interfaces/msg/detail/motor_states__rosidl_typesupport_introspection_c.h"
#include "go2_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "go2_interfaces/msg/detail/motor_states__functions.h"
#include "go2_interfaces/msg/detail/motor_states__struct.h"


// Include directives for member types
// Member `states`
#include "go2_interfaces/msg/motor_state.h"
// Member `states`
#include "go2_interfaces/msg/detail/motor_state__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void go2_interfaces__msg__MotorStates__rosidl_typesupport_introspection_c__MotorStates_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  go2_interfaces__msg__MotorStates__init(message_memory);
}

void go2_interfaces__msg__MotorStates__rosidl_typesupport_introspection_c__MotorStates_fini_function(void * message_memory)
{
  go2_interfaces__msg__MotorStates__fini(message_memory);
}

size_t go2_interfaces__msg__MotorStates__rosidl_typesupport_introspection_c__size_function__MotorStates__states(
  const void * untyped_member)
{
  const go2_interfaces__msg__MotorState__Sequence * member =
    (const go2_interfaces__msg__MotorState__Sequence *)(untyped_member);
  return member->size;
}

const void * go2_interfaces__msg__MotorStates__rosidl_typesupport_introspection_c__get_const_function__MotorStates__states(
  const void * untyped_member, size_t index)
{
  const go2_interfaces__msg__MotorState__Sequence * member =
    (const go2_interfaces__msg__MotorState__Sequence *)(untyped_member);
  return &member->data[index];
}

void * go2_interfaces__msg__MotorStates__rosidl_typesupport_introspection_c__get_function__MotorStates__states(
  void * untyped_member, size_t index)
{
  go2_interfaces__msg__MotorState__Sequence * member =
    (go2_interfaces__msg__MotorState__Sequence *)(untyped_member);
  return &member->data[index];
}

void go2_interfaces__msg__MotorStates__rosidl_typesupport_introspection_c__fetch_function__MotorStates__states(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const go2_interfaces__msg__MotorState * item =
    ((const go2_interfaces__msg__MotorState *)
    go2_interfaces__msg__MotorStates__rosidl_typesupport_introspection_c__get_const_function__MotorStates__states(untyped_member, index));
  go2_interfaces__msg__MotorState * value =
    (go2_interfaces__msg__MotorState *)(untyped_value);
  *value = *item;
}

void go2_interfaces__msg__MotorStates__rosidl_typesupport_introspection_c__assign_function__MotorStates__states(
  void * untyped_member, size_t index, const void * untyped_value)
{
  go2_interfaces__msg__MotorState * item =
    ((go2_interfaces__msg__MotorState *)
    go2_interfaces__msg__MotorStates__rosidl_typesupport_introspection_c__get_function__MotorStates__states(untyped_member, index));
  const go2_interfaces__msg__MotorState * value =
    (const go2_interfaces__msg__MotorState *)(untyped_value);
  *item = *value;
}

bool go2_interfaces__msg__MotorStates__rosidl_typesupport_introspection_c__resize_function__MotorStates__states(
  void * untyped_member, size_t size)
{
  go2_interfaces__msg__MotorState__Sequence * member =
    (go2_interfaces__msg__MotorState__Sequence *)(untyped_member);
  go2_interfaces__msg__MotorState__Sequence__fini(member);
  return go2_interfaces__msg__MotorState__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember go2_interfaces__msg__MotorStates__rosidl_typesupport_introspection_c__MotorStates_message_member_array[1] = {
  {
    "states",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(go2_interfaces__msg__MotorStates, states),  // bytes offset in struct
    NULL,  // default value
    go2_interfaces__msg__MotorStates__rosidl_typesupport_introspection_c__size_function__MotorStates__states,  // size() function pointer
    go2_interfaces__msg__MotorStates__rosidl_typesupport_introspection_c__get_const_function__MotorStates__states,  // get_const(index) function pointer
    go2_interfaces__msg__MotorStates__rosidl_typesupport_introspection_c__get_function__MotorStates__states,  // get(index) function pointer
    go2_interfaces__msg__MotorStates__rosidl_typesupport_introspection_c__fetch_function__MotorStates__states,  // fetch(index, &value) function pointer
    go2_interfaces__msg__MotorStates__rosidl_typesupport_introspection_c__assign_function__MotorStates__states,  // assign(index, value) function pointer
    go2_interfaces__msg__MotorStates__rosidl_typesupport_introspection_c__resize_function__MotorStates__states  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers go2_interfaces__msg__MotorStates__rosidl_typesupport_introspection_c__MotorStates_message_members = {
  "go2_interfaces__msg",  // message namespace
  "MotorStates",  // message name
  1,  // number of fields
  sizeof(go2_interfaces__msg__MotorStates),
  go2_interfaces__msg__MotorStates__rosidl_typesupport_introspection_c__MotorStates_message_member_array,  // message members
  go2_interfaces__msg__MotorStates__rosidl_typesupport_introspection_c__MotorStates_init_function,  // function to initialize message memory (memory has to be allocated)
  go2_interfaces__msg__MotorStates__rosidl_typesupport_introspection_c__MotorStates_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t go2_interfaces__msg__MotorStates__rosidl_typesupport_introspection_c__MotorStates_message_type_support_handle = {
  0,
  &go2_interfaces__msg__MotorStates__rosidl_typesupport_introspection_c__MotorStates_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_go2_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, go2_interfaces, msg, MotorStates)() {
  go2_interfaces__msg__MotorStates__rosidl_typesupport_introspection_c__MotorStates_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, go2_interfaces, msg, MotorState)();
  if (!go2_interfaces__msg__MotorStates__rosidl_typesupport_introspection_c__MotorStates_message_type_support_handle.typesupport_identifier) {
    go2_interfaces__msg__MotorStates__rosidl_typesupport_introspection_c__MotorStates_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &go2_interfaces__msg__MotorStates__rosidl_typesupport_introspection_c__MotorStates_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
