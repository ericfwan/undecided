#include "Game.hpp"

/**int main() {
    Game game;
    game.run();
    return 0;
}
**/

#include <SFML/Graphics.hpp>
#include "physics/RigidBody.hpp"
#include "scenes/Renderer.hpp"
#include <vector>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Renderer Test");
    window.setFramerateLimit(60);

    Renderer renderer;


    auto rect = Physics::RigidBody({400.f, 500.f}, {150.f, 20.f});
    auto ball = Physics::RigidBody({200.f, 300.f}, 30.f);


    std::vector<Physics::RigidBody*> activeObjects = { &rect, &ball };

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        float dt = clock.restart().asSeconds();

        // Update physics
        for (auto& obj : activeObjects) {
            obj->update(dt);
        }

        window.clear(sf::Color::Black);
        renderer.render(window, activeObjects); // draw all objects
        window.display();
    }

    return 0;
}

