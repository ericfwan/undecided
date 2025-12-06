#include "scenes/ConfirmExit.hpp"
#include "scenes/MenuScene.hpp"
#include "ui/FontManager.hpp"
#include "Game.hpp"

ConfirmExit::ConfirmExit(Game& game)
: Scene(game)
, yesBtn("YES", 28)
, noBtn("NO", 28)
{
    auto& w = game.window;

    question.setFont(FontManager::get());
    question.setString("QUIT GAME?");
    question.setCharacterSize(54);
    question.setFillColor(sf::Color::White);

    auto qb = question.getLocalBounds();
    question.setOrigin(qb.width / 2, qb.height / 2);
    question.setPosition(w.getSize().x / 2, 250);

    float cx = w.getSize().x / 2;

    yesBtn.setPosition(cx - yesBtn.getWidth() - 20, 360);
    noBtn.setPosition(cx + 20, 360);
}

void ConfirmExit::handleEvent(sf::Event& event)
{
    auto& w = game.window;
    yesBtn.handleEvent(event, w);
    noBtn.handleEvent(event, w);
}

void ConfirmExit::update(float dt)
{
    auto& w = game.window;

    yesBtn.update(w);
    noBtn.update(w);

    if (yesBtn.isClicked(w)) {
        game.window.close();
    }

    if (noBtn.isClicked(w)) {
        game.scenes.pop(); // back to previous scene
    }
}

void ConfirmExit::draw(sf::RenderWindow& window)
{
    window.draw(question);
    yesBtn.draw(window);
    noBtn.draw(window);
}
