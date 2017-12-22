#include <SFML/Graphics.hpp>

#include "Board.h"
#include <iostream>
int main()
{
	Board board;
	
	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		board.draw(window);
		window.display();
	}

	return 0;
}