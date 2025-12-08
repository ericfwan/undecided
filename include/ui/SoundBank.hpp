#pragma once
#include <SFML/Audio.hpp>
#include <map>
#include <string>

class SoundBank {
public:
    static SoundBank& get();

    bool load(const std::string& id, const std::string& path);

    void play(const std::string& id);

private:
    SoundBank() = default;

    std::map<std::string, sf::SoundBuffer> buffers;
    std::map<std::string, sf::Sound> sounds;
};
