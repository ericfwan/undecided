#include "scenes/GameScene.hpp"
#include "ui/FontManager.hpp"
#include "scenes/PauseScene.hpp"
#include <iostream>

GameScene::GameScene(sf::RenderWindow& window, SceneManager& manager)
    : Scene(window), sceneManager(manager), neon(window), hud(window)
{
    label.setFont(FontManager::get());
    label.setString("GAME ACTIVE");
    label.setCharacterSize(40);
    label.setFillColor(sf::Color::Magenta);

    sf::FloatRect b = label.getLocalBounds();
    label.setOrigin(b.width / 2, b.height / 2);
    label.setPosition(window.getSize().x / 2, window.getSize().y / 2);
}

void GameScene::handleEvent(sf::Event& event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        sceneManager.push(std::make_unique<PauseScene>(window, sceneManager));
    }
}

void GameScene::update(float dt) {
    neon.update(dt, window);
    hud.update(dt);
}

void GameScene::draw(sf::RenderWindow& window) {
    neon.draw(window);
    window.draw(label);
    hud.draw(window);
}
