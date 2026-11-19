#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <unordered_map>
#include <vector>
#include <memory>
#include <string>


int main()
{
	sf::RenderWindow window(sf::VideoMode({100, 100}), "SFML Test");

	while(window.isOpen())
	{
		while(auto event = window.pollEvent())
		{
			if(event->is<sf::Event::Closed>())
			{
				window.close();
			}
		}
		window.clear();
		window.display();
	}

	return 0;
}




