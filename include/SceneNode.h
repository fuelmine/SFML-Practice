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
	std::vector<SceneNodePtr> children_;

public:
	//Make it Uncopyable
	SceneNode() = default;
	SceneNode(const SceneNode& rhs) = delete;
	SceneNode& operator=(const SceneNode& rhs) = delete;

	void attachChild(SceneNodePtr child);
    SceneNodePtr detachChild(const SceneNode& node);

	void update(sf::Time deltaTime);

	sf::Vector2f getWorldPosition() const;
	
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

	virtual void updateCurrent(sf::Time deltaTime);
	virtual void updateChildren(sf::Time deltaTime);

	sf::Transform getWorldTransform() const;
};