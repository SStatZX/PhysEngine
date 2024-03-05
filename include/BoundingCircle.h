#pragma once

#include "MathPhys.h"

class BoundingCircle 
{
public:
    BoundingCircle(const Vector2& center, float radius) :
        m_center(center), m_radius(radius) {}

    inline const Vector2& GetCenter() { return m_center; }
    inline float GetRadius() const { return m_radius; }
private:
    float m_radius;
    Vector2 m_center;
};