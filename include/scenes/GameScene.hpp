#pragma once
#include <Scene.hpp>

#include "scenes/GameScene.hpp"
#include <SFML/Graphics.hpp>

class GameScene : public Scene {
public:
    GameScene();

    float deltaTime;
    void handleEvent(sf::Event& event) override;
    void update(float dt) override;
    void draw(sf::RenderWindow& window) override;

private:
    // Ball
    sf::CircleShape ball;
    sf::Vector2f ballVelocity;

    // Platform
    sf::RectangleShape platform;

    // Physics constants
    float gravity;
    float bounceFactor;
    float platformSpeed;

    // Window bounds
    float windowWidth;
    float windowHeight;

    // Helper functions
    void handleWallCollision();
    void handlePlatformCollision();
};
