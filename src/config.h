#pragma once

#define SOFTWARE_RENDERER_DISABLE_NEW_DELETE()                                 \
  void *operator new(size_t) = delete;                                         \
  void *operator new[](size_t) = delete;                                       \
  void operator delete(void *) = delete;                                       \
  void operator delete[](void *) = delete;
