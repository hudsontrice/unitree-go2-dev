// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from go2_interfaces:msg/VoxelMapCompressed.idl
// generated code does not contain a copyright notice

#ifndef GO2_INTERFACES__MSG__DETAIL__VOXEL_MAP_COMPRESSED__STRUCT_H_
#define GO2_INTERFACES__MSG__DETAIL__VOXEL_MAP_COMPRESSED__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'frame_id'
#include "rosidl_runtime_c/string.h"
// Member 'data'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/VoxelMapCompressed in the package go2_interfaces.
/**
  * Timestamp (in seconds since epoch)
 */
typedef struct go2_interfaces__msg__VoxelMapCompressed
{
  double stamp;
  /// Frame ID for the coordinate frame
  rosidl_runtime_c__String frame_id;
  /// Resolution of the voxel map
  double resolution;
  /// Origin of the voxel map (x, y, z)
  double origin[3];
  /// Width of the voxel map in each dimension (x, y, z)
  int16_t width[3];
  /// Source size of the compressed data
  uint64_t src_size;
  /// Compressed voxel data
  rosidl_runtime_c__uint8__Sequence data;
} go2_interfaces__msg__VoxelMapCompressed;

// Struct for a sequence of go2_interfaces__msg__VoxelMapCompressed.
typedef struct go2_interfaces__msg__VoxelMapCompressed__Sequence
{
  go2_interfaces__msg__VoxelMapCompressed * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} go2_interfaces__msg__VoxelMapCompressed__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GO2_INTERFACES__MSG__DETAIL__VOXEL_MAP_COMPRESSED__STRUCT_H_
