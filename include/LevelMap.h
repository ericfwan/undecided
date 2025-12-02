#pragma once
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

class LevelMap {
public:
    LevelMap();
    bool loadFromCSV(const std::string &path);
    void setTileSize(unsigned int w, unsigned int h);
    void draw(sf::RenderWindow &window, const sf::Texture &tileset);

private:
    std::vector<std::vector<int>> grid;
    unsigned int tileW = 32;
    unsigned int tileH = 32;
};
