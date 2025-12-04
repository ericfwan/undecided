#include "ui/Button.hpp"
#include "ui/FontManager.hpp"
#include "ui/SoundBank.hpp"

Button::Button(const std::string& text, unsigned int size) {
    label.setFont(FontManager::get());
    label.setString(text);
    label.setCharacterSize(size);

    // Default button theme
    normalColor = sf::Color(0, 255, 255);
    hoverColor  = sf::Color(255, 0, 255);

    label.setFillColor(normalColor);

    // Background box based on text size
    sf::FloatRect bounds = label.getLocalBounds();
    box.setSize({bounds.width + 20, bounds.height + 20});
    box.setFillColor(sf::Color::Transparent);
    box.setOutlineThickness(2);
    box.setOutlineColor(normalColor);
}

void Button::setPosition(float x, float y) {
    box.setPosition(x, y);
    label.setPosition(x + 10, y + 8);
}

void Button::setColors(sf::Color normal, sf::Color hover) {
    normalColor = normal;
    hoverColor  = hover;
}

void Button::setOutline(float thickness, sf::Color color) {
    box.setOutlineThickness(thickness);
    box.setOutlineColor(color);
}

void Button::update(sf::RenderWindow& window) {
    auto mouse = sf::Mouse::getPosition(window);
    hovered = box.getGlobalBounds().contains(mouse.x, mouse.y);

    if (hovered) {
        label.setFillColor(hoverColor);
        box.setOutlineColor(hoverColor);
    } else {
        label.setFillColor(normalColor);
        box.setOutlineColor(normalColor);
    }
}

bool Button::isClicked(sf::RenderWindow& window) {
    if (hovered && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

        // Play click audio
        SoundBank::get().play("click");

        return true;
    }
    return false;
}

void Button::draw(sf::RenderWindow& window) {
    window.draw(box);
    window.draw(label);
}
