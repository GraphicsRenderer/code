#pragma once

#include "utility.h"

namespace SoftwareRenderer {
#define VECTOR_LIKE_OPERATOR_ADD(Type, Size)                \
    static Type operator+(const Type& lhs, const Type& rhs) \
    {                                                       \
        Type ret;                                           \
        ELEMENT_WISE_OP(ret, lhs, rhs, Size, +);            \
        return ret;                                         \
    }

#define VECTOR_LIKE_OPERATOR_SUB(Type, Size)                \
    static Type operator-(const Type& lhs, const Type& rhs) \
    {                                                       \
        Type ret;                                           \
        ELEMENT_WISE_OP(ret, lhs, rhs, Size, -);            \
        return ret;                                         \
    }

#define VECTOR_LIKE_OPERATOR_MUL(Type, Size)                 \
    static Type operator*(const Type& lhs, const Type& rhs)  \
    {                                                        \
        Type ret;                                            \
        ELEMENT_WISE_OP(ret, lhs, rhs, Size, *);             \
        return ret;                                          \
    }                                                        \
                                                             \
    static Type operator*(const Type& lhs, const float& rhs) \
    {                                                        \
        Type ret;                                            \
        ELEMENT_WISE_SCALAR_OP(ret, lhs, rhs, Size, *);      \
        return ret;                                          \
    }                                                        \
                                                             \
    static Type operator*(const float& lhs, const Type& rhs) \
    {                                                        \
        Type ret;                                            \
        ELEMENT_WISE_SCALAR_OP(ret, rhs, lhs, Size, *);      \
        return ret;                                          \
    }

#define VECTOR_LIKE_OPERATOR_DIV(Type, Size)                 \
    static Type operator/(const Type& lhs, const Type& rhs)  \
    {                                                        \
        Type ret;                                            \
        ELEMENT_WISE_OP(ret, lhs, rhs, Size, /);             \
        return ret;                                          \
    }                                                        \
                                                             \
    static Type operator/(const Type& lhs, const float& rhs) \
    {                                                        \
        Type ret;                                            \
        ELEMENT_WISE_SCALAR_OP(ret, lhs, rhs, Size, /);      \
        return ret;                                          \
    }                                                        \
                                                             \
    static Type operator/(const float& lhs, const Type& rhs) \
    {                                                        \
        Type ret;                                            \
        ELEMENT_WISE_SCALAR_OP(ret, rhs, lhs, Size, /);      \
        return ret;                                          \
    }

#pragma region Color

struct Color {
    char r;
    char g;
    char b;
    char a;

    explicit Color()
        : Color(0, 0, 0, 255)
    {
    }

    explicit Color(char c)
        : Color(c, c, c, 255)
    {
    }

    explicit Color(char r, char g, char b)
        : Color(r, g, b, 255)
    {
    }

    explicit Color(char r, char g, char b, char a)
        : r(r)
        , g(g)
        , b(b)
        , a(a)
    {
    }

    static inline Color White() { return Color(255, 255, 255); }

    static inline Color Black() { return Color(0, 0, 0); }

    static inline Color Red() { return Color(255, 0, 0); }

    static inline Color Green() { return Color(0, 255, 0); }

    static inline Color Blue() { return Color(0, 0, 255); }

    inline std::size_t Length() const
    {
        return 4;
    }

    inline char& operator[](std::size_t idx)
    {
        switch (idx) {
        case 0:
            return r;
        case 1:
            return g;
        case 2:
            return b;
        case 3:
            return a;
        default:
            return r;
        }
    }

    inline const char& operator[](std::size_t idx) const
    {
        switch (idx) {
        case 0:
            return r;
        case 1:
            return g;
        case 2:
            return b;
        case 3:
            return a;
        default:
            return r;
        }
    }
};

VECTOR_LIKE_OPERATOR_ADD(Color, 4);

VECTOR_LIKE_OPERATOR_SUB(Color, 4);

VECTOR_LIKE_OPERATOR_MUL(Color, 4);

VECTOR_LIKE_OPERATOR_DIV(Color, 4);

#pragma endregion

#pragma region Vec2

template <typename DATATYPE>
struct Vec2 {
    DATATYPE x;
    DATATYPE y;

    explicit Vec2()
        : Vec2(0, 0)
    {
    }

    explicit Vec2(DATATYPE v)
        : Vec2(v, v)
    {
    }

    explicit Vec2(DATATYPE x, DATATYPE y)
        : x(x)
        , y(y)
    {
    }

    inline std::size_t Length() const
    {
        return 2;
    }

    inline DATATYPE& operator[](std::size_t idx)
    {
        switch (idx) {
        case 0:
            return x;
        case 1:
            return y;
        default:
            return x;
        }
    }

