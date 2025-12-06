#include "ui/HUD.hpp"
#include "ui/FontManager.hpp"

HUD::HUD()
{
    scoreText.setFont(FontManager::get());
    scoreText.setCharacterSize(28);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(20, 20);
}

void HUD::setScore(int s)
{
    score = s;
    scoreText.setString("Score: " + std::to_string(s));
}

void HUD::update(float dt)
{
    // could animate later
}

void HUD::draw(sf::RenderWindow& w)
{
    w.draw(scoreText);
}
