#pragma once
#include "Scene.hpp"
#include "ui/Button.hpp"
#include <SFML/Graphics.hpp>

class MenuScene : public Scene {
public:
    MenuScene(Game& game);

    void handleEvent(sf::Event& event) override;
    void update(float dt) override;
   void draw(sf::RenderWindow& window) override;

private:
    Button playButton;
    Button optionsButton;
    Button exitButton;

    sf::Text title;
};
