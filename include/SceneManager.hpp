#pragma once
#include <vector>
#include <memory>
#include "Scene.hpp"

class Game;

// SceneManager: stack-based scene controller
// Includes a minimal deferred "replace root scene" mechanism so
// we never destroy the active scene inside its own update()
class SceneManager {
public:
    explicit SceneManager(Game& game) : game(game) {}

    // Push overlay scenes (Pause, Options, ConfirmExit)
    void push(std::unique_ptr<Scene> scene) {
        stack.push_back(std::move(scene));
    }

    // Pop top scene safely
    void pop() {
        if (!stack.empty())
            stack.pop_back();
    }

    // Access current top scene
    Scene* current() {
        if (stack.empty()) return nullptr;
        return stack.back().get();
    }

    size_t size() const { return stack.size(); }

    void requestReplaceRoot(std::unique_ptr<Scene> scene) {
        pendingReplaceRoot = std::move(scene);
    }

    // Apply deferred operation after update finishes
    void applyPending() {
        if (!pendingReplaceRoot) return;

        stack.clear();
        stack.push_back(std::move(pendingReplaceRoot));
    }

private:
    Game& game;
    std::vector<std::unique_ptr<Scene>> stack;

    std::unique_ptr<Scene> pendingReplaceRoot;
};

