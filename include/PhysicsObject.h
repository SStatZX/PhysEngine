#pragma once

#include "MathPhys.h"
#include "BoundingCircle.h"
#include <SFML/System/Vector2.hpp>
class PhysicsObject
{
public:
    PhysicsObject(const Vector2& pos, const Vector2& vel, float rad) : // Constructor with member variables
        m_position(pos),
        m_velocity(vel),
        m_radius(rad) { }

    void Integrate(float delta, const Vector2& force);
    
    inline const sf::Vector2f getRenderPosition() { // Circle gets rendered from the top left corner,
        sf::Vector2f returnv(m_position.x - m_radius, m_position.y - m_radius); // to account for this error 
        return returnv;                              // adjust position given to renderer by amount of radius
    }
    inline const Vector2& getPosition() { return m_position; } // Getters
    inline const Vector2& getVelocity() { return m_velocity; }
    inline float getRadius() const { return m_radius; }
    inline BoundingCircle getBoundingCircle() const
    {
        return BoundingCircle(m_position, m_radius);
    }
    inline void setVelocity(const Vector2& velocity) { m_velocity = velocity; } // Setter for velocity
private:
    Vector2 m_position;
    Vector2 m_velocity;
    float m_radius;
};
