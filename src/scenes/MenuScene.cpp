#include "scenes/MenuScene.hpp"
#include <iostream> // temp logging

MenuScene::MenuScene(sf::RenderWindow& window, SceneManager& manager)
    : sceneManager(manager)
{
    font.loadFromFile("assets/fonts/arial.ttf"); // temporary

    // Create Buttons
    playButton = new Button(font, "PLAY", 32);
    optionsButton = new Button(font, "OPTIONS", 32);
    exitButton = new Button(font, "EXIT", 32);

    // Position them
    playButton->setPosition(280, 200);
    optionsButton->setPosition(280, 260);
    exitButton->setPosition(280, 320);

    // Neon colours (cyan + magenta)
    playButton->setColors(sf::Color(0,255,255), sf::Color(255,0,255));
    optionsButton->setColors(sf::Color(0,255,255), sf::Color(255,0,255));
    exitButton->setColors(sf::Color(0,255,255), sf::Color(255,0,255));

    playButton->setOutline(3, sf::Color(0,255,255));
    optionsButton->setOutline(3, sf::Color(0,255,255));
    exitButton->setOutline(3, sf::Color(0,255,255));
}

void MenuScene::handleEvent(sf::Event& event) {
    // no click event needed here (click detection inside update)
}

void MenuScene::update(float dt) {
    // Hover animations
    playButton->update(*sceneManager.current()->window); // this line needs window reference
    optionsButton->update(*sceneManager.current()->window);
    exitButton->update(*sceneManager.current()->window);

    // Click detection
    if (playButton->isClicked(*sceneManager.current()->window)) {
        std::cout << "PLAY clicked\n";
        // TODO: switch to GameScene
    }
    if (optionsButton->isClicked(*sceneManager.current()->window)) {
        std::cout << "OPTIONS clicked\n";
    }
    if (exitButton->isClicked(*sceneManager.current()->window)) {
        std::cout << "EXIT clicked\n";
        exit(0);
    }
}

void MenuScene::draw(sf::RenderWindow& window) {
    playButton->draw(window);
    optionsButton->draw(window);
    exitButton->draw(window);
}
