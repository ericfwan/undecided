#pragma once
#include <SFML/Graphics.hpp>

namespace Style
{
    // Neon Synthwave Palette
    static const sf::Color NeonCyan      = sf::Color(0, 255, 255);
    static const sf::Color NeonMagenta   = sf::Color(255, 0, 255);
    static const sf::Color Background    = sf::Color(10, 10, 20);  
    static const sf::Color White         = sf::Color(230, 230, 255);

    // UI Sizes
    static const unsigned int TitleSize       = 60;
    static const unsigned int ButtonFontSize  = 32;
    static const unsigned int HUDSize         = 22;

    static const float ButtonWidth  = 260.f;
    static const float ButtonHeight = 50.f;
    static const float ButtonSpacing = 70.f;

    // Glow Pulse Animation
    static const float GlowSpeed = 2.0f;

    // Neon Background Lines
    static const int NeonLineCount = 12;
    static const float NeonLineSpeedMin = 15.f;
    static const float NeonLineSpeedMax = 45.f;
}
