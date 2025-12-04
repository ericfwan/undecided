#include "ui/NeonBackground.hpp"
#include <cstdlib>

NeonBackground::NeonBackground(sf::RenderWindow& window) {
    const int count = 12;

    for (int i = 0; i < count; i++) {
        Line l;

        // vertical line
        l.shape.setSize({2.f, static_cast<float>(window.getSize().y)});
        
        // Neon cyan with random opacity
        l.shape.setFillColor(sf::Color(0, 255, 255, 60 + rand() % 120));

        // Random X position
        float x = (window.getSize().x / count) * i + (rand() % 40 - 20);
        l.shape.setPosition(x, 0);

        // Random speed
        l.speed = 20.f + rand() % 40;

        lines.push_back(l);
    }
}

void NeonBackground::update(float dt, sf::RenderWindow& window) {
    for (auto& ln : lines) {
        ln.shape.move(ln.speed * dt, 0);

        // wrap lines looping across screen
        if (ln.shape.getPosition().x > window.getSize().x) {
            ln.shape.setPosition(-10.f, 0);
        }
    }
}

void NeonBackground::draw(sf::RenderWindow& window) {
    for (auto& ln : lines) {
        window.draw(ln.shape);
    }
}
