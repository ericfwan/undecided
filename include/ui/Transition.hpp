#pragma once
#include <SFML/Graphics.hpp>

class Transition {
public:
    Transition(float duration = 0.7f);

    void startFadeIn();
    void startFadeOut();
    void update(float dt);
    void draw(sf::RenderWindow& window);

    bool isFinished() const { return finished; }

private:
    enum State { None, FadeIn, FadeOut };
    State state = None;

    float timer = 0.f;
    float duration;
    bool finished = true;

    sf::RectangleShape overlay;
};
