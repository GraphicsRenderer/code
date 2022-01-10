#pragma once

#include "utility.h"

namespace SoftwareRenderer {
template <typename DATATYPE, int SIZE, typename SUBTYPE>
class VectorLike {
protected:
    DATATYPE _data[SIZE];

public:
    VectorLike() { ELEMENT_WISE_ASSIGN(_data, 0, SIZE); }

    inline int Size() const { return SIZE; }

    DISABLE_NEW_DELETE();

    inline SUBTYPE operator+(const SUBTYPE& rhs)
    {
        SUBTYPE value;
        ELEMENT_WISE_OP(value._data, _data, rhs._data, SIZE, +);
        return value;
    }

    inline SUBTYPE operator-(const SUBTYPE& rhs)
    {
        SUBTYPE value;
        ELEMENT_WISE_OP(value._data, _data, rhs._data, SIZE, -);
        return value;
    }

    inline SUBTYPE operator*(const SUBTYPE& rhs)
    {
        SUBTYPE value;
        ELEMENT_WISE_OP(value._data, _data, rhs._data, SIZE, *);
        return value;
    }

    inline SUBTYPE operator*(const DATATYPE& rhs)
    {
        SUBTYPE value;
        ELEMENT_WISE_SCALAR_OP(value._data, _data, rhs, SIZE, *);
        return value;
    }

    inline SUBTYPE operator/(const SUBTYPE& rhs)
    {
        SUBTYPE value;
        ELEMENT_WISE_OP(value._data, _data, rhs._data, SIZE, /);
        return value;
    }

    static inline SUBTYPE Zero()
    {
        SUBTYPE value;
        ELEMENT_WISE_ASSIGN(value._data, 0, SIZE);
        return value;
    }
};

class Color : public VectorLike<char, 4, Color> {
public:
    using VectorLike<char, 4, Color>::VectorLike;

    Color()
        : Color(0, 0, 0, 0)
    {
    }

    Color(char c)
        : Color(c, c, c, 255)
    {
    }

    Color(char r, char g, char b)
        : Color(r, g, b, 255)
    {
    }

    Color(char r, char g, char b, char a)
    {
        _data[0] = r;
        _data[1] = g;
        _data[2] = b;
        _data[3] = a;
    }

    inline char R() const { return _data[0]; }

    inline char G() const { return _data[1]; }

    inline char B() const { return _data[2]; }

    inline char A() const { return _data[3]; }

    static inline Color White() { return Color(255, 255, 255); }

    static inline Color Black() { return Color(0, 0, 0); }

    static inline Color Red() { return Color(255, 0, 0); }

    static inline Color Green() { return Color(0, 255, 0); }

    static inline Color Blue() { return Color(0, 0, 255); }
};

template <typename DATATYPE, int SIZE, typename SUBTYPE>
class Vector : public VectorLike<DATATYPE, SIZE, SUBTYPE> {
public:
    using VectorLike<DATATYPE, SIZE, SUBTYPE>::VectorLike;

    static inline SUBTYPE One()
    {
        SUBTYPE value;
        ELEMENT_WISE_ASSIGN(value._data, 1, SIZE);
        return value;
    }
};

template <typename DATATYPE, typename SUBTYPE>
class Vector2 : public VectorLike<DATATYPE, 2, SUBTYPE> {
public:
    using VectorLike<DATATYPE, 2, SUBTYPE>::VectorLike;

    Vector2(DATATYPE x, DATATYPE y)
    {
        VectorLike<DATATYPE, 2, SUBTYPE>::_data[0] = x;
        VectorLike<DATATYPE, 2, SUBTYPE>::_data[1] = y;
    }

    inline DATATYPE X() const
    {
        return VectorLike<DATATYPE, 2, SUBTYPE>::_data[0];
    }

    inline DATATYPE Y() const
    {
        return VectorLike<DATATYPE, 2, SUBTYPE>::_data[1];
    }
};

template <typename DATATYPE, typename SUBTYPE>
class Vector3 : public VectorLike<DATATYPE, 3, SUBTYPE> {
public:
    using VectorLike<DATATYPE, 3, SUBTYPE>::VectorLike;

    Vector3(DATATYPE x, DATATYPE y, DATATYPE z)
    {
        VectorLike<DATATYPE, 3, SUBTYPE>::_data[0] = x;
        VectorLike<DATATYPE, 3, SUBTYPE>::_data[1] = y;
        VectorLike<DATATYPE, 3, SUBTYPE>::_data[2] = z;
    }

    inline DATATYPE X() const
    {
        return VectorLike<DATATYPE, 3, SUBTYPE>::_data[0];
    }

    inline DATATYPE Y() const
    {
        return VectorLike<DATATYPE, 3, SUBTYPE>::_data[1];
    }

    inline DATATYPE Z() const
    {
        return VectorLike<DATATYPE, 3, SUBTYPE>::_data[1];
    }
};

class Vec2i : public Vector2<int, Vec2i> {
public:
    using Vector2<int, Vec2i>::Vector2;
};

class Vec2f : public Vector2<float, Vec2f> {
public:
    using Vector2<float, Vec2f>::Vector2;
};

class Vec3i : public Vector3<int, Vec3i> {
public:
    using Vector3<int, Vec3i>::Vector3;
};

class Vec3f : public Vector3<float, Vec3f> {
public:
    using Vector3<float, Vec3f>::Vector3;
};
} // namespace SoftwareRenderer