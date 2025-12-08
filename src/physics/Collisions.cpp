#include "physics/Collisions.hpp"
#include "physics/RigidBody.hpp"

namespace Physics {
    Collisions physics;
    sf::Vector2f Collisions::get_Gravity() const {
        return gravity;
    }

    void Physics::Collisions::checkCollisions(std::vector<RigidBody*>& bodies) {
        // Find the ball (usually the first dynamic object)
        RigidBody* ball = nullptr;
        std::vector<RigidBody*> staticBodies;

        for (auto body : bodies) {
            if (body->type == RigidBody::ShapeType::Circle) {
                ball = body;
            } else {
                staticBodies.push_back(body);
            }
        }

        if (!ball) return;

        // Check ball against all static bodies (paddle, bricks, walls)
        for (auto body : staticBodies) {
            if (checkAABB(ball, body)) {
                resolveBallCollision(ball, body);
            }
        }
    }

    bool Collisions::checkAABB(RigidBody* a, RigidBody* b) {
        return a->aabb.intersects(b->aabb);
    }

    void Collisions::resolveBallCollision(RigidBody* ball, RigidBody* other) {
        // Find which side of the rectangle the ball hit
        sf::Vector2f ballCenter = ball->position;

        float overlapLeft = (other->aabb.max.x - ballCenter.x);
        float overlapRight = (ballCenter.x - other->aabb.min.x);
        float overlapTop = (other->aabb.max.y - ballCenter.y);
        float overlapBottom = (ballCenter.y - other->aabb.min.y);

        // Find smallest overlap (side that was hit)
        float minOverlap = std::min({overlapLeft, overlapRight, overlapTop, overlapBottom});

        // Bounce based on which side was hit
        if (minOverlap == overlapLeft) {
            ball->velocity.x = -std::abs(ball->velocity.x);  // Bounce left
        }
        else if (minOverlap == overlapRight) {
            ball->velocity.x = std::abs(ball->velocity.x);   // Bounce right
        }
        else if (minOverlap == overlapTop) {
            ball->velocity.y = -std::abs(ball->velocity.y);  // Bounce up
        }
        else if (minOverlap == overlapBottom) {
            ball->velocity.y = std::abs(ball->velocity.y);   // Bounce down
        }
    }
}




/**void Physics::Collisions::collisions() {
    sf::Vector2f pos = ball.getPosition();
    float r = ball.getRadius();

    const sf::Vector2f pPos = platform.getPosition();
    const sf::Vector2f pSize = platform.getSize();

    const float left = pPos.x - pSize.x / 2.f;
    const float right = pPos.x + pSize.x / 2.f;
    const float top = pPos.y - pSize.y / 2.f;

    // Check horizontal overlap
    bool overPlatformX = pos.x + r > left && pos.x - r < right;

    // Check vertical overlap (ball descending)
    const bool hittingTop = pos.y + r > top && pos.y + r < top + 30.f;
    const bool movingDown = ball.velocity.y > 0;

    if (overPlatformX && hittingTop && movingDown) {
        // Place ball on platform
        ball.setPosition({pos.x, top - r});

        // Bounce
        ball.velocity.y = -std::abs(ball.velocity.y) * physics.bounceFactor;

        // Add spin effect depending on hit position
        float offset = (pos.x - pPos.x) / (pSize.x / 2.f);
        ball.velocity.x += offset * 200.f;
    }
}
**/