#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Button {
public:
    Button(const std::string& text, unsigned int size = 32);

    void setPosition(float x, float y);
    void setColors(sf::Color normal, sf::Color hover);
    void setOutline(float thickness, sf::Color color);

    void update(sf::RenderWindow& window);
    bool isClicked(sf::RenderWindow& window);

    void draw(sf::RenderWindow& window);

private:
    sf::Text label;
    sf::RectangleShape box;

    sf::Color normalColor;
    sf::Color hoverColor;

    bool hovered = false;
};
