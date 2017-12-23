#pragma once

#include <SFML/Graphics.hpp>
#include "Board.h"

class Game
{
	public:
		Game();
		~Game();
		void run();

	private:
		//void drawObjects();

		sf::RenderWindow mWindow;
		Board mBoard;
};