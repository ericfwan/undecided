#pragma once
#include <SFML/Graphics.hpp>

class NeonBackground {
public:
    NeonBackground();

    void setColor(const sf::Color& c);
    void draw(sf::RenderWindow& window);

private:
    sf::RectangleShape shape;
};
