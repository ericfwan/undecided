#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <functional>
#include <cmath>
namespace Physics {
    class RigidBody;
    class Collisions {
    public:
        Collisions(sf::Vector2f gravity = {0.0f, 980.f})
            : gravity(gravity) {}

        struct CollisionInfo {
            RigidBody* other;           // The other body involved
            sf::Vector2f normal;        // Collision normal (direction)
            float penetration;          // How deep the overlap is
        };

        struct AABB {
            sf::Vector2f min;
            sf::Vector2f max;

            bool intersects(const AABB& other) const {
                return (min.x <= other.max.x && max.x >= other.min.x) &&
                       (min.y <= other.max.y && max.y >= other.min.y);
            }
        };

        sf::Vector2f get_Gravity() const;


    private:

        sf::Vector2f gravity;


    };
}