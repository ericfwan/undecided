#pragma once
#include "Scene.hpp"
#include "ui/Button.hpp"
#include <SFML/Graphics.hpp>

// Pause overlay menu.
// Triggered by ESC while in gameplay.
class PauseScene : public Scene {
public:
    PauseScene(Game& game);

    void handleEvent(sf::Event& event) override;
    void update(float dt) override;
    void draw(sf::RenderWindow& window) override;

private:
    sf::Text pausedLabel;

    Button resumeBtn;
    Button restartBtn;
    Button quitBtn;
};
