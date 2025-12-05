#pragma once
#include <SFML/Graphics.hpp>

class HUD {
public:
    HUD(sf::RenderWindow& window);

    void update(float dt);
    void draw(sf::RenderWindow& window);

private:
    sf::Text scoreText;
    sf::Text livesText;

    int score = 0;
    int lives = 3;
};
