#include "scenes/Options.hpp"
#include "Game.hpp"
#include "ui/FontManager.hpp"
#include "scenes/MenuScene.hpp"

Options::Options(Game& game)
    : Scene(game)
    , redBtn("RED", 24)
    , cyanBtn("CYAN", 24)
    , greenBtn("GREEN", 24)
    , whiteBtn("WHITE", 24)
    , bgPurple("PURPLE", 24)
    , bgLime("LIME", 24)
    , bgCyan("CYAN", 24)
    , saveBtn("SAVE", 26)
    , backBtn("BACK", 26)
{
    auto& window = game.window;

    selectedBallColor = game.ballColor;
    selectedBgColor   = game.neonColor;

    // Title
    title.setFont(FontManager::get());
    title.setString("OPTIONS");
    title.setCharacterSize(54);
    title.setFillColor(sf::Color::White);
    auto tb = title.getLocalBounds();
    title.setOrigin(tb.width / 2, tb.height / 2);
    title.setPosition(window.getSize().x / 2, 80);

    // Labels
    ballLabel.setFont(FontManager::get());
    ballLabel.setString("BALL COLOR:");
    ballLabel.setCharacterSize(28);
    ballLabel.setPosition(120, 180);

    bgLabel.setFont(FontManager::get());
    bgLabel.setString("BACKGROUND:");
    bgLabel.setCharacterSize(28);
    bgLabel.setPosition(120, 330);

    // Ball colors row
    redBtn.setPosition(350, 170);
    cyanBtn.setPosition(520, 170);
    greenBtn.setPosition(690, 170);
    whiteBtn.setPosition(860, 170);

    redBtn.setFillColor(sf::Color::Red);
    cyanBtn.setFillColor(sf::Color::Cyan);
    greenBtn.setFillColor(sf::Color::Green);
    whiteBtn.setFillColor(sf::Color::White);

    // Background colors row
    bgPurple.setPosition(350, 330);
    bgLime.setPosition(520, 330);
    bgCyan.setPosition(690, 330);

    bgPurple.setFillColor(sf::Color(180, 0, 255));
    bgLime.setFillColor(sf::Color::Green);
    bgCyan.setFillColor(sf::Color::Cyan);

    // SAVE + BACK
    float cx = window.getSize().x / 2;
    saveBtn.setPosition(cx - saveBtn.getWidth() - 20, 500);
    backBtn.setPosition(cx + 20, 500);

    updateSelectionVisuals();
}

void Options::handleEvent(sf::Event& event)
{
    auto& w = game.window;

    // Ball
    redBtn.handleEvent(event, w);
    cyanBtn.handleEvent(event, w);
    greenBtn.handleEvent(event, w);
    whiteBtn.handleEvent(event, w);

    // Background
    bgPurple.handleEvent(event, w);
    bgLime.handleEvent(event, w);
    bgCyan.handleEvent(event, w);

    // Save / Back
    saveBtn.handleEvent(event, w);
    backBtn.handleEvent(event, w);
}

void Options::update(float dt)
{
    auto& w = game.window;

    // Hover updates
    redBtn.update(w);
    cyanBtn.update(w);
    greenBtn.update(w);
    whiteBtn.update(w);

    bgPurple.update(w);
    bgLime.update(w);
    bgCyan.update(w);

    saveBtn.update(w);
    backBtn.update(w);

    // Ball selection
    if (redBtn.isClicked(w))      selectedBallColor = sf::Color::Red;
    if (cyanBtn.isClicked(w))     selectedBallColor = sf::Color::Cyan;
    if (greenBtn.isClicked(w))    selectedBallColor = sf::Color::Green;
    if (whiteBtn.isClicked(w))    selectedBallColor = sf::Color::White;

    // Background selection
    if (bgPurple.isClicked(w))    selectedBgColor = sf::Color(180, 0, 255);
    if (bgLime.isClicked(w))      selectedBgColor = sf::Color::Green;
    if (bgCyan.isClicked(w))      selectedBgColor = sf::Color::Cyan;

    updateSelectionVisuals();

    // SAVE then apply 
    if (saveBtn.isClicked(w)) {
        game.ballColor = selectedBallColor;
        game.neonColor = selectedBgColor;
        game.background.setColor(selectedBgColor);
        game.scenes.pop(); // go back to main menu
    }

    // BACK don’t save, just leave
    if (backBtn.isClicked(w)) {
        game.scenes.pop();
    }
}

void Options::updateSelectionVisuals()
{
    redBtn.setSelected(false);
    cyanBtn.setSelected(false);
    greenBtn.setSelected(false);
    whiteBtn.setSelected(false);

    bgPurple.setSelected(false);
    bgLime.setSelected(false);
    bgCyan.setSelected(false);

    // Ball
    if (selectedBallColor == sf::Color::Red)      redBtn.setSelected(true, sf::Color::Red);
    if (selectedBallColor == sf::Color::Cyan)     cyanBtn.setSelected(true, sf::Color::Cyan);
    if (selectedBallColor == sf::Color::Green)    greenBtn.setSelected(true, sf::Color::Green);
    if (selectedBallColor == sf::Color::White)    whiteBtn.setSelected(true, sf::Color(200,200,200));

    // Background
    if (selectedBgColor == sf::Color(180,0,255))  bgPurple.setSelected(true, sf::Color(180,0,255));
    if (selectedBgColor == sf::Color::Green)      bgLime.setSelected(true, sf::Color::Green);
    if (selectedBgColor == sf::Color::Cyan)       bgCyan.setSelected(true, sf::Color::Cyan);
}

void Options::draw(sf::RenderWindow& window)
{
    window.draw(title);
    window.draw(ballLabel);
    window.draw(bgLabel);

    redBtn.draw(window);
    cyanBtn.draw(window);
    greenBtn.draw(window);
    whiteBtn.draw(window);

    bgPurple.draw(window);
    bgLime.draw(window);
    bgCyan.draw(window);

    saveBtn.draw(window);
    backBtn.draw(window);
}
