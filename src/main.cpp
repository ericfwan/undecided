#include <SFML/Graphics.hpp>
#include <iostream>
#include "LevelMap.h"

int main() {
    const unsigned int WINDOW_W = 800;
    const unsigned int WINDOW_H = 600;

    sf::RenderWindow window(sf::VideoMode(WINDOW_W, WINDOW_H), "Undecided - Level Designer (SFML)");
    window.setFramerateLimit(60);

    sf::Texture tileset;
    if(!tileset.loadFromFile("assets/tiles.png")) {
        std::cerr << "Warning: assets/tiles.png not found. Using empty tileset." << std::endl;
    }

    LevelMap level;
    level.setTileSize(32, 32);
    bool ok = level.loadFromCSV("assets/levels/level1.csv");
    if(!ok) std::cerr << "Warning: level CSV not found or empty (assets/levels/level1.csv)" << std::endl;

    while(window.isOpen()) {
        sf::Event ev;
        while(window.pollEvent(ev)) {
            if(ev.type == sf::Event::Closed) window.close();
        }

        window.clear(sf::Color(15,15,30));

        level.draw(window, tileset);

        sf::Font font;
        if(font.loadFromFile("assets/fonts/arial.ttf")) {
            sf::Text t("Undecided - Level Preview", font, 14);
            t.setPosition(8.f, 8.f);
            window.draw(t);
        }

        window.display();
    }

    return 0;
}
