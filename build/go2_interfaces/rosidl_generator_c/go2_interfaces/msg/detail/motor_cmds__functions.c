// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from go2_interfaces:msg/MotorCmds.idl
// generated code does not contain a copyright notice
#include "go2_interfaces/msg/detail/motor_cmds__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `cmds`
#include "go2_interfaces/msg/detail/motor_cmd__functions.h"

bool
go2_interfaces__msg__MotorCmds__init(go2_interfaces__msg__MotorCmds * msg)
{
  if (!msg) {
    return false;
  }
  // cmds
  if (!go2_interfaces__msg__MotorCmd__Sequence__init(&msg->cmds, 0)) {
    go2_interfaces__msg__MotorCmds__fini(msg);
    return false;
  }
  return true;
}

void
go2_interfaces__msg__MotorCmds__fini(go2_interfaces__msg__MotorCmds * msg)
{
  if (!msg) {
    return;
  }
  // cmds
  go2_interfaces__msg__MotorCmd__Sequence__fini(&msg->cmds);
}

bool
go2_interfaces__msg__MotorCmds__are_equal(const go2_interfaces__msg__MotorCmds * lhs, const go2_interfaces__msg__MotorCmds * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // cmds
  if (!go2_interfaces__msg__MotorCmd__Sequence__are_equal(
      &(lhs->cmds), &(rhs->cmds)))
  {
    return false;
  }
  return true;
}

bool
go2_interfaces__msg__MotorCmds__copy(
  const go2_interfaces__msg__MotorCmds * input,
  go2_interfaces__msg__MotorCmds * output)
{
  if (!input || !output) {
    return false;
  }
  // cmds
  if (!go2_interfaces__msg__MotorCmd__Sequence__copy(
      &(input->cmds), &(output->cmds)))
  {
    return false;
  }
  return true;
}

go2_interfaces__msg__MotorCmds *
go2_interfaces__msg__MotorCmds__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_interfaces__msg__MotorCmds * msg = (go2_interfaces__msg__MotorCmds *)allocator.allocate(sizeof(go2_interfaces__msg__MotorCmds), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(go2_interfaces__msg__MotorCmds));
  bool success = go2_interfaces__msg__MotorCmds__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
go2_interfaces__msg__MotorCmds__destroy(go2_interfaces__msg__MotorCmds * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    go2_interfaces__msg__MotorCmds__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
go2_interfaces__msg__MotorCmds__Sequence__init(go2_interfaces__msg__MotorCmds__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_interfaces__msg__MotorCmds * data = NULL;

  if (size) {
    data = (go2_interfaces__msg__MotorCmds *)allocator.zero_allocate(size, sizeof(go2_interfaces__msg__MotorCmds), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = go2_interfaces__msg__MotorCmds__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        go2_interfaces__msg__MotorCmds__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
go2_interfaces__msg__MotorCmds__Sequence__fini(go2_interfaces__msg__MotorCmds__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      go2_interfaces__msg__MotorCmds__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

go2_interfaces__msg__MotorCmds__Sequence *
go2_interfaces__msg__MotorCmds__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_interfaces__msg__MotorCmds__Sequence * array = (go2_interfaces__msg__MotorCmds__Sequence *)allocator.allocate(sizeof(go2_interfaces__msg__MotorCmds__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = go2_interfaces__msg__MotorCmds__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
go2_interfaces__msg__MotorCmds__Sequence__destroy(go2_interfaces__msg__MotorCmds__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    go2_interfaces__msg__MotorCmds__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
go2_interfaces__msg__MotorCmds__Sequence__are_equal(const go2_interfaces__msg__MotorCmds__Sequence * lhs, const go2_interfaces__msg__MotorCmds__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!go2_interfaces__msg__MotorCmds__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
go2_interfaces__msg__MotorCmds__Sequence__copy(
  const go2_interfaces__msg__MotorCmds__Sequence * input,
  go2_interfaces__msg__MotorCmds__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(go2_interfaces__msg__MotorCmds);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    go2_interfaces__msg__MotorCmds * data =
      (go2_interfaces__msg__MotorCmds *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!go2_interfaces__msg__MotorCmds__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          go2_interfaces__msg__MotorCmds__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!go2_interfaces__msg__MotorCmds__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
