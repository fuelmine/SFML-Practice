#include <SFML/Graphics.hpp>
#include "SceneNode.h"
#include <stdexcept>
#include <algorithm>
#include <utility>
#include <memory>

void SceneNode::attachChild(SceneNodePtr child)
{
    if(!child)
        throw std::runtime_error("Cannot attach a null child");
    child->parent_ = this;
    children_.push_back(std::move(child));
}

SceneNode::SceneNodePtr SceneNode::detachChild(const SceneNode& node)
{
    auto iterator = std::find_if(children_.begin(), children_.end(),
        [&node](SceneNodePtr& child){ return child.get() == &node; });
    
    if(iterator == children_.end())
        throw std::runtime_error("That child does not exist!\n");
    
    SceneNodePtr result = std::move(*iterator);
    children_.erase(iterator);
    result->parent_ = nullptr;

    return result;
}

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    drawCurrent(target, states);

    for(const auto& child : children_)
    {
        child->draw(target, states);
    }
}

void SceneNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    
}


void SceneNode::update(sf::Time deltaTime)
{
    updateCurrent(deltaTime);
    updateChildren(deltaTime);
}

void SceneNode::updateCurrent(sf::Time deltaTime)
{

}

void SceneNode::updateChildren(sf::Time deltaTime)
{
    for(const auto& child : children_)
    {
        child->update(deltaTime);
    }
}

sf::Transform SceneNode::getWorldTransform() const
{
    sf::Transform transform = sf::Transform::Identity;

    for (const SceneNode* node = this; node != nullptr; node = node->parent_)
    {
        transform = node->getTransform() * transform;
    }

    return transform;
}

sf::Vector2f SceneNode::getWorldPosition() const
{
    return getWorldTransform() * sf::Vector2f();
}