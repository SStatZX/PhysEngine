#pragma once

#include "MathPhys.h"

class Intersection
{
public:
    Intersection(const bool colliding, const Vector2& distance) :
        m_Colliding(colliding), m_Distance(distance) {}

    inline bool doesIntersect() const { return m_Colliding; }
    inline const Vector2& getDistance() const { return m_Distance; }

    std::string to_string() {
        return std::to_string(m_Colliding) + ", " + m_Distance.to_string();
    }
private:
    bool m_Colliding;
    Vector2 m_Distance;
};