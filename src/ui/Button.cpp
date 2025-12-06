#include "ui/Button.hpp"
#include "ui/FontManager.hpp"

Button::Button(const std::string& text, unsigned int charSize)
{
    box.setSize({260.f, 55.f});
    box.setFillColor(sf::Color(60, 60, 80));
    box.setOutlineThickness(3);
    box.setOutlineColor(normalOutline);

    label.setFont(FontManager::get());
    label.setString(text);
    label.setCharacterSize(charSize);
    label.setFillColor(sf::Color::White);

    fitText();
    centerText();
}

void Button::setPosition(float x, float y)
{
    box.setPosition(x, y);
    centerText();
}

void Button::setSize(float w, float h)
{
    box.setSize({w, h});
    fitText();
    centerText();
}

void Button::setFillColor(const sf::Color& c)
{
    box.setFillColor(c);
}

void Button::setOutlineColor(const sf::Color& c)
{
    box.setOutlineColor(c);
}

void Button::setSelected(bool state, const sf::Color& glowColor)
{
    selected = state;

    if (selected) {
        highlightOutline = glowColor;
        box.setOutlineColor(glowColor);
        box.setOutlineThickness(4.f);
    } else {
        box.setOutlineColor(normalOutline);
        box.setOutlineThickness(3.f);
    }
}

// Shrink label if it overflows the button width.
void Button::fitText()
{
    sf::FloatRect bounds = label.getLocalBounds();
    float padding = 20.f;

    while (bounds.width + padding > box.getSize().x && label.getCharacterSize() > 10)
    {
        label.setCharacterSize(label.getCharacterSize() - 2);
        bounds = label.getLocalBounds();
    }
}

// Center the label within the rectangle.
void Button::centerText()
{
    sf::FloatRect tb = label.getLocalBounds();

    label.setOrigin(tb.left + tb.width / 2, tb.top + tb.height / 2);
    label.setPosition(
        box.getPosition().x + box.getSize().x / 2,
        box.getPosition().y + box.getSize().y / 2 - 3
    );
}

void Button::handleEvent(const sf::Event& event, const sf::RenderWindow& window)
{
    (void)window; // Window not needed here, but kept in signature for consistency.

    // Start click only if mouse pressed within bounds.
    if (event.type == sf::Event::MouseButtonPressed &&
        event.mouseButton.button == sf::Mouse::Left)
    {
        if (box.getGlobalBounds().contains(
                {(float)event.mouseButton.x, (float)event.mouseButton.y}))
        {
            pressed = true;
        }
    }

    // Complete click only if press started on the button
    // and release also happens within bounds.
    if (event.type == sf::Event::MouseButtonReleased &&
        event.mouseButton.button == sf::Mouse::Left)
    {
        if (pressed &&
            box.getGlobalBounds().contains(
                {(float)event.mouseButton.x, (float)event.mouseButton.y}))
        {
            released = true;
        }
        pressed = false;
    }
}

void Button::update(const sf::RenderWindow& window)
{
    // Selected buttons keep their special outline style.
    if (selected) return;

    hovered = box.getGlobalBounds().contains(
        (sf::Vector2f)sf::Mouse::getPosition(window)
    );

    box.setFillColor(hovered ? sf::Color(80, 80, 110)
                             : sf::Color(60, 60, 80));
}

// One-shot click read.
// The scene reads this once; we reset immediately after.
bool Button::isClicked(const sf::RenderWindow& window)
{
    (void)window; // Unused; click state is event-driven.

    if (released) {
        released = false;
        return true;
    }
    return false;
}

void Button::draw(sf::RenderWindow& window) const
{
    window.draw(box);
    window.draw(label);
}
