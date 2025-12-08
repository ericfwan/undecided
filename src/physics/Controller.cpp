#include "physics/Controller.hpp"

#include <iostream>
#include <SFML/Window/Keyboard.hpp>

void Controller::setPlatform(Physics::RigidBody* p) {
    platform = p;
}

void Controller::update(float dt, float windowWidth, float windowHeight){
    if (!platform) return;


    float moveSpeed = 400.f; // pixels per second
    float rotSpeed  = 360.f; // degrees per second
    sf::Vector2f pos = platform->getPosition();
    float rotation = platform->getRotation();

    // Move horizontally
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        pos.x -= moveSpeed * dt;
        platform->updateAABB();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        pos.x += moveSpeed * dt;
        platform->updateAABB();
    }

    // Move vertically
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        pos.y -= moveSpeed * dt;
        platform->updateAABB();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        pos.y += moveSpeed * dt;
        platform->updateAABB();
    }

    // Clamp inside window
    float halfWidth  = platform->getSize().x / 2.f;
    float halfHeight = platform->getSize().y / 2.f;

    if (pos.x - halfWidth < 0.f) pos.x = halfWidth;
    if (pos.x + halfWidth > windowWidth) pos.x = windowWidth - halfWidth;
    if (pos.y - halfHeight < 0.f) pos.y = halfHeight;
    if (pos.y + halfHeight > windowHeight) pos.y = windowHeight - halfHeight;

    platform->setPosition(pos);

    // Rotation
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        rotation -= (rotSpeed * dt);
        platform->updateAABB();// rotate anti-clockwise
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        rotation += (rotSpeed * dt);
        platform->updateAABB();// rotate clockwise
    }

    platform->setRotation(rotation);
}
