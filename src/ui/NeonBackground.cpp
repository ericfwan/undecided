#include "ui/NeonBackground.hpp"

NeonBackground::NeonBackground() {
    shape.setSize({1920, 1080});
    shape.setFillColor(sf::Color(10, 10, 20)); // default dark clean bg
}

void NeonBackground::setColor(const sf::Color& c) {
    shape.setFillColor(c);
}

void NeonBackground::draw(sf::RenderWindow& window) {
    window.draw(shape);
}
