#pragma once

#include "MathPhys.h"
#include "BoundingCircle.h"
#include <SFML/System/Vector2.hpp>

class Entity
{
public:
    Entity(BoundingCircle c) : m_circle(c) { } 

    inline sf::Vector2f getNormalisedCenter() {
        Vector2 pos = m_circle.getCenter();
        float radius = m_circle.getRadius();
        pos.normalize();
        return sf::Vector2f((pos.x*1920) - radius, (pos.y*1080) - radius);
    }

    inline Vector2 normal()
    {
        Vector2 circ = m_circle.getCenter();
        circ.normalize();
        return circ;
    }
private:
    BoundingCircle m_circle;
};