#pragma once
#include "Scene.hpp"
#include "ui/Button.hpp"
#include <SFML/Graphics.hpp>

class GameOverScene : public Scene {
public:
    GameOverScene(Game& game, int score);

    void handleEvent(sf::Event& event) override;
    void update(float dt) override;
   void draw(sf::RenderWindow& window) override;


private:
    sf::Text title;
    sf::Text scoreText;

    Button retryBtn;
    Button menuBtn;
    Button exitBtn;

    void positionUI();
};
