#pragma once
#include <SFML/Graphics.hpp>

class FontManager {
public:
    static const sf::Font& get();

private:
    static sf::Font font;
    static bool loaded;
};
