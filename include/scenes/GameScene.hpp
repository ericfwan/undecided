#pragma once
#include "Scene.hpp"
#include "physics/RigidBody.hpp"
#include "physics/Collisions.hpp"
#include <SFML/Graphics.hpp>

class GameScene : public Scene {
public:
    GameScene(Game& game);
    Physics::Collisions physics;

    Physics::RigidBody platform = Physics::RigidBody({30.f, 70.f}, {50.f, 10.f});
    Physics::RigidBody ball = Physics::RigidBody({30.f, 20.f}, 6.f);
    sf::Vector2f gravity = physics.get_Gravity();

    void handleEvent(sf::Event& event) override;
    void update(float dt) override;
    void draw(sf::RenderWindow& window) override;

private:

    // Window bounds (read once from Game)
    float windowWidth;
    float windowHeight;

    // Helpers
    void handleWallCollision();
    void handlePlatformCollision();
};
