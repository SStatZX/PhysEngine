#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include "PhysicsEngine.h"
#include "BoundingCircle.h"
#include <iostream>

void PhysicsEngine::AddObject(const PhysicsObject& object)
{
    m_objects.push_back(object);
}

void PhysicsEngine::Simulate(float delta, const Vector2& force)
{
    for(uint i = 0; i < m_objects.size(); i++)
    {
        m_objects[i].Integrate(delta, force);
    }
}

void PhysicsEngine::HandleCollisions(double CoR)
{
    for(uint i = 0; i < m_objects.size(); i++)
    {
        if(m_objects[i].getPosition().x - m_objects[i].getRadius() <= 0)
        {
            m_objects[i].setVelocity(
                Vector2(m_objects[i].getVelocity().reflect(Vector2(1.0f, 0.0f)) * CoR) 
            );
        }
        if(m_objects[i].getPosition().x + m_objects[i].getRadius() >= 1920)
        {
            m_objects[i].setVelocity(
                Vector2(m_objects[i].getVelocity().reflect(Vector2(-1.0f, 0.0f)) * CoR) 
            );
        }
        if(m_objects[i].getPosition().y - m_objects[i].getRadius() <= 0)
        {
            m_objects[i].setVelocity(
                Vector2(m_objects[i].getVelocity().reflect(Vector2(0.0f, -1.0f)) * CoR) 
            );
        }
        if(m_objects[i].getPosition().y + m_objects[i].getRadius() >= 1080)
        {
            m_objects[i].setVelocity(
                Vector2(m_objects[i].getVelocity().reflect(Vector2(0.0f, 1.0f)) * CoR) 
            );
        }
        for(uint j = i+1; j < m_objects.size(); j++)
        {
            Intersection intersection =
                m_objects[i].getBoundingCircle().getIntersection(
                    m_objects[j].getBoundingCircle());
            if(intersection.doesIntersect())
            {
                Vector2 direction = intersection.getDistance();
                direction.normalize();
                Vector2 otherDirection(direction.reflect(m_objects[i].getVelocity()));
                otherDirection.normalize();
                m_objects[i].setVelocity(
                    Vector2(m_objects[i].getVelocity().reflect(otherDirection) * CoR)
                );
                m_objects[j].setVelocity(
                    Vector2(m_objects[j].getVelocity().reflect(direction) * CoR)
                );
            }
        }

    }
}

void PhysicsEngine::Render(sf::RenderWindow& window, bool special)
{
    sf::Texture texture;
    texture.loadFromFile( "../res/dvd.png" );
    for(uint f = 0; f < m_objects.size(); f++)
    {
        if (!special)
        {
            sf::CircleShape circle(m_objects[f].getRadius());
            circle.setPosition(m_objects[f].getRenderPosition());
            circle.setFillColor(sf::Color(40, 0, 2*m_objects[f].getRadius(), 255));
            window.draw(circle);
            // std::cout << "Drawed! \n";
        } else {
            sf::Sprite sprite;
            sprite.setTexture(texture);
            sprite.scale(0.1, 0.1);
            sprite.setPosition(m_objects[f].getRenderPosition());
            // sprite.setColor(sf::Color());
            window.draw(sprite);
        }
    }
}