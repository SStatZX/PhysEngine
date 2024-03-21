#include "imgui.h"
#include "imgui-SFML.h"
#include <iostream>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include "PhysicsEngine.h"


int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Simple Physics Engine");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

    sf::Clock deltaClock;

    PhysicsEngine physicsEngine;

    float simSpeed = 0.1f;
    float grav = 0.1f;
    float CoR = 0.95;
    float circleSize = 50.0f;
    float circleVel[2] = {0.0f, 2.0f};
    bool special = false;

    physicsEngine.AddObject(PhysicsObject(
        Vector2(480.0f, 600.0f), Vector2(0.0f, -1.0f), 50.0f));
    // physicsEngine.AddObject(PhysicsObject(
    //     Vector2(400.0f, 200.0f), Vector2(0.0f, 1.595f), 100.0f));
    // physicsEngine.AddObject(PhysicsObject(
    //     Vector2(800.0f, 200.0f), Vector2(-1.0f, 0.0f), 100.0f));
    while (window.isOpen()) {
        sf::Event event;
        sf::Time elapsed = deltaClock.restart();
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(window, event);
            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonReleased:
                    if (event.key.code == sf::Mouse::Right)
                        physicsEngine.AddObject(PhysicsObject(
                            Vector2(mousePosition.x, mousePosition.y), Vector2(circleVel[0], circleVel[1]), circleSize));
            }
        }

        ImGui::SFML::Update(window, elapsed);

        // ImGui::ShowDemoWindow();

        ImGui::Begin("Tools");
        if (ImGui::Button("This spawns a circle."))
            physicsEngine.AddObject(PhysicsObject(
        Vector2(400.0f, 200.0f), Vector2(0.0f, 1.595f), 100.0f));
        if (ImGui::Button("Destroy all Objects."))
            physicsEngine.DeleteAll();
        ImGui::SliderFloat("Simulation Speed", &simSpeed, 0.0f, 1.0f);
        ImGui::SliderFloat("Force of Gravity", &grav, 0.0f, 1.0f);
        ImGui::SliderFloat("Coefficient of Restitution", &CoR, 0.8f, 1.5f);
        ImGui::SliderFloat("Spawn Circle Size (Right Click)", &circleSize, 1.0f, 500.0f);
        ImGui::InputFloat2("Spawn Circle Velocity", circleVel);
        ImGui::Checkbox("Don't Press!", &special);
        ImGui::End();

        window.clear();
        // window.draw();
        physicsEngine.Simulate(simSpeed, grav * Vector2(0.0f, +1.0f));
        physicsEngine.HandleCollisions((double)CoR);
        physicsEngine.Render(window, special);
        // window.draw(sf::CircleShape(50.0f));
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
}