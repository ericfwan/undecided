#pragma once
#include "Scene.hpp"
#include "SceneManager.hpp"
#include "ui/HUD.hpp"
#include "ui/NeonBackground.hpp"

class GameScene : public Scene {
public:
    GameScene(sf::RenderWindow& window, SceneManager& manager);

    void handleEvent(sf::Event& event) override;
    void update(float dt) override;
    void draw(sf::RenderWindow& window) override;

private:
    SceneManager& sceneManager;
    NeonBackground neon;
    HUD hud;

    sf::Text label;
};
