#include "scenes/GameOverScene.hpp"
#include "ui/FontManager.hpp"
#include "scenes/GameScene.hpp"

GameOverScene::GameOverScene(sf::RenderWindow& window, SceneManager& manager, int score)
    : Scene(window), sceneManager(manager), neon(window)
{
    gameOverText.setFont(FontManager::get());
    gameOverText.setString("GAME OVER");
    gameOverText.setCharacterSize(56);
    gameOverText.setFillColor(sf::Color::Red);

    sf::FloatRect b = gameOverText.getLocalBounds();
    gameOverText.setOrigin(b.width / 2, b.height / 2);
    gameOverText.setPosition(window.getSize().x / 2, 120);

    scoreText.setFont(FontManager::get());
    scoreText.setString("Score: " + std::to_string(score));
    scoreText.setCharacterSize(28);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(window.getSize().x / 2 - 60, 200);

    retryButton = new Button("RETRY", 32);
    menuButton = new Button("MENU", 32);

    retryButton->setPosition(window.getSize().x / 2 - 100, 260);
    menuButton->setPosition(window.getSize().x / 2 - 100, 320);
}

void GameOverScene::handleEvent(sf::Event& event) {}

void GameOverScene::update(float dt) {
    neon.update(dt, window);

    retryButton->update(window);
    menuButton->update(window);

    if (retryButton->isClicked(window)) {
        sceneManager.push(std::make_unique<GameScene>(window, sceneManager));
    }

    if (menuButton->isClicked(window)) {
        sceneManager.clear();
    }
}

void GameOverScene::draw(sf::RenderWindow& window) {
    neon.draw(window);
    window.draw(gameOverText);
    window.draw(scoreText);

    retryButton->draw(window);
    menuButton->draw(window);
}
