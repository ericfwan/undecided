#include "scenes/MenuScene.hpp"
#include "Game.hpp"
#include "ui/FontManager.hpp"
#include "scenes/GameScene.hpp"
#include "scenes/Options.hpp"
#include "scenes/ConfirmExit.hpp"
#include <memory>

MenuScene::MenuScene(Game& game)
: Scene(game)
, playButton("PLAY", 32)
, optionsButton("OPTIONS", 32)
, exitButton("EXIT", 32)
{
    auto& w = game.window;

    title.setFont(FontManager::get());
    title.setString("UNDECIDED");
    title.setCharacterSize(64);
    title.setFillColor(sf::Color::Cyan);

    auto b = title.getLocalBounds();
    title.setOrigin(b.width / 2.f, b.height / 2.f);
    title.setPosition(w.getSize().x / 2.f, 120.f);

    float cx = w.getSize().x / 2.f;

    playButton.setPosition(cx - playButton.getWidth() / 2.f, 250.f);
    optionsButton.setPosition(cx - optionsButton.getWidth() / 2.f, 320.f);
    exitButton.setPosition(cx - exitButton.getWidth() / 2.f, 390.f);
}

void MenuScene::handleEvent(sf::Event& event)
{
    auto& w = game.window;

    playButton.handleEvent(event, w);
    optionsButton.handleEvent(event, w);
    exitButton.handleEvent(event, w);
}

void MenuScene::update(float dt)
{
    auto& w = game.window;

    // Hover visual updates
    playButton.update(w);
    optionsButton.update(w);
    exitButton.update(w);


    if (playButton.isClicked(w)) {
        game.scenes.requestReplaceRoot(std::make_unique<GameScene>(game));
        return;
    }

    
    if (optionsButton.isClicked(w)) {
        game.scenes.push(std::make_unique<Options>(game));
        return;
    }

    // EXIT
    if (exitButton.isClicked(w)) {
        game.scenes.push(std::make_unique<ConfirmExit>(game));
        return;
    }

    (void)dt; 
}

void MenuScene::draw(sf::RenderWindow& window)
{
    window.draw(title);

    playButton.draw(window);
    optionsButton.draw(window);
    exitButton.draw(window);
}
