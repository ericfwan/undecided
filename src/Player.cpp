#include "Player.h"

Player::Player() {
    texture.loadFromFile("assets/player.png");
    sprite.setTexture(texture);
    sprite.setPosition(100.f, 100.f);
}

void Player::update(float dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        sprite.move(0.f, -speed * dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        sprite.move(0.f, speed * dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        sprite.move(-speed * dt, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        sprite.move(speed * dt, 0.f);
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
