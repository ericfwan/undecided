#pragma once
#include <SFML/Graphics.hpp>

class Game;

// Base class for all scenes.
// Each scene is responsible for its own input, update, and draw logic.
class Scene {
public:
    Scene(Game& game) : game(game) {}
    virtual ~Scene() = default;

    virtual void handleEvent(sf::Event& event) = 0;
    virtual void update(float dt) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;

protected:
    Game& game;
};
