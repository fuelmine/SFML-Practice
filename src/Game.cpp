#include "Game.h"


Game::Game() : window_{ sf::VideoMode({460, 680}), "SFML Application!"}
{

}

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
    while(window_.isOpen())
    {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while(timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        render();
    }
}

void Game::update(sf::Time deltaTime)
{

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