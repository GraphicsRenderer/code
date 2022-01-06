#pragma once

#define FUNC_ALISE(highLevelF, lowLevelF)                                      \
  template <typename... Args>                                                  \
  inline auto highLevelF(Args &&... args)                                      \
      ->decltype(lowLevelF(std::forward<Args>(args)...)) {                     \
    return lowLevelF(std::forward<Args>(args)...);                             \
  }
