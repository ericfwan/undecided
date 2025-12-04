#include "scenes/PauseScene.hpp"
#include "ui/FontManager.hpp"
#include <iostream>

PauseScene::PauseScene(sf::RenderWindow& window, SceneManager& manager)
    : Scene(window), sceneManager(manager), neon(window)
{
    pausedText.setFont(FontManager::get());
    pausedText.setString("PAUSED");
    pausedText.setCharacterSize(48);
    pausedText.setFillColor(sf::Color::Yellow);

    sf::FloatRect b = pausedText.getLocalBounds();
    pausedText.setOrigin(b.width / 2, b.height / 2);
    pausedText.setPosition(window.getSize().x / 2, 120);

    resumeButton = new Button("RESUME", 32);
    menuButton = new Button("MENU", 32);

    resumeButton->setPosition(window.getSize().x / 2 - 100, 250);
    menuButton->setPosition(window.getSize().x / 2 - 100, 310);
}

void PauseScene::handleEvent(sf::Event& event) {}

void PauseScene::update(float dt) {
    neon.update(dt, window);

    resumeButton->update(window);
    menuButton->update(window);

    if (resumeButton->isClicked(window)) {
        sceneManager.pop();  // return to game
    }

    if (menuButton->isClicked(window)) {
        sceneManager.clear();
    }
}

void PauseScene::draw(sf::RenderWindow& window) {
    neon.draw(window);
    window.draw(pausedText);
    resumeButton->draw(window);
    menuButton->draw(window);
}
