#include "ui/Button.hpp"
#include <cmath>

Button::Button(const sf::Font& font, const std::string& text, unsigned int size)
{
    label.setFont(font);
    label.setString(text);
    label.setCharacterSize(size);

    normalColor = sf::Color(0, 255, 255); 
    hoverColor  = sf::Color(255, 0, 255);

    label.setFillColor(normalColor);

    sf::FloatRect bounds = label.getLocalBounds();
    box.setSize({ bounds.width + 30, bounds.height + 30 });
    box.setFillColor(sf::Color::Transparent);
    box.setOutlineThickness(2);
    box.setOutlineColor(normalColor);
}

void Button::setPosition(float x, float y) {
    box.setPosition(x, y);
    label.setPosition(x + 15, y + 15);
}

void Button::setColors(sf::Color normal, sf::Color hover) {
    normalColor = normal;
    hoverColor = hover;
}

void Button::setOutline(float thickness, sf::Color color) {
    box.setOutlineThickness(thickness);
    box.setOutlineColor(color);
}

bool Button::isHovered(sf::RenderWindow& window) {
    auto p = sf::Mouse::getPosition(window);
    return box.getGlobalBounds().contains(p.x, p.y);
}

bool Button::isClicked(sf::RenderWindow& window) {
    return hovered && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

void Button::update(sf::RenderWindow& window) {
    hovered = isHovered(window);

    if (hovered) {
        pulseTime += 0.07f;
        hoverScale = 1.0f + std::sin(pulseTime) * 0.08f;

        label.setScale(hoverScale, hoverScale);
        box.setScale(hoverScale, hoverScale);

        label.setFillColor(hoverColor);
        box.setOutlineColor(hoverColor);
    } else {
        pulseTime = 0;
        hoverScale = 1.0f;
        label.setScale(1.0f, 1.0f);
        box.setScale(1.0f, 1.0f);

        label.setFillColor(normalColor);
        box.setOutlineColor(normalColor);
    }
}

void Button::draw(sf::RenderWindow& window) {
    window.draw(box);
    window.draw(label);
}
