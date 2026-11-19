#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class SceneNode : public sf::Drawable, public sf::Transformable
{
public:
	using SceneNodePtr = std::unique_ptr<SceneNode>;

private:
	SceneNode* parent_;
	std::vector<SceneNode> children_;

public:
	void attachChild(SceneNodePtr child);
    SceneNodePtr detachChild(const SceneNode& node);
	
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void drawCurrent(sf::RenderTraget& target, sf::RenderStates states) const;
};