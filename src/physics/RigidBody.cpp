#include "physics/RigidBody.hpp"


void Physics::RigidBody::updateAABB() {
    sf::Vector2f const half = size * 0.5f;
    aabb.min = position - half;
    aabb.max = position + half;
}

void Physics::RigidBody::draw(sf::RenderWindow& window) const {
    if (type == ShapeType::Rectangle) {
        sf::RectangleShape rect(size);
        rect.setPosition(position);
        window.draw(rect);
    } else if (type == ShapeType::Circle) {
        sf::CircleShape circ(radius);
        circ.setPosition(position - sf::Vector2f(radius, radius)); // center correction
        window.draw(circ);
    }
}

void Physics::RigidBody::update(const float dt) {
    position += velocity * dt;
}


void Physics::RigidBody::setOrigin(sf::Vector2f origin) {

}

