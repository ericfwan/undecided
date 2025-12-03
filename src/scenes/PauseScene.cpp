#include "scenes/PauseScene.hpp"
#include "config.hpp"
#include <iostream>

PauseScene::PauseScene(sf::RenderWindow& window, SceneManager& manager)
    : Scene(window), sceneManager(manager)
{
    font.loadFromFile("assets/fonts/RobotoMono-Regular.ttf");

    // Semi-transparent overlay
    darkOverlay.setSize({ (float)window.getSize().x, (float)window.getSize().y });
    darkOverlay.setFillColor(sf::Color(0, 0, 0, 150));

    // Title text
    title.setFont(font);
    title.setString("PAUSED");
    title.setCharacterSize(Style::TitleFontSize);
    title.setFillColor(Style::NeonMagenta);

    sf::FloatRect bounds = title.getLocalBounds();
    title.setOrigin(bounds.width / 2, bounds.height / 2);
    title.setPosition(window.getSize().x / 2, window.getSize().y / 2 - 40);
}

void PauseScene::handleEvent(sf::Event& event) {
    // ESC closes pause menu
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape) {
            std::cout << "Resuming game...\n";
            sceneManager.pop();  // pop the pause scene
        }
    }
}

void PauseScene::update(float dt) {
    // Pause scene doesn't need logic for now
}

void PauseScene::draw(sf::RenderWindow& window) {
    // Draw overlay above the gameplay
    window.draw(darkOverlay);
    window.draw(title);
}
