#include "Game.h"

Game::Game() : mWindow(sf::VideoMode(1280, 720), "Connect Four"), mBoard()
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

			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					mBoard.movePlayer1(1);
				}
			}
		}

		mWindow.clear();
		mBoard.draw(mWindow);
 		mWindow.display();
	}



}