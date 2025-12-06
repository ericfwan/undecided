#pragma once
#include <SFML/Graphics.hpp>
#include <string>

// Simple UI button with basic hover + click state.
// Click is detected using press+release inside the button bounds.
class Button {
public:
    Button(const std::string& text, unsigned int charSize = 28);

    void setPosition(float x, float y);
    void setSize(float w, float h);

    void setFillColor(const sf::Color& c);
    void setOutlineColor(const sf::Color& c);

    // Selected state used for option toggles (e.g., colour pickers).
    void setSelected(bool state, const sf::Color& glowColor = sf::Color::Transparent);

    void handleEvent(const sf::Event& event, const sf::RenderWindow& window);
    void update(const sf::RenderWindow& window);
    void draw(sf::RenderWindow& window) const;

    // Returns true once per completed click.
    bool isClicked(const sf::RenderWindow& window);

    float getWidth() const { return box.getSize().x; }
    float getHeight() const { return box.getSize().y; }

private:
    sf::RectangleShape box;
    sf::Text label;

    bool hovered = false;
    bool pressed = false;
    bool released = false;
    bool selected = false;

    sf::Color normalOutline = sf::Color(70, 70, 90);
    sf::Color highlightOutline = normalOutline;

    void fitText();
    void centerText();
};
