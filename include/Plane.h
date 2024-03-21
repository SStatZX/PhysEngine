#pragma once

#include "MathPhys.h"
#include "BoundingCircle.h"

class Plane
{
public:
    Plane(const Vector2& normal, float distance) :
        m_normal(normal),
        m_distance(distance) {}

    Plane normalized() const;
    Intersection IntersectCircle(const BoundingCircle& other) const;

    inline const Vector2& getNormal() const { return m_normal; }
    inline float getDistance() const { return m_distance; }
private:
    const Vector2 m_normal;
    const float m_distance;
};