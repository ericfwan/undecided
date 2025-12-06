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

    if (resumeBtn.isClicked(w)) {
        game.scenes.pop(); // back to gameplay
    }

    if (restartBtn.isClicked(w)) {
        game.scenes.pop();                 // remove pause
        game.scenes.pop();                 // remove game
        game.scenes.push(std::make_unique<GameScene>(game));
    }

    if (quitBtn.isClicked(w)) {
        game.scenes.pop();                 // remove pause
        game.scenes.pop();                 // remove game
        game.scenes.push(std::make_unique<MenuScene>(game));
    }
}

void PauseScene::draw(sf::RenderWindow& window)
{
    window.draw(pausedLabel);
    resumeBtn.draw(window);
    restartBtn.draw(window);
    quitBtn.draw(window);
}
