#pragma once
#include "Scene.hpp"
#include "SceneManager.hpp"
#include <SFML/Graphics.hpp>

class PauseScene : public Scene {
public:
    PauseScene(sf::RenderWindow& window, SceneManager& manager);

    void handleEvent(sf::Event& event) override;
    void update(float dt) override;
    void draw(sf::RenderWindow& window) override;

private:
    SceneManager& sceneManager;

    sf::RectangleShape darkOverlay;
    sf::Text title;
    sf::Font font;
};
