# Project: Undecided (SFML 2.x + CMake)

This code tree is a starter template for your **Undecided** project using **SFML 2.x** and **CMake**. It contains a minimal working window, a simple tile-map loader, and CMake config tuned for Homebrew SFML (Apple Silicon). Drop your assets into the `assets/` folder and add levels as CSV files.

---

## CMakeLists.txt

```cmake
cmake_minimum_required(VERSION 3.18)
project(Undecided LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Allow user to pass custom prefix path (recommended on macOS Homebrew sfml@2)
if(NOT DEFINED CMAKE_PREFIX_PATH)
    set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH};/opt/homebrew/opt/sfml@2")
endif()

find_package(SFML 2 COMPONENTS system window graphics audio REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB SRC "${CMAKE_SOURCE_DIR}/src/*.cpp")
add_executable(Undecided ${SRC})

target_link_libraries(Undecided PRIVATE sfml-system sfml-window sfml-graphics sfml-audio)

# Useful build flags
if(MSVC)
    target_compile_options(Undecided PRIVATE /W4 /permissive-)
else()
    target_compile_options(Undecided PRIVATE -Wall -Wextra -Wpedantic)
endif()
```

---

## .gitignore

```
/build
/.vscode
/.idea
*.o
*.obj
*.exe
*.DS_Store
/Makefile
/CMakeFiles
/CMakeCache.txt
```

---

## include/LevelMap.h

```cpp
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
    std::vector<std::vector<int>> grid; // simple int id grid
    unsigned int tileW = 32;
    unsigned int tileH = 32;
};
```

---

## src/LevelMap.cpp

```cpp
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
            if(id <= 0) continue; // 0 = empty

            // assume tileset cells laid out left-to-right, top-to-bottom
            unsigned int ti = (unsigned int)(id - 1);
            unsigned int tx = ti % cols;
            unsigned int ty = ti / cols;

            spr.setTextureRect(sf::IntRect(tx * tileW, ty * tileH, tileW, tileH));
            spr.setPosition(static_cast<float>(x * tileW), static_cast<float>(y * tileH));
            window.draw(spr);
        }
    }
}
```

---

## src/main.cpp

```cpp
#include <SFML/Graphics.hpp>
#include <iostream>
#include "LevelMap.h"

int main() {
    const unsigned int WINDOW_W = 800;
    const unsigned int WINDOW_H = 600;

    sf::RenderWindow window(sf::VideoMode(WINDOW_W, WINDOW_H), "Undecided - Level Designer (SFML)");
    window.setFramerateLimit(60);

    // Load a simple tileset (placeholder). Place your tiles in assets/tiles.png
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

        // Draw level
        level.draw(window, tileset);

        // Simple UI text
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
```

---

## build_instructions.txt

```
# Build instructions (macOS Apple Silicon / Homebrew sfml@2)

1) From project root:
   mkdir build
   cd build
   cmake -DCMAKE_PREFIX_PATH=/opt/homebrew/opt/sfml@2 ..
   make

2) Run the binary:
   ./Undecided

Notes:
- If you opened a new terminal session, export these or add them to ~/.zprofile or ~/.zshrc:
  export LDFLAGS="-L/opt/homebrew/opt/sfml@2/lib"
  export CPPFLAGS="-I/opt/homebrew/opt/sfml@2/include"
  export CMAKE_PREFIX_PATH="/opt/homebrew/opt/sfml@2"

- Place your tileset at: assets/tiles.png (tile size 32x32)
- Place levels at: assets/levels/level1.csv (CSV grid of integers)
```

---

## assets/ (suggested files)

- assets/tiles.png  (create a placeholder 96x32 with 3 tiles 32x32 each)
- assets/levels/level1.csv (sample grid:)

```
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
0,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0
0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0
... (extend rows to fit)
```

---

## README.md (short)

```
# Undecided
SFML 2.x C++ starter project for the Games Engineering module (SET09121).

This repo includes a tilemap loader and starter CMake config for macOS (Homebrew sfml@2).

Author: David Akpan
```

---

# Next steps
- I have generated a complete starter project in the canvas (look in the editor panel).  
- Follow `build_instructions.txt` (or run the quick commands below) to compile and run.

Quick build commands (run in project root):
```
mkdir build && cd build
cmake -DCMAKE_PREFIX_PATH=/opt/homebrew/opt/sfml@2 ..
make
./Undecided
```

If you want, I can now:
1. Create these files in your local machine (I can provide a zip) — tell me if you want a downloadable archive.
2. Push a ready Git repo structure with README + .gitignore content you can paste into your repo.
3. Start implementing a more advanced tile collision and physics interface (your core responsibility).

Which would you like next?
mkdir -p ~/UndecidedGame/src
mkdir -p ~/UndecidedGame/include
mkdir -p ~/UndecidedGame/assets/levels
cd ~/UndecidedGame

