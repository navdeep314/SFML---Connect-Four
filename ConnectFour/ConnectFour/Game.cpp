#include "Game.h"

Game::Game() : mWindow(sf::VideoMode(1280, 720), "Connect Four")
{

}
Game::~Game()
{

}
void Game::run()
{

	while (mWindow.isOpen())
	{
		sf::Event event;
		while (mWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				mWindow.close();
		}

		mWindow.clear();
		//.draw();
		mWindow.display();
	}



}