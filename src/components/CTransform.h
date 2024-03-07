#ifndef CTRANSFORM_H
#define CTRANSFORM_H

#include "../Vec2.h"

class CTransform
{
public:
    Vec2f position = {0, 0};
    Vec2f velocity = {0, 0};
    Vec2f acceleration = {0, 0};
    CTransform() {};
    CTransform(const Vec2f& p, const Vec2f& v, const Vec2f& a)
    : position(p), velocity(v), acceleration(a) {};
};

#endif