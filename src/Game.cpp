#include "Game.hpp"
#include "scenes/MenuScene.hpp"

#include <memory>

Game::Game()
: window(sf::VideoMode(1920, 1080), "Undecided")
, scenes(*this)
{
    window.setFramerateLimit(60);

    // Start on Menu
    scenes.push(std::make_unique<MenuScene>(*this));
}

void Game::run() {
    sf::Clock clock;

    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event)) {

            // Only OS close button closes the window
            if (event.type == sf::Event::Closed)
                window.close();

            // Forward input to active scene
            if (scenes.current())
                scenes.current()->handleEvent(event);
        }

        // Update active scene
        if (scenes.current())
            scenes.current()->update(dt);

        // Apply deferred root changes safely after update
        scenes.applyPending();

        // Clear
        window.clear(sf::Color(10, 10, 20));

        // Global neon BG
        background.draw(window);

        // Draw active scene
        if (scenes.current())
            scenes.current()->draw(window);

        window.display();
    }
}
