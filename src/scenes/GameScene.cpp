#include "scenes/GameScene.hpp"
#include "ui/FontManager.hpp"
#include "scenes/PauseScene.hpp"
#include <iostream>
#include "scenes/GameScene.hpp"
#include "Scene.hpp"
#include <cmath>
#include "SceneManager.hpp"
#include "ui/NeonBackground.hpp"


GameScene::GameScene() {
    // Window size
    windowWidth = 800.f;
    windowHeight = 600.f;

    // Physics
    gravity = 800.f;
    bounceFactor = 0.8f;
    platformSpeed = 500.f;

    // Setup ball
    ball.setRadius(15.f);
    ball.setFillColor(sf::Color::Red);
    ball.setOrigin(15.f, 15.f); // Center origin
    ball.setPosition(400.f, 100.f);
    ballVelocity = sf::Vector2f(150.f, 0.f);

    // Setup platform
    platform.setSize(sf::Vector2f(120.f, 20.f));
    platform.setFillColor(sf::Color::White);
    platform.setOrigin(60.f, 10.f); // Center origin
    platform.setPosition(400.f, 500.f);
}


void GameScene::handleEvent(sf::Event &event, float const dt) {
    // Mouse control
    if (event.type == sf::Event::MouseMoved) {
        auto mouseX = static_cast<float>(event.mouseMove.x);
        auto mouseY = static_cast<float>(event.mouseMove.y);

        // Keep platform in bounds
        float const halfWidth = platform.getSize().x / 2.f;
        float const halfHeight = platform.getSize().y / 2.f;

        if (mouseX < halfWidth) {
            mouseX = halfWidth;
        }
        if (mouseX > windowWidth - halfWidth) {
            mouseX = windowWidth - halfWidth;
        }
        if (mouseY < halfHeight) {
            mouseY = halfHeight;
        }
        if (mouseY > windowHeight - halfHeight) {
            mouseY = windowHeight - halfHeight;
        }


        platform.setPosition(mouseX, mouseY);
    }


    // Keyboard control for platform
    float platformHalfWidth = platform.getSize().x / 2.f;
    float platformHalfHeight = platform.getSize().y / 2.f;
    float constexpr  rotationSpeed = 360.f; // degrees per second

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        platform.rotate(-rotationSpeed * dt);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
        platform.rotate(rotationSpeed * dt);
    }

    // Keep platform in bounds
    sf::Vector2f platPos = platform.getPosition();
    platformHalfWidth = platform.getSize().x / 2.f;
    platformHalfHeight = platform.getSize().y / 2.f;

    // Clamp X
    if (platPos.x < platformHalfWidth) {
        platPos.x = platformHalfWidth;
    }
    if (platPos.x > windowWidth - platformHalfWidth) {
        platPos.x = windowWidth - platformHalfWidth;
    }

    // Clamp Y
    if (platPos.y < platformHalfHeight) {
        platPos.y = platformHalfHeight;
    }
    if (platPos.y > windowHeight - platformHalfHeight) {
        platPos.y = windowHeight - platformHalfHeight;
    }

    // Apply clamped position
    platform.setPosition(platPos);

    // Apply gravity to ball
    ballVelocity.y += gravity * dt;

    // Move ball
    ball.move(ballVelocity * dt);

    // Handle collisions
    handleWallCollision();
    handlePlatformCollision();
}

void GameScene::handleWallCollision() {
    sf::Vector2f pos = ball.getPosition();
    const float radius = ball.getRadius();

    // Left wall
    if (pos.x - radius < 0.f) {
        ball.setPosition(radius, pos.y);
        if (ballVelocity.x > -100.f) {
            ballVelocity.x = std::abs(ballVelocity.x);
        } else {
            ballVelocity.x = std::abs(ballVelocity.x) * bounceFactor;
        }
    }

    // Right wall
    if (pos.x + radius > windowWidth) {
        ball.setPosition(windowWidth - radius, pos.y);
        if (ballVelocity.x < 100.f) {
            ballVelocity.x = -std::abs(ballVelocity.x);
        } else {
            ballVelocity.x = -std::abs(ballVelocity.x) * bounceFactor;
        }
    }

    // Ceiling
    if (pos.y - radius < 0.f) {
        ball.setPosition(pos.x, radius);
        if (ballVelocity.y < 100.f) {
            ballVelocity.y = -std::abs(ballVelocity.y);
        } else {
            ballVelocity.y = -std::abs(ballVelocity.y) * bounceFactor;
        }
    }

    // Floor
    if (pos.y + radius > windowHeight) {
        ball.setPosition(pos.x, windowHeight - radius);
        if (ballVelocity.y > -100.f) {
            ballVelocity.y = -std::abs(ballVelocity.y);
        } else {
            ballVelocity.y = -std::abs(ballVelocity.y) * bounceFactor;
        }
    }
}

void GameScene::handlePlatformCollision() {
    sf::Vector2f ballPos = ball.getPosition();
    float radius = ball.getRadius();

    sf::Vector2f platPos = platform.getPosition();
    sf::Vector2f platSize = platform.getSize();

    // Platform boundaries
    float platLeft = platPos.x - platSize.x / 2.f;
    float platRight = platPos.x + platSize.x / 2.f;
    float platTop = platPos.y - platSize.y / 2.f;

    // Check if ball hits platform
    bool ballAbovePlatform = ballPos.x + radius > platLeft &&
                             ballPos.x - radius < platRight;
    bool ballHitsPlatformTop = ballPos.y + radius > platTop &&
                               ballPos.y + radius < platTop + 20.f;
    bool ballMovingDown = ballVelocity.y > 0;

    if (ballAbovePlatform && ballHitsPlatformTop && ballMovingDown) {
        // Place ball on top of platform
        ball.setPosition(ballPos.x, platTop - radius);

        // Bounce upward
        ballVelocity.y = -std::abs(ballVelocity.y) * bounceFactor;

        // Add spin based on where ball hit platform
        float hitPosition = (ballPos.x - platPos.x) / (platSize.x / 2.f);
        ballVelocity.x += hitPosition * 150.f;
    }
}

void GameScene::draw(sf::RenderWindow &window) {
    window.draw(platform);
    window.draw(ball);
}

void GameScene::update(float dt) {
    neon.update(dt, window);
    hud.update(dt);
}

void GameScene::draw(sf::RenderWindow &window) {
    neon.draw(window);
    window.draw(label);
    hud.draw(window);
}


