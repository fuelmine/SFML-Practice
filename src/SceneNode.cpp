#include <SFML/Graphics.hpp>
#include "SceneNode.h"
#include <stdexcept>
#include <vector>
#include <memory>

void SceneNode::attachChild(SceneNodePtr child)
{
    child->parent_ = parent_;
    children_.push_back(std::move(child));
}

SceneNodePtr SceneNode::detachChild(const SceneNode& node)
{
    auto iterator = std::find_if(children_.begin(), children_.end()
        [&node](SceneNodePtr& child){ return child.get() == &node; });
    
    if(iterator == children_.end())
        throw std::runtime_error("That child does not exist!\n");
    
    SceneNodePtr result = std::move(*iterator);
    children_.erase(iterator);

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
