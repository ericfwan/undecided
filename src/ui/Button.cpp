#include "ui/Button.hpp"

Button::Button(const sf::Font& font, const std::string& text, unsigned int size)
{
    label.setFont(font);
    label.setString(text);
    label.setCharacterSize(size);

    // Default colors (neon-ish)
    normalColor = sf::Color(0, 255, 255);      // cyan
    hoverColor  = sf::Color(255, 0, 255);      // magenta

    label.setFillColor(normalColor);

    // Button “box” for clicking (invisible, used for hitbox + outline)
    box.setFillColor(sf::Color::Transparent);
    box.setOutlineThickness(2);
    box.setOutlineColor(normalColor);

    // Fit box to text
    sf::FloatRect bounds = label.getLocalBounds();
    box.setSize({ bounds.width + 20, bounds.height + 20 });
}

void Button::setPosition(float x, float y) {
    box.setPosition(x, y);
    label.setPosition(x + 10, y + 10);
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
    auto mousePos = sf::Mouse::getPosition(window);
    return box.getGlobalBounds().contains(mousePos.x, mousePos.y);
}

bool Button::isClicked(sf::RenderWindow& window) {
    return hovered && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

void Button::update(sf::RenderWindow& window) {
    hovered = isHovered(window);

    if (hovered) {
        label.setFillColor(hoverColor);
        box.setOutlineColor(hoverColor);
    } else {
        label.setFillColor(normalColor);
        box.setOutlineColor(normalColor);
    }
}

void Button::draw(sf::RenderWindow& window) {
    window.draw(box);
    window.draw(label);
}
