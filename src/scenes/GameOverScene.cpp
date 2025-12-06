#include "scenes/GameOverScene.hpp"
#include "ui/FontManager.hpp"
#include "Game.hpp"
#include "scenes/GameScene.hpp"
#include "scenes/MenuScene.hpp"
#include "scenes/ConfirmExit.hpp"

GameOverScene::GameOverScene(Game& game, int score)
: Scene(game)
, retryBtn("RETRY", 28)
, menuBtn("MAIN MENU", 26)
, exitBtn("EXIT GAME", 26)
{
    auto& w = game.window;

    title.setFont(FontManager::get());
    title.setString("GAME OVER");
    title.setCharacterSize(62);
    title.setFillColor(sf::Color::Red);

    auto tb = title.getLocalBounds();
    title.setOrigin(tb.width / 2, tb.height / 2);
    title.setPosition(w.getSize().x / 2, 120);

    scoreText.setFont(FontManager::get());
    scoreText.setString("Score: " + std::to_string(score));
    scoreText.setCharacterSize(32);
    scoreText.setFillColor(sf::Color::White);

    auto sb = scoreText.getLocalBounds();
    scoreText.setOrigin(sb.width / 2, sb.height / 2);
    scoreText.setPosition(w.getSize().x / 2, 190);

    float cx = w.getSize().x / 2;

    retryBtn.setPosition(cx - retryBtn.getWidth() / 2, 260);
    menuBtn.setPosition(cx - menuBtn.getWidth() / 2, 330);
    exitBtn.setPosition(cx - exitBtn.getWidth() / 2, 400);
}

void GameOverScene::handleEvent(sf::Event& event) {
    auto& w = game.window;

    retryBtn.handleEvent(event, w);
    menuBtn.handleEvent(event, w);
    exitBtn.handleEvent(event, w);
}

void GameOverScene::update(float dt) {
    auto& w = game.window;

    retryBtn.update(w);
    menuBtn.update(w);
    exitBtn.update(w);

    if (retryBtn.isClicked(w)) {
        game.scenes.pop();  
        game.scenes.push(std::make_unique<GameScene>(game));
    }

    if (menuBtn.isClicked(w)) {
        while (game.scenes.current()) game.scenes.pop();
        game.scenes.push(std::make_unique<MenuScene>(game));
    }

    if (exitBtn.isClicked(w)) {
        game.scenes.push(std::make_unique<ConfirmExit>(game));
    }
}

void GameOverScene::draw(sf::RenderWindow& window) {
    window.draw(title);
    window.draw(scoreText);
    retryBtn.draw(window);
    menuBtn.draw(window);
    exitBtn.draw(window);
}
