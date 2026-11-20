#pragma once

#include <SFML/Graphics.hpp>
#include "SceneNode.h"
#include "ResourceHolder.h"
#include "AirCraft.h"

class World
{
public:
    explicit World(sf::RenderWindow& window);

    void update(sf::Time deltaTime);
    void draw();

private:
    void loadTextures();
    void buildScene();

private:
    enum class Layer
    {
        Background, Air, LayerCount
    };

private:
    sf::RenderWindow& window_;
    sf::View worldView_;
    TextureHolder textures_;
    SceneNode sceneGraph_;

    sf::FloatRect worldBorder_;
    sf::Vector2f spawnPosition_;
    float scrollSpeed_;
    AirCraft* playerAirCraft_;
};


World::World(sf::RenderWindow& window)
    : window_{ window }
    , 
{

}

void World::loadTextures()
{
    textures_.loadResource();
}
void World::update(sf::Time deltaTime)
{
    sceneGraph_.update(deltaTime);
}

