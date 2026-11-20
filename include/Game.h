#pragma once

#include <SFML/Graphics.hpp>

class Game
{
private:
    sf::RenderWindow window_;

public:
    Game();
    
    void run();

private:
    void processEvents();

    void render();

    void update(sf::Time deltaTime);

};