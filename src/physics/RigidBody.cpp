#include "physics/RigidBody.hpp"




void Physics::RigidBody::updateAABB() {
    if (type == ShapeType::Rectangle) {
        const sf::Vector2f half = size * 0.5f;
        aabb.min = position - half;
        aabb.max = position + half;
    } else if (type == ShapeType::Circle) {
        const sf::Vector2f r(radius, radius);
        aabb.min = position - r;
        aabb.max = position + r;
    }
}

void Physics::RigidBody::draw(sf::RenderWindow& window) const {
    if (type == ShapeType::Rectangle) {
        sf::RectangleShape rect(size);
        rect.setOrigin(origin);
        rect.setPosition(position);
        rect.setRotation(rotation);      // <---
        rect.setFillColor(colour);
        window.draw(rect);
    }
    else if (type == ShapeType::Circle) {
        sf::CircleShape circ(radius);
        circ.setOrigin(origin);
        circ.setPosition(position);
        circ.setRotation(rotation);       // <---
        circ.setFillColor(colour);
        window.draw(circ);
    }
}

void Physics::RigidBody::update(const float dt) {
    position += velocity * dt;
    rotation += angularVelocity * dt;
}


void Physics::RigidBody::setOrigin() {
    if (type == ShapeType::Rectangle) {
        origin = size * 0.5f;
    }
    else if (type == ShapeType::Circle) {
        origin = sf::Vector2f(radius, radius);
    }
}

void Physics::RigidBody::setPosition(const sf::Vector2f pos) {
    position = pos;
}

void Physics::RigidBody::setRotation(float angle) {
    rotation = angle;
}

void Physics::RigidBody::setSize(const sf::Vector2f size) {
    this->size = size;
}

void Physics::RigidBody::setColour(sf::Color colour) {
    this->colour = colour;
}

sf::Vector2f Physics::RigidBody::getSize() const {
    return size;
}

sf::Vector2f Physics::RigidBody::getPosition() const {
    return position;
}
float Physics::RigidBody::getRadius() const {
    return (type == ShapeType::Circle) ? radius : 0.f;
}


void Physics::RigidBody::move(const sf::Vector2f& offset) {
    position += offset;
}

void Physics::RigidBody::move(float x, float y) {
    position.x += x;
    position.y += y;
}

float Physics::RigidBody::getRotation() const {
    return rotation;
}

void Physics::RigidBody::rotate(const float angle) {
    rotation += angle;
}




