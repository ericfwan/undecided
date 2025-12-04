#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class NeonBackground {
public:
    // Constructor requires window reference
    NeonBackground(sf::RenderWindow& window);

    // Update + draw
    void update(float dt, sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);

private:
    struct Line {
        sf::RectangleShape shape;
        float speed;
    };

    std::vector<Line> lines;
};
