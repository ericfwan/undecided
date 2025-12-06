#pragma once
#include "Scene.hpp"
#include "ui/Button.hpp"
#include <SFML/Graphics.hpp>

// Simple confirmation overlay.
// Should ONLY close the window when the user explicitly clicks YES.
class ConfirmExit : public Scene {
public:
    ConfirmExit(Game& game);

    void handleEvent(sf::Event& event) override;
    void update(float dt) override;
    void draw(sf::RenderWindow& window) override;

private:
    sf::Text title;

    Button yesBtn;
    Button noBtn;
};
