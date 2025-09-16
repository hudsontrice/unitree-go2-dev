// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from go2_interfaces:msg/PathPoint.idl
// generated code does not contain a copyright notice
#include "go2_interfaces/msg/detail/path_point__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
go2_interfaces__msg__PathPoint__init(go2_interfaces__msg__PathPoint * msg)
{
  if (!msg) {
    return false;
  }
  // t_from_start
  // x
  // y
  // yaw
  // vx
  // vy
  // vyaw
  return true;
}

void
go2_interfaces__msg__PathPoint__fini(go2_interfaces__msg__PathPoint * msg)
{
  if (!msg) {
    return;
  }
  // t_from_start
  // x
  // y
  // yaw
  // vx
  // vy
  // vyaw
}

bool
go2_interfaces__msg__PathPoint__are_equal(const go2_interfaces__msg__PathPoint * lhs, const go2_interfaces__msg__PathPoint * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // t_from_start
  if (lhs->t_from_start != rhs->t_from_start) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // yaw
  if (lhs->yaw != rhs->yaw) {
    return false;
  }
  // vx
  if (lhs->vx != rhs->vx) {
    return false;
  }
  // vy
  if (lhs->vy != rhs->vy) {
    return false;
  }
  // vyaw
  if (lhs->vyaw != rhs->vyaw) {
    return false;
  }
  return true;
}

bool
go2_interfaces__msg__PathPoint__copy(
  const go2_interfaces__msg__PathPoint * input,
  go2_interfaces__msg__PathPoint * output)
{
  if (!input || !output) {
    return false;
  }
  // t_from_start
  output->t_from_start = input->t_from_start;
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // yaw
  output->yaw = input->yaw;
  // vx
  output->vx = input->vx;
  // vy
  output->vy = input->vy;
  // vyaw
  output->vyaw = input->vyaw;
  return true;
}

go2_interfaces__msg__PathPoint *
go2_interfaces__msg__PathPoint__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_interfaces__msg__PathPoint * msg = (go2_interfaces__msg__PathPoint *)allocator.allocate(sizeof(go2_interfaces__msg__PathPoint), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(go2_interfaces__msg__PathPoint));
  bool success = go2_interfaces__msg__PathPoint__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
go2_interfaces__msg__PathPoint__destroy(go2_interfaces__msg__PathPoint * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    go2_interfaces__msg__PathPoint__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
go2_interfaces__msg__PathPoint__Sequence__init(go2_interfaces__msg__PathPoint__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_interfaces__msg__PathPoint * data = NULL;

  if (size) {
    data = (go2_interfaces__msg__PathPoint *)allocator.zero_allocate(size, sizeof(go2_interfaces__msg__PathPoint), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = go2_interfaces__msg__PathPoint__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        go2_interfaces__msg__PathPoint__fini(&data[i - 1]);
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
go2_interfaces__msg__PathPoint__Sequence__fini(go2_interfaces__msg__PathPoint__Sequence * array)
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
      go2_interfaces__msg__PathPoint__fini(&array->data[i]);
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

go2_interfaces__msg__PathPoint__Sequence *
go2_interfaces__msg__PathPoint__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_interfaces__msg__PathPoint__Sequence * array = (go2_interfaces__msg__PathPoint__Sequence *)allocator.allocate(sizeof(go2_interfaces__msg__PathPoint__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = go2_interfaces__msg__PathPoint__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
go2_interfaces__msg__PathPoint__Sequence__destroy(go2_interfaces__msg__PathPoint__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    go2_interfaces__msg__PathPoint__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
go2_interfaces__msg__PathPoint__Sequence__are_equal(const go2_interfaces__msg__PathPoint__Sequence * lhs, const go2_interfaces__msg__PathPoint__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!go2_interfaces__msg__PathPoint__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
go2_interfaces__msg__PathPoint__Sequence__copy(
  const go2_interfaces__msg__PathPoint__Sequence * input,
  go2_interfaces__msg__PathPoint__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(go2_interfaces__msg__PathPoint);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    go2_interfaces__msg__PathPoint * data =
      (go2_interfaces__msg__PathPoint *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!go2_interfaces__msg__PathPoint__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          go2_interfaces__msg__PathPoint__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!go2_interfaces__msg__PathPoint__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
