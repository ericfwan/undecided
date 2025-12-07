#pragma once
#include "physics/RigidBody.hpp"
#include <vector>
#include <SFML/Graphics.hpp>

class Renderer {
public:
    void render(sf::RenderWindow& window, const std::vector<Physics::RigidBody*>& objects);
};
