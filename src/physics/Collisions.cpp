#include "physics/Collisions.hpp"


Physics::Collisions physics;
sf::Vector2f Physics::Collisions::get_Gravity() const {
    return gravity;
}
