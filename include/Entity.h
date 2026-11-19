#pragma once

#include <SFML/Graphics.hpp>
#include <SceneNode.h>

class Entity : public SceneNode
{
private:
    sf::Vector2f velocity_;

public:
    void setVelocity(float vx, float vy);

    void setVelocity(const sf::Vector2f& velocity);

    const sf::Velocity& getVelocity() const;
};