// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from go2_interfaces:msg/SportModeState.idl
// generated code does not contain a copyright notice
#include "go2_interfaces/msg/detail/sport_mode_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `stamp`
#include "go2_interfaces/msg/detail/time_spec__functions.h"
// Member `imu_state`
#include "go2_interfaces/msg/detail/imu__functions.h"

bool
go2_interfaces__msg__SportModeState__init(go2_interfaces__msg__SportModeState * msg)
{
  if (!msg) {
    return false;
  }
  // stamp
  if (!go2_interfaces__msg__TimeSpec__init(&msg->stamp)) {
    go2_interfaces__msg__SportModeState__fini(msg);
    return false;
  }
  // error_code
  // imu_state
  if (!go2_interfaces__msg__IMU__init(&msg->imu_state)) {
    go2_interfaces__msg__SportModeState__fini(msg);
    return false;
  }
  // mode
  // progress
  // gait_type
  // foot_raise_height
  // position
  // body_height
  // velocity
  // yaw_speed
  // range_obstacle
  // foot_force
  // foot_position_body
  // foot_speed_body
  return true;
}

void
go2_interfaces__msg__SportModeState__fini(go2_interfaces__msg__SportModeState * msg)
{
  if (!msg) {
    return;
  }
  // stamp
  go2_interfaces__msg__TimeSpec__fini(&msg->stamp);
  // error_code
  // imu_state
  go2_interfaces__msg__IMU__fini(&msg->imu_state);
  // mode
  // progress
  // gait_type
  // foot_raise_height
  // position
  // body_height
  // velocity
  // yaw_speed
  // range_obstacle
  // foot_force
  // foot_position_body
  // foot_speed_body
}

bool
go2_interfaces__msg__SportModeState__are_equal(const go2_interfaces__msg__SportModeState * lhs, const go2_interfaces__msg__SportModeState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // stamp
  if (!go2_interfaces__msg__TimeSpec__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  // error_code
  if (lhs->error_code != rhs->error_code) {
    return false;
  }
  // imu_state
  if (!go2_interfaces__msg__IMU__are_equal(
      &(lhs->imu_state), &(rhs->imu_state)))
  {
    return false;
  }
  // mode
  if (lhs->mode != rhs->mode) {
    return false;
  }
  // progress
  if (lhs->progress != rhs->progress) {
    return false;
  }
  // gait_type
  if (lhs->gait_type != rhs->gait_type) {
    return false;
  }
  // foot_raise_height
  if (lhs->foot_raise_height != rhs->foot_raise_height) {
    return false;
  }
  // position
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->position[i] != rhs->position[i]) {
      return false;
    }
  }
  // body_height
  if (lhs->body_height != rhs->body_height) {
    return false;
  }
  // velocity
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->velocity[i] != rhs->velocity[i]) {
      return false;
    }
  }
  // yaw_speed
  if (lhs->yaw_speed != rhs->yaw_speed) {
    return false;
  }
  // range_obstacle
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->range_obstacle[i] != rhs->range_obstacle[i]) {
      return false;
    }
  }
  // foot_force
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->foot_force[i] != rhs->foot_force[i]) {
      return false;
    }
  }
  // foot_position_body
  for (size_t i = 0; i < 12; ++i) {
    if (lhs->foot_position_body[i] != rhs->foot_position_body[i]) {
      return false;
    }
  }
  // foot_speed_body
  for (size_t i = 0; i < 12; ++i) {
    if (lhs->foot_speed_body[i] != rhs->foot_speed_body[i]) {
      return false;
    }
  }
  return true;
}

bool
go2_interfaces__msg__SportModeState__copy(
  const go2_interfaces__msg__SportModeState * input,
  go2_interfaces__msg__SportModeState * output)
{
  if (!input || !output) {
    return false;
  }
  // stamp
  if (!go2_interfaces__msg__TimeSpec__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  // error_code
  output->error_code = input->error_code;
  // imu_state
  if (!go2_interfaces__msg__IMU__copy(
      &(input->imu_state), &(output->imu_state)))
  {
    return false;
  }
  // mode
  output->mode = input->mode;
  // progress
  output->progress = input->progress;
  // gait_type
  output->gait_type = input->gait_type;
  // foot_raise_height
  output->foot_raise_height = input->foot_raise_height;
  // position
  for (size_t i = 0; i < 3; ++i) {
    output->position[i] = input->position[i];
  }
  // body_height
  output->body_height = input->body_height;
  // velocity
  for (size_t i = 0; i < 3; ++i) {
    output->velocity[i] = input->velocity[i];
  }
  // yaw_speed
  output->yaw_speed = input->yaw_speed;
  // range_obstacle
  for (size_t i = 0; i < 4; ++i) {
    output->range_obstacle[i] = input->range_obstacle[i];
  }
  // foot_force
  for (size_t i = 0; i < 4; ++i) {
    output->foot_force[i] = input->foot_force[i];
  }
  // foot_position_body
  for (size_t i = 0; i < 12; ++i) {
    output->foot_position_body[i] = input->foot_position_body[i];
  }
  // foot_speed_body
  for (size_t i = 0; i < 12; ++i) {
    output->foot_speed_body[i] = input->foot_speed_body[i];
  }
  return true;
}

go2_interfaces__msg__SportModeState *
go2_interfaces__msg__SportModeState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_interfaces__msg__SportModeState * msg = (go2_interfaces__msg__SportModeState *)allocator.allocate(sizeof(go2_interfaces__msg__SportModeState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(go2_interfaces__msg__SportModeState));
  bool success = go2_interfaces__msg__SportModeState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
go2_interfaces__msg__SportModeState__destroy(go2_interfaces__msg__SportModeState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    go2_interfaces__msg__SportModeState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
go2_interfaces__msg__SportModeState__Sequence__init(go2_interfaces__msg__SportModeState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_interfaces__msg__SportModeState * data = NULL;

  if (size) {
    data = (go2_interfaces__msg__SportModeState *)allocator.zero_allocate(size, sizeof(go2_interfaces__msg__SportModeState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = go2_interfaces__msg__SportModeState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        go2_interfaces__msg__SportModeState__fini(&data[i - 1]);
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
go2_interfaces__msg__SportModeState__Sequence__fini(go2_interfaces__msg__SportModeState__Sequence * array)
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
      go2_interfaces__msg__SportModeState__fini(&array->data[i]);
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

go2_interfaces__msg__SportModeState__Sequence *
go2_interfaces__msg__SportModeState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_interfaces__msg__SportModeState__Sequence * array = (go2_interfaces__msg__SportModeState__Sequence *)allocator.allocate(sizeof(go2_interfaces__msg__SportModeState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = go2_interfaces__msg__SportModeState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
go2_interfaces__msg__SportModeState__Sequence__destroy(go2_interfaces__msg__SportModeState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    go2_interfaces__msg__SportModeState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
go2_interfaces__msg__SportModeState__Sequence__are_equal(const go2_interfaces__msg__SportModeState__Sequence * lhs, const go2_interfaces__msg__SportModeState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!go2_interfaces__msg__SportModeState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
go2_interfaces__msg__SportModeState__Sequence__copy(
  const go2_interfaces__msg__SportModeState__Sequence * input,
  go2_interfaces__msg__SportModeState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(go2_interfaces__msg__SportModeState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    go2_interfaces__msg__SportModeState * data =
      (go2_interfaces__msg__SportModeState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!go2_interfaces__msg__SportModeState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          go2_interfaces__msg__SportModeState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!go2_interfaces__msg__SportModeState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
