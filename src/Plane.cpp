#include "Plane.h"

Plane Plane::normalized() const
{
    float magnitude = m_normal.length();

    return Plane(m_normal/magnitude, m_distance/magnitude);
}

Intersection Plane::IntersectCircle(const BoundingCircle& other) const
{
    float distanceFromCircleCenter = fabs(m_normal.dot(other.getCenter()) + m_distance);
    float distanceFromCircle = distanceFromCircleCenter - other.getRadius();
    return Intersection(distanceFromCircle < 0, m_normal * distanceFromCircle);
}