#pragma once
#include <vector>
#include <memory>
#include "Scene.hpp"

class SceneManager {
public:
    SceneManager() = default;

    // Push a new scene onto the stack
    void push(std::unique_ptr<Scene> scene) {
        scenes.push_back(std::move(scene));
    }

    // Pop the top scene
    void pop() {
        if (!scenes.empty()) {
            scenes.pop_back();
        }
    }

    // Clear ALL scenes (used for returning to Main Menu)
    void clear() {
        scenes.clear();
    }

    // Get the current (top) scene
    Scene* current() {
        if (scenes.empty()) return nullptr;
        return scenes.back().get();
    }

private:
    std::vector<std::unique_ptr<Scene>> scenes;
};
