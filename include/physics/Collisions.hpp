#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <functional>
#include <cmath>
namespace Physics {
    class RigidBody;
    class Collisions {
    public:



        explicit Collisions(const sf::Vector2f gravity = {0.0f, 980.f}, const float bounceFactor = 10.f)
            : gravity(gravity), bounceFactor(bounceFactor){}

        struct CollisionInfo {
            RigidBody* other{};           // The other body involved
            sf::Vector2f normal;        // Collision normal (direction)
            float penetration{};          // How deep the overlap is
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
        float bounceFactor;
        void checkCollisions(std::vector<RigidBody*>& bodies);

    private:

        sf::Vector2f gravity;
        bool checkAABB(RigidBody* a, RigidBody* b);
        void resolveBallCollision(RigidBody* ball, RigidBody* other);



    };
}