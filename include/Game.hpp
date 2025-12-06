#pragma once
#include <SFML/Graphics.hpp>
#include "SceneManager.hpp"
#include "ui/NeonBackground.hpp"

class Game {
public:
    Game();
    void run();

    sf::RenderWindow window;
    SceneManager scenes;
    NeonBackground background;

    sf::Color ballColor = sf::Color::White;
    sf::Color neonColor = sf::Color::Cyan;

    bool sfxEnabled = true;
};
