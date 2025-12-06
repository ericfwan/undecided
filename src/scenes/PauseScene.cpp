#include "scenes/PauseScene.hpp"
#include "scenes/GameScene.hpp"
#include "scenes/MenuScene.hpp"
#include "ui/FontManager.hpp"
#include "Game.hpp"

PauseScene::PauseScene(Game& game)
: Scene(game)
, resumeBtn("RESUME", 28)
, restartBtn("RESTART", 28)
, quitBtn("QUIT", 28)
{
    auto& w = game.window;

    pausedLabel.setFont(FontManager::get());
    pausedLabel.setString("PAUSED");
    pausedLabel.setCharacterSize(60);
    pausedLabel.setFillColor(sf::Color::White);

    auto pb = pausedLabel.getLocalBounds();
    pausedLabel.setOrigin(pb.width / 2, pb.height / 2);
    pausedLabel.setPosition(w.getSize().x / 2, 200);

    float cx = w.getSize().x / 2;

    resumeBtn.setPosition(cx - resumeBtn.getWidth() / 2, 330);
    restartBtn.setPosition(cx - restartBtn.getWidth() / 2, 410);
    quitBtn.setPosition(cx - quitBtn.getWidth() / 2, 490);
}

void PauseScene::handleEvent(sf::Event& event)
{
    auto& w = game.window;

    // ESC while paused should resume.
    if (event.type == sf::Event::KeyPressed &&
        event.key.code == sf::Keyboard::Escape)
    {
        game.scenes.pop();
        return;
    }

    resumeBtn.handleEvent(event, w);
    restartBtn.handleEvent(event, w);
    quitBtn.handleEvent(event, w);
}

void PauseScene::update(float dt)
{
    auto& w = game.window;

    resumeBtn.update(w);
    restartBtn.update(w);
    quitBtn.update(w);

    // Resume: just remove the pause scene.
    if (resumeBtn.isClicked(w)) {
        game.scenes.pop();
        return;
    }

    // Restart: hard reset to a fresh GameScene.
    // This avoids relying on fragile "pop twice" assumptions.
    if (restartBtn.isClicked(w)) {
        game.scenes.clear();
        game.scenes.push(std::make_unique<GameScene>(game));
        return;
    }

    // Quit: hard reset back to Menu.
    // Clean, predictable, no stack ghosts.
    if (quitBtn.isClicked(w)) {
        game.scenes.clear();
        game.scenes.push(std::make_unique<MenuScene>(game));
        return;
    }
}

void PauseScene::draw(sf::RenderWindow& window)
{
    window.draw(pausedLabel);
    resumeBtn.draw(window);
    restartBtn.draw(window);
    quitBtn.draw(window);
}
