#include "scenes/MenuScene.hpp"
#include "scenes/GameScene.hpp"
#include "config.hpp"
#include <iostream>

MenuScene::MenuScene(sf::RenderWindow& window, SceneManager& manager)
    : Scene(window), sceneManager(manager)
{
    font.loadFromFile("assets/fonts/RobotoMono-Regular.ttf");

    background.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
    background.setFillColor(Style::Background);

    const int lineCount = 10;
    for (int i = 0; i < lineCount; i++) {
        sf::RectangleShape line;
        line.setSize({2.f, (float)window.getSize().y});

        float x = 50.f + i * 70.f;
        line.setPosition(x, 0);

        line.setFillColor(sf::Color(0, 255, 255, 70 + rand() % 120));

        neonLines.push_back(line);
        neonSpeeds.push_back(20.f + rand() % 40);
    }

    title.setFont(font);
    title.setString("UNDECIDED");
    title.setCharacterSize(Style::TitleFontSize);
    title.setFillColor(Style::NeonCyan);

    sf::FloatRect t = title.getLocalBounds();
    title.setOrigin(t.width / 2, t.height / 2);
    title.setPosition(window.getSize().x / 2, 120);

    playButton = new Button(font, "PLAY", Style::ButtonFontSize);
    optionsButton = new Button(font, "OPTIONS", Style::ButtonFontSize);
    exitButton = new Button(font, "EXIT", Style::ButtonFontSize);

    float cx = window.getSize().x / 2 - 100;

    playButton->setPosition(cx, 220);
    optionsButton->setPosition(cx, 220 + Style::ButtonSpacing);
    exitButton->setPosition(cx, 220 + 2 * Style::ButtonSpacing);

    playButton->setColors(Style::NeonCyan, Style::NeonMagenta);
    optionsButton->setColors(Style::NeonCyan, Style::NeonMagenta);
    exitButton->setColors(Style::NeonCyan, Style::NeonMagenta);

    playButton->setOutline(Style::ButtonOutlineThickness, Style::NeonCyan);
    optionsButton->setOutline(Style::ButtonOutlineThickness, Style::NeonCyan);
    exitButton->setOutline(Style::ButtonOutlineThickness, Style::NeonCyan);
}

void MenuScene::handleEvent(sf::Event& event) {
}

void MenuScene::update(float dt) {
    for (int i = 0; i < neonLines.size(); i++) {
        neonLines[i].move(neonSpeeds[i] * dt, 0);

        if (neonLines[i].getPosition().x > window.getSize().x)
            neonLines[i].setPosition(-20, 0);
    }

    playButton->update(window);
    optionsButton->update(window);
    exitButton->update(window);

    if (playButton->isClicked(window)) {
        std::cout << "Switching to GameScene...\n";
        sceneManager.push(std::make_unique<GameScene>(window, sceneManager));
    }

    if (optionsButton->isClicked(window)) {
        std::cout << "OPTIONS clicked\n";
    }

    if (exitButton->isClicked(window)) {
        window.close();
    }
}

void MenuScene::draw(sf::RenderWindow& window) {
    window.draw(background);

    for (auto& line : neonLines)
        window.draw(line);

    window.draw(title);

    playButton->draw(window);
    optionsButton->draw(window);
    exitButton->draw(window);
}
