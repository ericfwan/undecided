#include "scenes/GameScene.hpp"
#include "Game.hpp"
#include <cmath>

GameScene::GameScene(Game& game)
: Scene(game)
{
    windowWidth = static_cast<float>(game.window.getSize().x);
    windowHeight = static_cast<float>(game.window.getSize().y);

    gravity = 800.f;
    bounceFactor = 0.8f;
    platformSpeed = 500.f;

    // Ball setup
    ball.setRadius(15.f);
    ball.setFillColor(game.ballColor);

    ball.setOrigin(15.f, 15.f);
    ball.setPosition(windowWidth / 2.f, 120.f);
    ballVelocity = {150.f, 0.f};

    // Platform setup
    platform.setSize({150.f, 20.f});
    platform.setOrigin(75.f, 10.f);
    platform.setFillColor(sf::Color::White);
    platform.setPosition(windowWidth / 2.f, windowHeight - 100.f);
}

void GameScene::handleEvent(sf::Event& event) {
    // Mouse control
    if (event.type == sf::Event::MouseMoved) {
        float mouseX = static_cast<float>(event.mouseMove.x);

        float half = platform.getSize().x / 2.f;
        if (mouseX < half) mouseX = half;
        if (mouseX > windowWidth - half) mouseX = windowWidth - half;

        platform.setPosition(mouseX, platform.getPosition().y);
    }
}

void GameScene::update(float dt) {
    // Gravity
    ballVelocity.y += gravity * dt;

    // Move ball
    ball.move(ballVelocity * dt);

    // Collisions
    handleWallCollision();
    handlePlatformCollision();

    // Keyboard rotation
    const float rotSpeed = 250.f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        platform.rotate(-rotSpeed * dt);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::E))
    {
        platform.rotate(rotSpeed * dt);
    }
}

void GameScene::handleWallCollision() {
    sf::Vector2f pos = ball.getPosition();
    float r = ball.getRadius();

    // Left
    if (pos.x - r < 0.f) {
        ball.setPosition(r, pos.y);
        ballVelocity.x = std::abs(ballVelocity.x);
    }

    // Right
    if (pos.x + r > windowWidth) {
        ball.setPosition(windowWidth - r, pos.y);
        ballVelocity.x = -std::abs(ballVelocity.x);
    }

    // Top
    if (pos.y - r < 0.f) {
        ball.setPosition(pos.x, r);
        ballVelocity.y = std::abs(ballVelocity.y);
    }

    // Bottom (soft bounce)
    if (pos.y + r > windowHeight) {
        ball.setPosition(pos.x, windowHeight - r);
        ballVelocity.y = -std::abs(ballVelocity.y) * bounceFactor;
    }
}

void GameScene::handlePlatformCollision() {
    sf::Vector2f pos = ball.getPosition();
    float r = ball.getRadius();

    sf::Vector2f pPos = platform.getPosition();
    sf::Vector2f pSize = platform.getSize();

    float left = pPos.x - pSize.x / 2.f;
    float right = pPos.x + pSize.x / 2.f;
    float top = pPos.y - pSize.y / 2.f;

    // Check horizontal overlap
    bool overPlatformX = pos.x + r > left && pos.x - r < right;

    // Check vertical overlap (ball descending)
    bool hittingTop = pos.y + r > top && pos.y + r < top + 30.f;
    bool movingDown = ballVelocity.y > 0;

    if (overPlatformX && hittingTop && movingDown) {
        // Place ball on platform
        ball.setPosition(pos.x, top - r);

        // Bounce
        ballVelocity.y = -std::abs(ballVelocity.y) * bounceFactor;

        // Add spin effect depending on hit position
        float offset = (pos.x - pPos.x) / (pSize.x / 2.f);
        ballVelocity.x += offset * 200.f;
    }
}
void GameScene::draw(sf::RenderWindow& window) {
    window.draw(platform);
    window.draw(ball);
}

