#include <SFML/Graphics.hpp>
#include "SceneManager.hpp"
#include "scenes/MenuScene.hpp"
#include "ui/SoundBank.hpp"


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Undecided");
    window.setFramerateLimit(60);
    SoundBank::get().load("click", "assets/sfx/click.wav");



    SceneManager sceneManager;

    // LOAD THE MENU SCENE
    sceneManager.push(std::make_unique<MenuScene>(window, sceneManager));

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
