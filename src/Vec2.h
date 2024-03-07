#ifndef VEC2_H
#define VEC2_H

#include <math.h>
#include <iostream>

template <typename T>
class Vec2
{
public:
    T x = 0;
    T y = 0;
    Vec2() {};
    Vec2(float xin, float yin) : x(xin), y(yin) {};

    Vec2& operator = (const Vec2& v)
    {
        x = v.x;
        y = v.y;

        return *this;
    }

    Vec2 operator + (Vec2& v)
    {
        return Vec2(x+v.x, y+v.y);
    }

    Vec2 operator - (Vec2& v)
    {
        return Vec2(x-v.x, y-v.y);
    }

    Vec2& operator += (Vec2& v)
    {
        x += v.x;
        y += v.y;
        return *this;
    }

    Vec2& operator -= (Vec2& v)
    {
        x -= v.x;
        y -= v.y;
        return *this;
    }

    Vec2 operator * (float s)
    {
        return Vec2(x*s, y*s);
    }

    Vec2 operator / (float s)
    {
        return Vec2(x/s, y/s);
    }

    Vec2& operator += (float s)
    {
        x += s;
        y += s;
        return *this;
    }

    Vec2& operator -= (float s)
    {
        x -= s;
        y -= s;
        return *this;
    }

    Vec2& operator *= (float s)
    {
        x *= s;
        y *= s;
        return *this;
    }

    Vec2& operator /= (float s)
    {
        x /= s;
        y /= s;
        return *this;
    }

    friend std::ostream& operator << (std::ostream& os, const Vec2& v)
    {
        os << "x = " << v.x << " y = " << v.y << "\n";
        return os;
    }

    Vec2& add(Vec2 v)
    {
        x = x + v.x;
        y = y + v.y;
        return *this;
    }

    float dist(Vec2 v) const
    {
        Vec2 d(x-v.x, y-v.y);
        return d.length();
    }

    // or magnitude
    float length()
    {
        return sqrtf(x*x + y*y);
    }

    Vec2& scale(float s)
    {
        x *= s;
        y *= s;
        return *this;
    }

    void set(float x, float y)
    {
        this->x = x;
        this->y = y;
    }

    void rotate(float deg)
    {
        float theta = deg / 180.0 * M_PI;
        float c = cos(theta);
        float s = sin(theta);
        float tx = x * c - y * s;
        float ty = x * s + y * c;
        x = tx;
        y = ty;
    }

    // unit vector
    Vec2& normalize()
    {
        if (length() == 0) return *this;
        *this *= (1.0 / length()); // x / length(), y / length()
        return *this;
    }

    void truncate(float length)
    {
        float angle = atan2f(y, x);
        x = length * cos(angle);
        y = length * sin(angle);
    }

    // orthogonal
    Vec2 ortho() const
    {
        return Vec2(y, -x);
    }

    static float dot(Vec2 v1, Vec2 v2)
    {
        return (v1.x * v2.x) + (v1.y * v2.y);
    }

    static float cross(Vec2 v1, Vec2 v2)
    {
        return (v1.x * v2.y) - (v1.y * v2.x);
    }

};

using Vec2f = Vec2<float>;
using Vec2d = Vec2<double>;

#endif