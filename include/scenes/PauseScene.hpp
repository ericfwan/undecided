#pragma once
#include "Scene.hpp"
#include "SceneManager.hpp"
#include "ui/Button.hpp"
#include "ui/NeonBackground.hpp"

class PauseScene : public Scene {
public:
    PauseScene(sf::RenderWindow& window, SceneManager& manager);

    void handleEvent(sf::Event& event) override;
    void update(float dt) override;
    void draw(sf::RenderWindow& window) override;

private:
    SceneManager& sceneManager;
    NeonBackground neon;

    sf::Text pausedText;
    Button* resumeButton;
    Button* menuButton;
};
