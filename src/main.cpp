#include <SFML/Graphics.hpp>
#include "SceneManager.hpp"
#include "scenes/GameScene.hpp"
#include "Scene.hpp"
#include <memory>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Bouncing Ball");
    window.setFramerateLimit(60);

    SceneManager sceneManager;

    // THIS LINE IS KEY - creates and adds the game scene!
    sceneManager.push(std::make_unique<GameScene>());

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

        window.clear(sf::Color(30, 30, 40));
        if (sceneManager.current())
            sceneManager.current()->draw(window);
        window.display();
    }

    return 0;
}