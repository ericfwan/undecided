#pragma once
#include <SFML/Graphics.hpp>
#include "SceneManager.hpp"
#include "ui/NeonBackground.hpp"

// Central game context.
// Owns the window, scene stack, and a few global settings shared across scenes.
class Game {
public:
    Game();
    void run();

    sf::RenderWindow window;
    SceneManager scenes;
    NeonBackground background;

    // Runtime-configurable visual settings.
    sf::Color ballColor = sf::Color::White;
    sf::Color neonColor = sf::Color::Cyan;

    // Global SFX toggle (used by UI/menus).
    bool sfxEnabled = true;
};
