#include "ui/FontManager.hpp"
#include <stdexcept>

sf::Font FontManager::font;
bool FontManager::loaded = false;

const sf::Font& FontManager::get() {
    if (!loaded) {
        if (!font.loadFromFile("assets/fonts/RobotoMono-Regular.ttf")) {
            throw std::runtime_error("Failed to load font!");
        }
        loaded = true;
    }
    return font;
}
