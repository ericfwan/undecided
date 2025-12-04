#pragma once
#include <SFML/Graphics.hpp>

class SceneManager;

class Scene {
public:
    Scene(sf::RenderWindow& window) : window(window) {}
    virtual ~Scene() = default;

    virtual void handleEvent(sf::Event& event) = 0;
    virtual void update(float dt) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;

protected:
    sf::RenderWindow& window;
};
