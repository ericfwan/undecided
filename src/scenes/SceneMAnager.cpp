#include "SceneManager.hpp"

SceneManager::SceneManager() = default;

void SceneManager::push(std::unique_ptr<Scene> scene) {
    scenes.push_back(std::move(scene));
}

void SceneManager::pop() {
    if (!scenes.empty()) {
        scenes.pop_back();
    }
}

void SceneManager::clear() {
    scenes.clear();
}

Scene* SceneManager::current() {
    if (scenes.empty()) return nullptr;
    return scenes.back().get();
}