    inline const DATATYPE& operator[](std::size_t idx) const
    {
        switch (idx) {
        case 0:
            return x;
        case 1:
            return y;
        default:
            return x;
        }
    }
};

typedef Vec2<int> Vec2i;

typedef Vec2<float> Vec2f;

VECTOR_LIKE_OPERATOR_ADD(Vec2i, 2);

VECTOR_LIKE_OPERATOR_SUB(Vec2i, 2);

VECTOR_LIKE_OPERATOR_MUL(Vec2i, 2);

VECTOR_LIKE_OPERATOR_DIV(Vec2i, 2);

VECTOR_LIKE_OPERATOR_ADD(Vec2f, 2);

VECTOR_LIKE_OPERATOR_SUB(Vec2f, 2);

VECTOR_LIKE_OPERATOR_MUL(Vec2f, 2);

VECTOR_LIKE_OPERATOR_DIV(Vec2f, 2);

#pragma endregion

#pragma region Vec3

template <typename DATATYPE>
struct Vec3 {
    DATATYPE x;
    DATATYPE y;
    DATATYPE z;

    explicit Vec3()
        : Vec3(0, 0, 0)
    {
    }

    explicit Vec3(DATATYPE v)
        : Vec3(v, v, v)
    {
    }

    explicit Vec3(DATATYPE x, DATATYPE y, DATATYPE z)
        : x(x)
        , y(y)
        , z(z)
    {
    }

    inline std::size_t Length() const
    {
        return 3;
    }

    inline DATATYPE& operator[](std::size_t idx)
    {
        switch (idx) {
        case 0:
            return x;
        case 1:
            return y;
        case 2:
            return z;
        default:
            return x;
        }
    }

    inline const DATATYPE& operator[](std::size_t idx) const
    {
        switch (idx) {
        case 0:
            return x;
        case 1:
            return y;
        case 2:
            return z;
        default:
            return x;
        }
    }
};

typedef Vec3<int> Vec3i;

typedef Vec3<float> Vec3f;

VECTOR_LIKE_OPERATOR_ADD(Vec3i, 3);

VECTOR_LIKE_OPERATOR_SUB(Vec3i, 3);

VECTOR_LIKE_OPERATOR_MUL(Vec3i, 3);

VECTOR_LIKE_OPERATOR_DIV(Vec3i, 3);

VECTOR_LIKE_OPERATOR_ADD(Vec3f, 3);

VECTOR_LIKE_OPERATOR_SUB(Vec3f, 3);

VECTOR_LIKE_OPERATOR_MUL(Vec3f, 3);

VECTOR_LIKE_OPERATOR_DIV(Vec3f, 3);

#pragma endregion

#pragma region Vec4

template <typename DATATYPE>
struct Vec4 {
    DATATYPE x;
    DATATYPE y;
    DATATYPE z;
    DATATYPE w;

    explicit Vec4()
        : Vec4(0, 0, 0, 0)
    {
    }

    explicit Vec4(DATATYPE v)
        : Vec4(v, v, v, v)
    {
    }

    explicit Vec4(DATATYPE x, DATATYPE y, DATATYPE z, DATATYPE w)
        : x(x)
        , y(y)
        , z(z)
        , w(w)
    {
    }

    inline std::size_t Length() const
    {
        return 3;
    }

    inline DATATYPE& operator[](std::size_t idx)
    {
        switch (idx) {
        case 0:
            return x;
        case 1:
            return y;
        case 2:
            return z;
        case 3:
            return w;
        default:
            return x;
        }
    }

    inline const DATATYPE& operator[](std::size_t idx) const
    {
        switch (idx) {
        case 0:
            return x;
        case 1:
            return y;
        case 2:
            return z;
        case 3:
            return w;
        default:
            return x;
        }
    }
};

typedef Vec4<int> Vec4i;

typedef Vec4<float> Vec4f;

VECTOR_LIKE_OPERATOR_ADD(Vec4i, 4);

VECTOR_LIKE_OPERATOR_SUB(Vec4i, 4);

VECTOR_LIKE_OPERATOR_MUL(Vec4i, 4);

VECTOR_LIKE_OPERATOR_DIV(Vec4i, 4);

VECTOR_LIKE_OPERATOR_ADD(Vec4f, 4);

VECTOR_LIKE_OPERATOR_SUB(Vec4f, 4);

VECTOR_LIKE_OPERATOR_MUL(Vec4f, 4);

VECTOR_LIKE_OPERATOR_DIV(Vec4f, 4);

#pragma endregion
} // namespace SoftwareRenderer