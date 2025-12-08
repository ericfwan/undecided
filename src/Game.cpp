#include "Game.hpp"
#include "scenes/MenuScene.hpp"

Game::Game()
: window(sf::VideoMode(1920, 1080), "Undecided")
, scenes(*this)
{
    window.setFramerateLimit(60);

    scenes.push(std::make_unique<MenuScene>(*this));
}

void Game::run() {
    sf::Clock clock;

    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (scenes.current())
                scenes.current()->handleEvent(event);
        }

        if (scenes.current())
            scenes.current()->update(dt);

        window.clear(sf::Color(10, 10, 20));

        // Draw global neon background (new clean version)
        background.draw(window);

        // Draw current scene
        if (scenes.current())
            scenes.current()->draw(window);

        window.display();
    }
}
