#pragma once
#include <memory>
#include <stack>
#include "Scene.hpp"

class SceneManager {
public:
    void push(std::unique_ptr<Scene> scene);
    void pop();
    Scene* current();

private:
    std::stack<std::unique_ptr<Scene>> scenes;
};
