#include "ui/FontManager.hpp"
#include <iostream>

sf::Font FontManager::font;
bool FontManager::loaded = false;

sf::Font& FontManager::get() {
    if (!loaded) {
        if (!font.loadFromFile("assets/fonts/RobotoMono-Regular.ttf")) {
            std::cerr << "ERROR: Failed to load font: assets/fonts/RobotoMono-Regular.ttf\n";
        }
        loaded = true;
    }
    return font;
}
