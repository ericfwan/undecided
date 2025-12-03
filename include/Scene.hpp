#pragma once
#include <SFML/Graphics.hpp>

class Scene {
public:
    Scene(sf::RenderWindow& win) : window(win) {}
    virtual ~Scene() = default;

    virtual void handleEvent(sf::Event& event) = 0;
    virtual void update(float dt) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;

protected:
    sf::RenderWindow& window;
};
