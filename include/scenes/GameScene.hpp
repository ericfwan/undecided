#pragma once
#include "Scene.hpp"
#include "physics/RigidBody.hpp"
#include "physics/Collisions.hpp"
#include <SFML/Graphics.hpp>

class GameScene : public Scene {
public:
    GameScene(Game& game);

    void update(float dt) override;
    void draw(sf::RenderWindow& window) override;

private:
    Physics::RigidBody ball;
    Physics::RigidBody platform;
    Physics::Collisions physics;


    float windowWidth;
    float windowHeight;

    void handleWallCollision();
};
