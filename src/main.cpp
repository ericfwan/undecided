#include <SFML/Graphics.hpp>
#include "SceneManager.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Undecided");
    window.setFramerateLimit(60);

    SceneManager sceneManager;

    // temporary; no scene yet
    // add MenuScene next

    sf::Clock clock;

    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (sceneManager.current())
                sceneManager.current()->handleEvent(event);
        }

        if (sceneManager.current())
            sceneManager.current()->update(dt);

        window.clear();
        if (sceneManager.current())
            sceneManager.current()->draw(window);
        window.display();
    }

    return 0;
}
