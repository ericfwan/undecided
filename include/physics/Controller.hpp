#pragma once
#include <SFML/Graphics.hpp>
#include "physics/RigidBody.hpp"

class Controller {
public:
    Controller() = default;

    // Set the platform to control
    void setPlatform(Physics::RigidBody* platform);

    // Call this every frame
    void update(float dt, float windowWidth, float windowHeight);

private:
    Physics::RigidBody* platform = nullptr;
};
