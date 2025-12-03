#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Button {
public:
    Button(const sf::Font& font, const std::string& text, unsigned int size);

    void setPosition(float x, float y);
    void setColors(sf::Color normal, sf::Color hover);
    void setOutline(float thickness, sf::Color color);

    bool isHovered(sf::RenderWindow& window);
    bool isClicked(sf::RenderWindow& window);

    void update(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);

private:
    sf::Text label;
    sf::RectangleShape box;

    sf::Color normalColor;
    sf::Color hoverColor;

    bool hovered = false;

    // Animation
    float pulseTime = 0.f;
    float hoverScale = 1.f;
};
