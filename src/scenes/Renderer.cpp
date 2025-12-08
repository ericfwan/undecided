#include "physics/RigidBody.hpp"
#include "scenes/Renderer.hpp"
#include <vector>
#include <SFML/Graphics.hpp>


    void Renderer::render(sf::RenderWindow& window, const std::vector<Physics::RigidBody*>& objects) {
        for (const auto& body : objects) {
            if (body->type == Physics::RigidBody::ShapeType::Rectangle) {
                sf::RectangleShape rect(body->size);
                rect.setOrigin(body->size.x / 2.f, body->size.y / 2.f);
                rect.setPosition(body->position);
                rect.setRotation(body->rotation);  // <-- ADD THIS
                rect.setFillColor(sf::Color::White);
                window.draw(rect);
            } else if (body->type == Physics::RigidBody::ShapeType::Circle) {
                sf::CircleShape circ(body->radius);
                circ.setOrigin(body->radius, body->radius);
                circ.setPosition(body->position);
                circ.setRotation(body->rotation);  // <-- ADD THIS
                circ.setFillColor(sf::Color::White);
                window.draw(circ);
            }
        }
    }


