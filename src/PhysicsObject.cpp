#include "PhysicsObject.h"

void PhysicsObject::Integrate(float delta, const Vector2& force)
{
    m_position += m_velocity * delta;
    m_velocity += force;
}