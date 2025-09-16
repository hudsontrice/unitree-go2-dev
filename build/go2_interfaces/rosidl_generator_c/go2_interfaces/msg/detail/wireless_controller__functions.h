// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from go2_interfaces:msg/WirelessController.idl
// generated code does not contain a copyright notice

#ifndef GO2_INTERFACES__MSG__DETAIL__WIRELESS_CONTROLLER__FUNCTIONS_H_
#define GO2_INTERFACES__MSG__DETAIL__WIRELESS_CONTROLLER__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "go2_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "go2_interfaces/msg/detail/wireless_controller__struct.h"

/// Initialize msg/WirelessController message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * go2_interfaces__msg__WirelessController
 * )) before or use
 * go2_interfaces__msg__WirelessController__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_go2_interfaces
bool
go2_interfaces__msg__WirelessController__init(go2_interfaces__msg__WirelessController * msg);

/// Finalize msg/WirelessController message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_go2_interfaces
void
go2_interfaces__msg__WirelessController__fini(go2_interfaces__msg__WirelessController * msg);

/// Create msg/WirelessController message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * go2_interfaces__msg__WirelessController__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_go2_interfaces
go2_interfaces__msg__WirelessController *
go2_interfaces__msg__WirelessController__create();

/// Destroy msg/WirelessController message.
/**
 * It calls
 * go2_interfaces__msg__WirelessController__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_go2_interfaces
void
go2_interfaces__msg__WirelessController__destroy(go2_interfaces__msg__WirelessController * msg);

/// Check for msg/WirelessController message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_go2_interfaces
bool
go2_interfaces__msg__WirelessController__are_equal(const go2_interfaces__msg__WirelessController * lhs, const go2_interfaces__msg__WirelessController * rhs);

/// Copy a msg/WirelessController message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_go2_interfaces
bool
go2_interfaces__msg__WirelessController__copy(
  const go2_interfaces__msg__WirelessController * input,
  go2_interfaces__msg__WirelessController * output);

/// Initialize array of msg/WirelessController messages.
/**
 * It allocates the memory for the number of elements and calls
 * go2_interfaces__msg__WirelessController__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_go2_interfaces
bool
go2_interfaces__msg__WirelessController__Sequence__init(go2_interfaces__msg__WirelessController__Sequence * array, size_t size);

/// Finalize array of msg/WirelessController messages.
/**
 * It calls
 * go2_interfaces__msg__WirelessController__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_go2_interfaces
void
go2_interfaces__msg__WirelessController__Sequence__fini(go2_interfaces__msg__WirelessController__Sequence * array);

/// Create array of msg/WirelessController messages.
/**
 * It allocates the memory for the array and calls
 * go2_interfaces__msg__WirelessController__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_go2_interfaces
go2_interfaces__msg__WirelessController__Sequence *
go2_interfaces__msg__WirelessController__Sequence__create(size_t size);

/// Destroy array of msg/WirelessController messages.
/**
 * It calls
 * go2_interfaces__msg__WirelessController__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_go2_interfaces
void
go2_interfaces__msg__WirelessController__Sequence__destroy(go2_interfaces__msg__WirelessController__Sequence * array);

/// Check for msg/WirelessController message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_go2_interfaces
bool
go2_interfaces__msg__WirelessController__Sequence__are_equal(const go2_interfaces__msg__WirelessController__Sequence * lhs, const go2_interfaces__msg__WirelessController__Sequence * rhs);

/// Copy an array of msg/WirelessController messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_go2_interfaces
bool
go2_interfaces__msg__WirelessController__Sequence__copy(
  const go2_interfaces__msg__WirelessController__Sequence * input,
  go2_interfaces__msg__WirelessController__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // GO2_INTERFACES__MSG__DETAIL__WIRELESS_CONTROLLER__FUNCTIONS_H_
