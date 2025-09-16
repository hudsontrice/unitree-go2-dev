// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from go2_interfaces:msg/MotorState.idl
// generated code does not contain a copyright notice
#include "go2_interfaces/msg/detail/motor_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
go2_interfaces__msg__MotorState__init(go2_interfaces__msg__MotorState * msg)
{
  if (!msg) {
    return false;
  }
  // mode
  // q
  // dq
  // ddq
  // tau_est
  // q_raw
  // dq_raw
  // ddq_raw
  // temperature
  // lost
  // reserve
  return true;
}

void
go2_interfaces__msg__MotorState__fini(go2_interfaces__msg__MotorState * msg)
{
  if (!msg) {
    return;
  }
  // mode
  // q
  // dq
  // ddq
  // tau_est
  // q_raw
  // dq_raw
  // ddq_raw
  // temperature
  // lost
  // reserve
}

bool
go2_interfaces__msg__MotorState__are_equal(const go2_interfaces__msg__MotorState * lhs, const go2_interfaces__msg__MotorState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // mode
  if (lhs->mode != rhs->mode) {
    return false;
  }
  // q
  if (lhs->q != rhs->q) {
    return false;
  }
  // dq
  if (lhs->dq != rhs->dq) {
    return false;
  }
  // ddq
  if (lhs->ddq != rhs->ddq) {
    return false;
  }
  // tau_est
  if (lhs->tau_est != rhs->tau_est) {
    return false;
  }
  // q_raw
  if (lhs->q_raw != rhs->q_raw) {
    return false;
  }
  // dq_raw
  if (lhs->dq_raw != rhs->dq_raw) {
    return false;
  }
  // ddq_raw
  if (lhs->ddq_raw != rhs->ddq_raw) {
    return false;
  }
  // temperature
  if (lhs->temperature != rhs->temperature) {
    return false;
  }
  // lost
  if (lhs->lost != rhs->lost) {
    return false;
  }
  // reserve
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->reserve[i] != rhs->reserve[i]) {
      return false;
    }
  }
  return true;
}

bool
go2_interfaces__msg__MotorState__copy(
  const go2_interfaces__msg__MotorState * input,
  go2_interfaces__msg__MotorState * output)
{
  if (!input || !output) {
    return false;
  }
  // mode
  output->mode = input->mode;
  // q
  output->q = input->q;
  // dq
  output->dq = input->dq;
  // ddq
  output->ddq = input->ddq;
  // tau_est
  output->tau_est = input->tau_est;
  // q_raw
  output->q_raw = input->q_raw;
  // dq_raw
  output->dq_raw = input->dq_raw;
  // ddq_raw
  output->ddq_raw = input->ddq_raw;
  // temperature
  output->temperature = input->temperature;
  // lost
  output->lost = input->lost;
  // reserve
  for (size_t i = 0; i < 2; ++i) {
    output->reserve[i] = input->reserve[i];
  }
  return true;
}

go2_interfaces__msg__MotorState *
go2_interfaces__msg__MotorState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_interfaces__msg__MotorState * msg = (go2_interfaces__msg__MotorState *)allocator.allocate(sizeof(go2_interfaces__msg__MotorState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(go2_interfaces__msg__MotorState));
  bool success = go2_interfaces__msg__MotorState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
go2_interfaces__msg__MotorState__destroy(go2_interfaces__msg__MotorState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    go2_interfaces__msg__MotorState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
go2_interfaces__msg__MotorState__Sequence__init(go2_interfaces__msg__MotorState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_interfaces__msg__MotorState * data = NULL;

  if (size) {
    data = (go2_interfaces__msg__MotorState *)allocator.zero_allocate(size, sizeof(go2_interfaces__msg__MotorState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = go2_interfaces__msg__MotorState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        go2_interfaces__msg__MotorState__fini(&data[i - 1]);
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
go2_interfaces__msg__MotorState__Sequence__fini(go2_interfaces__msg__MotorState__Sequence * array)
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
      go2_interfaces__msg__MotorState__fini(&array->data[i]);
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

go2_interfaces__msg__MotorState__Sequence *
go2_interfaces__msg__MotorState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_interfaces__msg__MotorState__Sequence * array = (go2_interfaces__msg__MotorState__Sequence *)allocator.allocate(sizeof(go2_interfaces__msg__MotorState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = go2_interfaces__msg__MotorState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
go2_interfaces__msg__MotorState__Sequence__destroy(go2_interfaces__msg__MotorState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    go2_interfaces__msg__MotorState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
go2_interfaces__msg__MotorState__Sequence__are_equal(const go2_interfaces__msg__MotorState__Sequence * lhs, const go2_interfaces__msg__MotorState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!go2_interfaces__msg__MotorState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
go2_interfaces__msg__MotorState__Sequence__copy(
  const go2_interfaces__msg__MotorState__Sequence * input,
  go2_interfaces__msg__MotorState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(go2_interfaces__msg__MotorState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    go2_interfaces__msg__MotorState * data =
      (go2_interfaces__msg__MotorState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!go2_interfaces__msg__MotorState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          go2_interfaces__msg__MotorState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!go2_interfaces__msg__MotorState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
