#include "ui/Transition.hpp"
#include <algorithm>

Transition::Transition()
{
    overlay.setFillColor(sf::Color(0, 0, 0, 255));
    overlay.setSize({1920, 1080});
}

void Transition::startFadeIn(float d)
{
    duration = d;
    fadeIn = true;
    fadeOut = false;
    active = true;
    timer = 0;
    alpha = 255.f; 
}

void Transition::startFadeOut(float d)
{
    duration = d;
    fadeOut = true;
    fadeIn = false;
    active = true;
    timer = 0;
    alpha = 0.f;
}

bool Transition::isFinished() const
{
    return !active;
}

void Transition::update(float dt)
{
    if (!active) return;

    timer += dt;
    float t = std::min(timer / duration, 1.f);

    if (fadeIn)
        alpha = 255.f * (1.f - t);
    else if (fadeOut)
        alpha = 255.f * t;

    overlay.setFillColor(sf::Color(0, 0, 0, static_cast<sf::Uint8>(alpha)));

    if (t >= 1.f)
        active = false;
}

void Transition::draw(sf::RenderWindow& window)
{
    if (active)
        window.draw(overlay);
}
