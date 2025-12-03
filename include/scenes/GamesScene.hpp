#pragma once

#include <SFML/Graphics.hpp>
#include "Scene.hpp"
#include "SceneManager.hpp"

class GameScene : public Scene {
public:
    GameScene(sf::RenderWindow& window, SceneManager& manager);

    void handleEvent(sf::Event& event) override;
    void update(float dt) override;
    void draw(sf::RenderWindow& window) override;

private:
    SceneManager& sceneManager;

    // TEMP TEST: something visible on screen
    sf::CircleShape circle;
};
