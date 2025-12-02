#include "LevelMap.h"
#include <fstream>
#include <sstream>
#include <iostream>

LevelMap::LevelMap() {}

void LevelMap::setTileSize(unsigned int w, unsigned int h) {
    tileW = w;
    tileH = h;
}

bool LevelMap::loadFromCSV(const std::string &path) {
    std::ifstream in(path);
    if(!in.is_open()) return false;

    grid.clear();
    std::string line;
    while(std::getline(in, line)) {
        if(line.empty()) continue;
        std::stringstream ss(line);
        std::vector<int> row;
        std::string cell;
        while(std::getline(ss, cell, ',')) {
            try {
                int id = std::stoi(cell);
                row.push_back(id);
            } catch(...) {
                row.push_back(0);
            }
        }
        grid.push_back(row);
    }
    return !grid.empty();
}

void LevelMap::draw(sf::RenderWindow &window, const sf::Texture &tileset) {
    if(grid.empty()) return;

    sf::Sprite spr;
    spr.setTexture(tileset);

    unsigned int cols = tileset.getSize().x / tileW;

    for(size_t y = 0; y < grid.size(); ++y) {
        for(size_t x = 0; x < grid[y].size(); ++x) {
            int id = grid[y][x];
            if(id <= 0) continue;

            unsigned int ti = (unsigned int)(id - 1);
            unsigned int tx = ti % cols;
            unsigned int ty = ti / cols;

            spr.setTextureRect(sf::IntRect(tx * tileW, ty * tileH, tileW, tileH));
            spr.setPosition(static_cast<float>(x * tileW), static_cast<float>(y * tileH));
            window.draw(spr);
        }
    }
}
