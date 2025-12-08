#pragma once
#include "Scene.hpp"
#include "ui/Button.hpp"
#include <SFML/Graphics.hpp>

class Options : public Scene {
public:
    Options(Game& game);

    void handleEvent(sf::Event& event) override;
    void update(float dt) override;
    void draw(sf::RenderWindow& window) override;

private:
    void updateSelectionVisuals();

    // Labels
    sf::Text title;
    sf::Text ballLabel;
    sf::Text bgLabel;

    // Ball colour buttons
    Button redBtn;
    Button cyanBtn;
    Button greenBtn;
    Button whiteBtn;

    // Background colour buttons
    Button bgPurple;
    Button bgLime;
    Button bgCyan;

    // Save then Back
    Button saveBtn;
    Button backBtn;

    sf::Color selectedBallColor;
    sf::Color selectedBgColor;
};
