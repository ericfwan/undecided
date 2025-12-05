#pragma once
#include <SFML/Graphics.hpp>

class Player {
public:
    Player();
    void update(float dt);
    void draw(sf::RenderWindow& window);

private:
    sf::Sprite sprite;
    sf::Texture texture;
    float speed = 200.f; // pixels per second
};
