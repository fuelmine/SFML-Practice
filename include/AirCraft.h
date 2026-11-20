#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "TextureHolder.h"


class AirCraft : public Entity
{
public:
    enum class Type
    {
        Eagle, Raptor
    };

public:
    explicit AirCraft(Type type, const TextureHolder& textures);

private:

    void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;

    Type type_;
    sf::Sprite sprite_;
};
