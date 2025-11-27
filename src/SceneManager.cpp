#include "SceneManager.hpp"

void SceneManager::push(std::unique_ptr<Scene> scene) {
    scenes.push(std::move(scene));
}

void SceneManager::pop() {
    if (!scenes.empty())
        scenes.pop();
}

Scene* SceneManager::current() {
    if (scenes.empty())
        return nullptr;
    return scenes.top().get();
}
