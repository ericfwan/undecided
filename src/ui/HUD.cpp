#include "ui/HUD.hpp"
#include "ui/FontManager.hpp"

HUD::HUD(sf::RenderWindow& window) {
    scoreText.setFont(FontManager::get());
    scoreText.setCharacterSize(20);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(20, 10);

    livesText.setFont(FontManager::get());
    livesText.setCharacterSize(20);
    livesText.setFillColor(sf::Color::White);
    livesText.setPosition(window.getSize().x - 120, 10);
}

void HUD::update(float dt) {
    scoreText.setString("Score: " + std::to_string(score));
    livesText.setString("Lives: " + std::to_string(lives));
}

void HUD::draw(sf::RenderWindow& window) {
    window.draw(scoreText);
    window.draw(livesText);
}
