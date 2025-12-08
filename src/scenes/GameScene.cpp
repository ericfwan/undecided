#include "scenes/GameScene.hpp"
#include "Game.hpp"
#include "physics/Collisions.hpp"
#include "physics/RigidBody.hpp"
#include <cmath>

GameScene::GameScene(Game& game)
: Scene(game),
physics(),
platform({30.f, 70.f}, {10.f, 5.f}),
ball({30.f, 20.f}, 2.f)
{

    windowWidth = static_cast<float>(game.window.getSize().x);
    windowHeight = static_cast<float>(game.window.getSize().y);
    sf::Vector2f gravity = physics.get_Gravity();

    // Ball setup


    ball.setPosition({windowWidth / 2.f, 120.f});
    ball.velocity = {150.f, 0.f};

    // Platform setup
    platform.setColour(sf::Color::White);
    platform.setPosition({windowWidth / 2.f, windowHeight - 100.f});
}


void GameScene::update(float dt) {
    // Gravity
    ball.velocity.y += physics.get_Gravity().y * dt;

    // Move ball
    ball.move(ball.velocity * dt);

    // Collisions
    handleWallCollision();


    platform.update(dt);
    ball.update(dt);
    platform.updateAABB();
    ball.updateAABB();
    // Keyboard rotation
    const float rotSpeed = 250.f;
}
void GameScene::handleWallCollision() {
    sf::Vector2f pos = ball.getPosition();
    float r = ball.getRadius();

    // Left
    if (pos.x - r < 0.f) {
        ball.setPosition({r, pos.y});
        ball.velocity.x = std::abs(ball.velocity.x);
    }

    // Right
    if (pos.x + r > windowWidth) {
        ball.setPosition({windowWidth - r, pos.y});
        ball.velocity.x = -std::abs(ball.velocity.x);
    }

    // Top
    if (pos.y - r < 0.f) {
        ball.setPosition({pos.x, r});
        ball.velocity.y = std::abs(ball.velocity.y);
    }

    // Bottom (soft bounce)
    if (pos.y + r > windowHeight) {
        ball.setPosition({pos.x, windowHeight - r});
        ball.velocity.y = -std::abs(ball.velocity.y) * physics.bounceFactor;
    }
}


void GameScene::draw(sf::RenderWindow& window) {
    platform.draw(window);
    ball.draw(window);
}

