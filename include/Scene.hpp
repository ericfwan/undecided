#pragma once
#include <SFML/Graphics.hpp>

class Game;

class Scene {
public:
    Scene(Game& game) : game(game) {}
    virtual ~Scene() = default;

    virtual void handleEvent(sf::Event& event){};
    virtual void update(float dt) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;

protected:
    Game& game;
};
