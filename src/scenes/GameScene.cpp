#include "scenes/GameScene.hpp"
#include <iostream>

GameScene::GameScene(sf::RenderWindow& window, SceneManager& manager)
    : Scene(window), sceneManager(manager)
{
    circle.setRadius(40);
    circle.setFillColor(sf::Color::Magenta);
    circle.setPosition(300, 300);
}

void GameScene::handleEvent(sf::Event& event) {
}

void GameScene::update(float dt) {
}

void GameScene::draw(sf::RenderWindow& window) {
    window.draw(circle);
}
