#pragma once

#include "MathPhys.h"

class BoundingCircle 
{
public:
    BoundingCircle(const Vector2& center, float radius) :
        m_center(center), m_radius(radius) {}

    inline const Vector2& getCenter() const { return m_center; }
    inline float getRadius() const { return m_radius; }

    inline const bool isColliding(const BoundingCircle& target) {
        return (m_center - target.getCenter()).length() < m_radius+target.getRadius();
    }

    inline float getDistance(const BoundingCircle& target) {
        return (m_center - target.getCenter()).length();
    }
private:
    float m_radius;
    Vector2 m_center;
};