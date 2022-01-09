#pragma once

#include "config.h"
#include <Eigen/Core>

namespace SoftwareRenderer {
// Vector2
#ifdef SOFTWARE_RENDERER_USE_DOUBLE_PRECISION
typedef Eigen::Vector2d Vector2;
#else
typedef Eigen::Vector2f Vector2;
#endif

// Vector3
#ifdef SOFTWARE_RENDERER_USE_DOUBLE_PRECISION
typedef Eigen::Vector3d Vector3;
#else
typedef Eigen::Vector3f Vector3;
#endif

// Vector4
#ifdef SOFTWARE_RENDERER_USE_DOUBLE_PRECISION
typedef Eigen::Vector4d Vector4;
#else
typedef Eigen::Vector4f Vector4;
#endif

// Matrix3x4
#ifdef SOFTWARE_RENDERER_USE_DOUBLE_PRECISION
typedef int a;
#else
typedef int a;
#endif

// Matrix4x4
#ifdef SOFTWARE_RENDERER_USE_DOUBLE_PRECISION
typedef int a;
#else
typedef int a;
#endif
} // namespace SoftwareRenderer