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
        float radius{};            // for circles
        sf::Vector2f velocity;
        sf::Vector2f origin = size/2.f;
        sf::Color colour;
        float rotation;
        float angularVelocity; // degrees per second





        // Constructor for rectangle
        RigidBody(sf::Vector2f pos, sf::Vector2f sz)
            : type(ShapeType::Rectangle), position(pos), size(sz), velocity(0.f, 0.f) {}

        // Constructor for circle
        RigidBody(sf::Vector2f pos, float r)
            : type(ShapeType::Circle), position(pos), radius(r), velocity(0.f, 0.f) {}

        Collisions::AABB aabb;

        void updateAABB();
        void draw(sf::RenderWindow& window) const;
        void setColour(sf::Color colour);
        void setSize(sf::Vector2f size);
        void setOrigin();
        void setPosition(sf::Vector2f pos);
        void setRotation(float angle);
        sf::Vector2f getSize() const;
        sf::Vector2f getPosition() const;
        float getRadius() const;

        void move(const sf::Vector2f& offset);
        void move(float x, float y);

        void rotate(float angle);
        float getRotation() const;

        void checkCollisions(std::vector<RigidBody*>& bodies);


        void update(float dt);
    };
}