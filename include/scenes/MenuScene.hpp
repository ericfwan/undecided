#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
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

    // Background
    sf::RectangleShape background;

    // Title
    sf::Text title;
    sf::Font font;

    // Buttons
    Button* playButton;
    Button* optionsButton;
    Button* exitButton;

    // NEON LINES (THE ONES YOU WERE MISSING)
    std::vector<sf::RectangleShape> neonLines;
    std::vector<float> neonSpeeds;
};
