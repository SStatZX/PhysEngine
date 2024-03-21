#pragma once

#include "PhysicsObject.h"
#include <vector>

class PhysicsEngine
{
public:
    PhysicsEngine() {}

    void AddObject(const PhysicsObject& object);
    void Simulate(float delta, const Vector2& force);
    void HandleCollisions(double CoE);
    void Render(sf::RenderWindow& window, bool special);
    inline void DeleteAll() { m_objects.clear(); }
private:
    std::vector<PhysicsObject> m_objects;
};