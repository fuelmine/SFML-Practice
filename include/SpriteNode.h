#pragma once

#include <SFML/Graphics.hpp>
#include "SceneNode.h"


class SpriteNode : public SceneNode
{
public:
    explicit SpriteNode(const sf::Texture& texture);
    SpriteNode(const sf::Texture& texture, const sf::IntRect& rect);

private:
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    sf::Sprite sprite_;
};

SpriteNode::SpriteNode(const sf::Texture& texture)
    : sprite_{ texture }
{
    
}

void SpriteNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
[
    target.draw(sprite_, target);
]