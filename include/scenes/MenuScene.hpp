#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.hpp"
#include "SceneManager.hpp"
#include "ui/Button.hpp"

class MenuScene : public Scene {
public:
    MenuScene(sf::RenderWindow& window, SceneManager& manager);

    void handleEvent(sf::Event& event) override;
    void update(float dt) override;
    void draw(sf::RenderWindow& window) override;

private:
    SceneManager& sceneManager;
    sf::Font font;

    Button* playButton;
    Button* optionsButton;
    Button* exitButton;
};
