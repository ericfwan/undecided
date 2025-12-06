#pragma once
#include <vector>
#include <memory>
#include "Scene.hpp"

class Game;

// Simple stack-based scene manager.
// The top scene is the active one for input/update/draw.
// Use clear()+push() for hard transitions (e.g., Quit to Menu, Start Game).
class SceneManager {
public:
    SceneManager(Game& game) : game(game) {}

    // Push a scene onto the stack.
    void push(std::unique_ptr<Scene> scene) {
        stack.push_back(std::move(scene));
    }

    // Remove the top-most scene.
    void pop() {
        if (!stack.empty())
            stack.pop_back();
    }

    // Clear ALL scenes.
    // Useful for safe resets / returning to menu.
    void clear() {
        stack.clear();
    }

    // Get the current scene (top of stack).
    Scene* current() {
        if (stack.empty()) return nullptr;
        return stack.back().get();
    }

    // Helpful for debugging or guarded pops.
    size_t size() const {
        return stack.size();
    }

private:
    Game& game;
    std::vector<std::unique_ptr<Scene>> stack;
};
