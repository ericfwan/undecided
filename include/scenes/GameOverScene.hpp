#pragma once
#include "Scene.hpp"
#include "SceneManager.hpp"
#include "ui/Button.hpp"
#include "ui/NeonBackground.hpp"

class GameOverScene : public Scene {
public:
    GameOverScene(sf::RenderWindow& window, SceneManager& manager, int score);

    void handleEvent(sf::Event& event) override;
    void update(float dt) override;
    void draw(sf::RenderWindow& window) override;

private:
    SceneManager& sceneManager;
    NeonBackground neon;

    sf::Text gameOverText;
    sf::Text scoreText;

    Button* retryButton;
    Button* menuButton;
};
