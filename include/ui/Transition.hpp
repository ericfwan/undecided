#pragma once
#include <SFML/Graphics.hpp>

class Transition {
public:
    Transition();

    void startFadeIn(float duration = 0.6f);
    void startFadeOut(float duration = 0.6f);

    void update(float dt);
    void draw(sf::RenderWindow& window);

    bool isActive() const { return active; }
    bool isFinished() const;

private:
    float timer = 0.f;
    float duration = 0.6f;
    float alpha = 255.f;

    bool fadeIn = false;
    bool fadeOut = false;
    bool active = false;

    sf::RectangleShape overlay;
};
