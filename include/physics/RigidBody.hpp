#pragma once
#include "physics/Collisions.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>
namespace Physics {
    class RigidBody {
    public:

        enum class ShapeType {
            Circle,
            Rectangle
        };


        ShapeType type;
        sf::Vector2f position;
        sf::Vector2f size;      // for rectangles
        float radius;            // for circles
        sf::Vector2f velocity;

        // Constructor for rectangle
        RigidBody(sf::Vector2f pos, sf::Vector2f sz)
            : type(ShapeType::Rectangle), position(pos), size(sz), velocity(0.f, 0.f) {}

        // Constructor for circle
        RigidBody(sf::Vector2f pos, float r)
            : type(ShapeType::Circle), position(pos), radius(r), velocity(0.f, 0.f) {}

        Collisions::AABB aabb;

        void updateAABB();
        void draw(sf::RenderWindow& window) const;
        void setOrigin(sf::Vector2f origin);
        void update(float dt);
    };
}