#pragma once
#include <vector>
#include <memory>
#include "Scene.hpp"

class SceneManager {
public:
    SceneManager();

    void push(std::unique_ptr<Scene> scene);
    void pop();
    void clear();
    Scene* current();

private:
    std::vector<std::unique_ptr<Scene>> scenes;
};
