#include "imgui.h"
#include "imgui-SFML.h"
#include <iostream>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include "PhysicsEngine.h"
void BoundingCircleTest();

int main() {
    // BoundingCircleTest();
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Simple Physics Engine");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

    sf::Clock deltaClock;

    PhysicsEngine physicsEngine; // Create PhysicsEngine object

    float simSpeed = 0.1f; // User variables, default values / definitions
    float grav = 0.1f;
    float CoR = 0.95;
    float circleSize = 50.0f;
    float circleVel[2] = {0.0f, 2.0f};
    bool special = false;

    physicsEngine.AddObject(PhysicsObject(
        Vector2(480.0f, 600.0f), Vector2(0.0f, -1.0f), 50.0f)); // Create first object.

    while (window.isOpen()) { // Main loop
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
                            // Add physics object on right click at mouse position.
                            Vector2(mousePosition.x, mousePosition.y), Vector2(circleVel[0], circleVel[1]), circleSize)); 
            }
        }

        ImGui::SFML::Update(window, elapsed);

        ImGui::Begin("Tools"); // GUI Code, create buttons / sliders changes user variables
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

        window.clear(); // Clear window before rendering
        physicsEngine.HandleCollisions((double)CoR); // Handle Collision for physics engine, pass in Coefficient of Restitution as a double
        physicsEngine.Simulate(simSpeed, grav * Vector2(0.0f, +1.0f)); // Gravity is a float, times by a vector which is direction of gravity
        physicsEngine.Render(window, special); // Pass RenderWindow window by reference (pointer) with bool special as well for render type
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
}

void BoundingCircleTest() {
    Vector2 banana(2.0F, 3.0F);
    Vector2 apple(3.0F, -2.0F);

    BoundingCircle c1(banana, 4.0);
    BoundingCircle c2(apple, 3.0);

    Intersection inter = c1.getIntersection(c2);

    std::cout << "Bounding?: " << inter.to_string() << std::endl;
}