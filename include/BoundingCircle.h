#pragma once

#include "MathPhys.h"
#include "Intersection.h"

class BoundingCircle 
{
public:
    BoundingCircle(const Vector2& center, float radius) :
        m_center(center), m_radius(radius) {}

    inline const Vector2& getCenter() const { return m_center; }
    inline float getRadius() const { return m_radius; }

    inline const Intersection getIntersection(const BoundingCircle& target) {
        float rDistance = m_radius + target.getRadius(); // r1 + r2 = rs
        Vector2 direction = (target.getCenter() - m_center); // v1 - v2 = vd
        float cDistance = direction.length(); // |vd|
        direction /= cDistance; // vd / |vd| = normalized form
        float distance = cDistance - rDistance; // |vd| - rs : difference in distance between centres and sum of radii

        return Intersection(distance < 0, direction * distance); /* if distance < 0 => |vd| < rs 
                                    i.e. distance between of centres is greater than 
                                    the distance between radii therefore intersecting
                                    direction * distance = direction with magnitude of difference in intersection
                                    hence if not touching ignore */
    }

private:
    float m_radius;
    Vector2 m_center;
};