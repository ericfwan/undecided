#include "scenes/MenuScene.hpp"
#include "scenes/GameScene.hpp"
#include "ui/FontManager.hpp"
#include "config.hpp"
#include <iostream>

MenuScene::MenuScene(sf::RenderWindow& window, SceneManager& manager)
    : Scene(window), sceneManager(manager), neon(window)
{
    // Title
    title.setFont(FontManager::get());
    title.setString("UNDECIDED");
    title.setCharacterSize(64);
    title.setFillColor(sf::Color::Cyan);

    sf::FloatRect b = title.getLocalBounds();
    title.setOrigin(b.width / 2, b.height / 2);
    title.setPosition(window.getSize().x / 2, 120);

    // Buttons
    playButton = new Button("PLAY", 32);
    optionsButton = new Button("OPTIONS", 32);
    exitButton = new Button("EXIT", 32);

    float cx = window.getSize().x / 2 - 100;
    float cy = 240;

    playButton->setPosition(cx, cy);
    optionsButton->setPosition(cx, cy + 60);
    exitButton->setPosition(cx, cy + 120);
}

void MenuScene::handleEvent(sf::Event& event) {}

void MenuScene::update(float dt) {
    neon.update(dt, window);

    playButton->update(window);
    optionsButton->update(window);
    exitButton->update(window);

    if (playButton->isClicked(window)) {
        std::cout << "Switching to GameScene...\n";
        sceneManager.push(std::make_unique<GameScene>(window, sceneManager));
    }

    if (exitButton->isClicked(window)) {
        window.close();
    }
}

void MenuScene::draw(sf::RenderWindow& window) {
    neon.draw(window);
    window.draw(title);

    playButton->draw(window);
    optionsButton->draw(window);
    exitButton->draw(window);
}
