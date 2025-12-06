#pragma once
#include "Scene.hpp"
#include <SFML/Graphics.hpp>

class GameScene : public Scene {
public:
    GameScene(Game& game);

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

    // Window bounds (read once from Game)
    float windowWidth;
    float windowHeight;

    void handleWallCollision();
    void handlePlatformCollision();
};
