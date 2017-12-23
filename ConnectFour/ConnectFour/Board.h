#pragma once

#include <SFML/Graphics.hpp>

#define BOARD_WIDTH 7
#define BOARD_HEIGHT 6
#define BOARD_GRAPHIC_WIDTH 700.0f
#define BOARD_GRAPHIC_HEIGHT 600.0f
#define BOARD_GRAPHIC_X_COORDINATE 290.0f
#define BOARD_GRAPHIC_Y_COORDINATE 60.0f

#define CHIP_GRAPHIC_RADIUS 40.0f

#define PLAYER1_CHIP_COLOR sf::Color::Red
#define PLAYER2_CHIP_COLOR sf::Color::Yellow

/**
Value enum type to represent each player.
Player 1, Player 2 and neither (empty).
*/
enum Value { Empty, Player1, Player2 };

/*
Game Board Class - Stores and draws all pieces
*/
class Board
{
	public:
		/**
		Board Constructor - Initializes Board graphics.
		*/
		Board();
		/**
		Board Deconstructor
		*/
		~Board();

		/**
		Draws board and pieces to window parameter
		*/
		void draw(sf::RenderWindow& window);
		/**
		Accepts int parameter for which column to add a chip of Player1's to.
		Returns bool; true if move was successful, false if it did not execute.
		*/
		bool movePlayer1(const int& column);
		/**
		Accepts int parameter for which column to add a chip of Player2's to.
		Returns bool; true if move was successful, false if it did not execute.
		*/
		bool movePlayer2(const int& column);

		/**
		Checks board to determine if the game is over.
		Returns empty if game is NOT over.
		If the game IS over, the winner is returned.
		*/
		Value checkForWinner();

	private:
		/**
		Accepts column number of board as parameter.
		Returns true if move to that column is valid, false if invalid.
		*/
		bool isMoveValid(const int& column);
		/**
		Accepts Value parameter for which Player is making the move, and
		int for which column to add a chip to.
		Returns bool; true if move was successful, false if it did not execute.
		*/
		bool move(const Value& player, const int& column);

		Value mValues[6][7] = { Empty }; // Store board values
		sf::RectangleShape mBoardRect; // Board rectangle
		sf::CircleShape mChips[6][7]; // Board chips

};