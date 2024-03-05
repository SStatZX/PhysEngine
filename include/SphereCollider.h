#pragma once

#include "MathPhys.h"

class BoundingSphere
{
public:
    BoundingSphere(const Vector3& center, float radius) :
        m_center(center), m_radius(radius) {}

    inline Vector3 GetCenter() const { return m_center; }
    inline float GetRadius() const { return m_radius; }
private:
    Vector3 m_center;
    float m_radius;
};