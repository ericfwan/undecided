#include "ui/SoundBank.hpp"
#include <iostream>

SoundBank& SoundBank::get() {
    static SoundBank instance;
    return instance;
}

bool SoundBank::load(const std::string& id, const std::string& path) {
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile(path)) {
        std::cout << "Failed to load sound: " << path << "\n";
        return false;
    }

    buffers[id] = buffer;

    sf::Sound sound;
    sound.setBuffer(buffers[id]);
    sounds[id] = sound;

    return true;
}

void SoundBank::play(const std::string& id) {
   
    auto it = sounds.find(id);
    if (it != sounds.end()) {
        it->second.play();
    }
}
