#pragma once

#include <algorithm>

#define FUNC_ALISE(highLevelF, lowLevelF)                  \
    template <typename... Args>                            \
    inline auto highLevelF(Args&&... args)                 \
        ->decltype(lowLevelF(std::forward<Args>(args)...)) \
    {                                                      \
        return lowLevelF(std::forward<Args>(args)...);     \
    }

#define DISABLE_NEW_DELETE()               \
    void* operator new(size_t) = delete;   \
    void* operator new[](size_t) = delete; \
    void operator delete(void*) = delete;  \
    void operator delete[](void*) = delete;

static inline bool IsFloatEqual(float a, float b)
{
    return std::abs(a - b) < 0.0001f;
}

#define ELEMENT_WISE_ASSIGN(ret, val, size) \
    for (auto i = 0; i < size; i++) {       \
        ret[i] = val;                       \
    }

#define ELEMENT_WISE_SCALAR_OP(ret, lhs, rhs, size, op) \
    for (auto i = 0; i < size; i++) {                   \
        ret[i] = lhs[i] op rhs;                         \
    }

#define ELEMENT_WISE_OP(ret, lhs, rhs, size, op) \
    for (auto i = 0; i < size; i++) {            \
        ret[i] = lhs[i] op rhs[i];               \
    }
