#pragma once
#include <SFML/Graphics.hpp>

#include "SceneManager.hpp"
#include "ui/NeonBackground.hpp"

// Core game container.
// Owns the window, global settings, background, and scene stack.
class Game {
public:
    Game();
    void run();

    sf::RenderWindow window;
    SceneManager scenes;
    NeonBackground background;

    // Global visual settings updated by Options
    sf::Color ballColor = sf::Color::White;
    sf::Color neonColor = sf::Color::Cyan;

    // Global SFX toggle
    bool sfxEnabled = true;
};
