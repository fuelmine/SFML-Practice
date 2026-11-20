#pragma once

#include <SFML/Graphics.hpp>
#include "ResourceHolder.h"

namespace Textures
{
    enum class ID
    {
        Eagle, Raptor
    };
};

using TextureHolder = ResourceHolder<sf::Texture, Textures::ID>;