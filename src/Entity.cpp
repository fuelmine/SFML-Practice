#include "Entity.h"

void Entity::setVelocity(float vx, float vy)
{
    velocity_.x = vx;
    velocity_.y = vy;
}

void Entity::setVelocity(const sf::Vector2f& velocity)
{
    velocity_ = velocity;
}

const sf::Vector2f& Entity::getVelocity() const
{
    return velocity_;
}