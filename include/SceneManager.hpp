#pragma once
#include <vector>
#include <memory>

#include "Scene.hpp"

class Game;

class SceneManager {
public:
    SceneManager(Game& game) : game(game) {}

    // Push a scene onto the stack
    void push(std::unique_ptr<Scene> scene) {
        stack.push_back(std::move(scene));
    }

    // Remove the top-most scene
    void pop() {
        if (!stack.empty())
            stack.pop_back();
    }

    // Clear ALL scenes (used for menu resets, game restarts)
    void clear() {
        stack.clear();
    }

    // Get the current scene (top of stack)
    Scene* current() {
        if (stack.empty()) return nullptr;
        return stack.back().get();
    }

private:
    Game& game;
    std::vector<std::unique_ptr<Scene>> stack;
};
