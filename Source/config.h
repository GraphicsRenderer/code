#pragma once

// #define SOFTWARE_RENDERER_USE_DOUBLE_PRECISION

namespace SoftwareRenderer {
inline bool ConfigUseDoublePrecision() {
#ifdef SOFTWARE_RENDERER_USE_DOUBLE_PRECISION
  return true;
#else
  return false;
#endif
}
} // namespace SoftwareRenderer
