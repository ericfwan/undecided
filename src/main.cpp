#include "Game.hpp"
#include "physics/Controller.hpp"

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
    Controller controller;
    Physics::Collisions collisionSystem;



    Physics::RigidBody platform({400.f, 500.f}, {75.f, 5.f});
    Physics::RigidBody ball({200.f, 300.f}, 5.f);
    Physics::RigidBody* platform_ptr = &platform;

    controller.setPlatform(platform_ptr);

    // Setup ball
    ball.setOrigin();
    ball.velocity = {150.f, 0.f};

    // Optional colors
    platform.setColour(sf::Color::White);
    ball.setColour(sf::Color::Red);

    std::vector<Physics::RigidBody*> activeObjects = { &platform, &ball };

    sf::Vector2f gravity(0.f, 980.f);
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        float dt = clock.restart().asSeconds();

        controller.update(dt, window.getSize().x, window.getSize().y);


        // Physics updates

        ball.update(dt);

        window.clear(sf::Color::Black);
        renderer.render(window, activeObjects);
        window.display();
    }

    return 0;
}

