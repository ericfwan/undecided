#pragma once
#include <SFML/Graphics.hpp>

class HUD {
public:
    HUD();

    void setScore(int s);
    void update(float dt);
    void draw(sf::RenderWindow& w);

private:
    sf::Text scoreText;
    int score = 0;
};
