#include "scenes/ConfirmExit.hpp"
#include "Game.hpp"
#include "ui/FontManager.hpp"

#include <memory>

ConfirmExit::ConfirmExit(Game& game)
: Scene(game)
, yesBtn("YES", 28)
, noBtn("NO", 28)
{
    auto& w = game.window;

    title.setFont(FontManager::get());
    title.setString("EXIT GAME?");
    title.setCharacterSize(52);
    title.setFillColor(sf::Color::White);

    auto tb = title.getLocalBounds();
    title.setOrigin(tb.width / 2, tb.height / 2);
    title.setPosition(w.getSize().x / 2, 220);

    float cx = w.getSize().x / 2;

    yesBtn.setPosition(cx - yesBtn.getWidth() - 20, 340);
    noBtn.setPosition(cx + 20, 340);
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

    // Only close if YES was explicitly clicked.
    if (yesBtn.isClicked(w)) {
        game.window.close();
        return;
    }

    // NO simply removes this overlay.
    if (noBtn.isClicked(w)) {
        game.scenes.pop();
        return;
    }
}

void ConfirmExit::draw(sf::RenderWindow& window)
{
    window.draw(title);
    yesBtn.draw(window);
    noBtn.draw(window);
}
