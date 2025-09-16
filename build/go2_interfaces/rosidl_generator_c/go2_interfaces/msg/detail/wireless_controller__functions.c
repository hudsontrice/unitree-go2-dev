// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from go2_interfaces:msg/WirelessController.idl
// generated code does not contain a copyright notice
#include "go2_interfaces/msg/detail/wireless_controller__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
go2_interfaces__msg__WirelessController__init(go2_interfaces__msg__WirelessController * msg)
{
  if (!msg) {
    return false;
  }
  // lx
  // ly
  // rx
  // ry
  // keys
  return true;
}

void
go2_interfaces__msg__WirelessController__fini(go2_interfaces__msg__WirelessController * msg)
{
  if (!msg) {
    return;
  }
  // lx
  // ly
  // rx
  // ry
  // keys
}

bool
go2_interfaces__msg__WirelessController__are_equal(const go2_interfaces__msg__WirelessController * lhs, const go2_interfaces__msg__WirelessController * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // lx
  if (lhs->lx != rhs->lx) {
    return false;
  }
  // ly
  if (lhs->ly != rhs->ly) {
    return false;
  }
  // rx
  if (lhs->rx != rhs->rx) {
    return false;
  }
  // ry
  if (lhs->ry != rhs->ry) {
    return false;
  }
  // keys
  if (lhs->keys != rhs->keys) {
    return false;
  }
  return true;
}

bool
go2_interfaces__msg__WirelessController__copy(
  const go2_interfaces__msg__WirelessController * input,
  go2_interfaces__msg__WirelessController * output)
{
  if (!input || !output) {
    return false;
  }
  // lx
  output->lx = input->lx;
  // ly
  output->ly = input->ly;
  // rx
  output->rx = input->rx;
  // ry
  output->ry = input->ry;
  // keys
  output->keys = input->keys;
  return true;
}

go2_interfaces__msg__WirelessController *
go2_interfaces__msg__WirelessController__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_interfaces__msg__WirelessController * msg = (go2_interfaces__msg__WirelessController *)allocator.allocate(sizeof(go2_interfaces__msg__WirelessController), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(go2_interfaces__msg__WirelessController));
  bool success = go2_interfaces__msg__WirelessController__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
go2_interfaces__msg__WirelessController__destroy(go2_interfaces__msg__WirelessController * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    go2_interfaces__msg__WirelessController__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
go2_interfaces__msg__WirelessController__Sequence__init(go2_interfaces__msg__WirelessController__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_interfaces__msg__WirelessController * data = NULL;

  if (size) {
    data = (go2_interfaces__msg__WirelessController *)allocator.zero_allocate(size, sizeof(go2_interfaces__msg__WirelessController), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = go2_interfaces__msg__WirelessController__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        go2_interfaces__msg__WirelessController__fini(&data[i - 1]);
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
go2_interfaces__msg__WirelessController__Sequence__fini(go2_interfaces__msg__WirelessController__Sequence * array)
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
      go2_interfaces__msg__WirelessController__fini(&array->data[i]);
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

go2_interfaces__msg__WirelessController__Sequence *
go2_interfaces__msg__WirelessController__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_interfaces__msg__WirelessController__Sequence * array = (go2_interfaces__msg__WirelessController__Sequence *)allocator.allocate(sizeof(go2_interfaces__msg__WirelessController__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = go2_interfaces__msg__WirelessController__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
go2_interfaces__msg__WirelessController__Sequence__destroy(go2_interfaces__msg__WirelessController__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    go2_interfaces__msg__WirelessController__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
go2_interfaces__msg__WirelessController__Sequence__are_equal(const go2_interfaces__msg__WirelessController__Sequence * lhs, const go2_interfaces__msg__WirelessController__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!go2_interfaces__msg__WirelessController__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
go2_interfaces__msg__WirelessController__Sequence__copy(
  const go2_interfaces__msg__WirelessController__Sequence * input,
  go2_interfaces__msg__WirelessController__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(go2_interfaces__msg__WirelessController);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    go2_interfaces__msg__WirelessController * data =
      (go2_interfaces__msg__WirelessController *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!go2_interfaces__msg__WirelessController__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          go2_interfaces__msg__WirelessController__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!go2_interfaces__msg__WirelessController__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
