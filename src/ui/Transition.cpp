#include "ui/Transition.hpp"

Transition::Transition(float duration)
: duration(duration) {
    overlay.setFillColor(sf::Color(0, 0, 0, 255));
    overlay.setSize({1200, 800}); // dynamically resized later
}

void Transition::startFadeIn() {
    state = FadeIn;
    timer = 0.f;
    finished = false;
}

void Transition::startFadeOut() {
    state = FadeOut;
    timer = 0.f;
    finished = false;
}

void Transition::update(float dt) {
    if (state == None) return;

    timer += dt;
    float t = std::min(timer / duration, 1.f);

    if (state == FadeIn) {
        int alpha = 255 - static_cast<int>(255 * t);
        overlay.setFillColor(sf::Color(0,0,0,alpha));
    } else {
        int alpha = static_cast<int>(255 * t);
        overlay.setFillColor(sf::Color(0,0,0,alpha));
    }

    if (t >= 1.f) {
        finished = true;
        state = None;
    }
}

void Transition::draw(sf::RenderWindow& window) {
    window.draw(overlay);
}
