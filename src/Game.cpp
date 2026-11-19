#include "Game.h"


Game::Game() : window_{ sf::VideoMode({460, 680}), "SFML Application!"}
{

}

void Game::run()
{
    while(window_.isOpen())
    {
        processEvents();
        update();
        render();
    }
}


void Game::processEvents()
{
    while(const auto& event = window_.pollEvent())
    {
        if(event->is<sf::Event::Closed>())
        {
            window_.close();
        }
    }
}

void Game::render()
{
    window_.clear();
    window_.display();
}