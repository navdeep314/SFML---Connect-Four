#pragma once

#include <SFML/Graphics.hpp>

#define BOARD_WIDTH 700.0f
#define BOARD_HEIGHT 600.0f

/*
Game Board Class - Stores and draws all pieces
*/
class Board
{
	public:
		enum Value { Empty, Player1, Player2 };
		Board();
		~Board();

		/*
		Draws board and pieces to window parameter
		*/
		void draw(const sf::RenderWindow &window);
		/*
		Checks board to determine if the game is over.
		Returns empty if game is NOT over.
		If the game IS over, the winner is returned.
		*/
		Value checkForWinner();

	private:
		Value mValues[6][7] = { Empty }; // Store board values
		sf::RectangleShape mBoardRect; // Board rectangle
		sf::CircleShape mChips[6][7]; // Board chips

};