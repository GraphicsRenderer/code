#pragma once

// #define CONFIG_USE_DOUBLE_PRECISION

inline bool ConfigUseDoublePrecision() {
#ifdef CONFIG_USE_DOUBLE_PRECISION
  return true;
#else
  return false;
#endif
}