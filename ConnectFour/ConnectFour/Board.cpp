#include "Board.h"

Board::Board() 
{
	// Initialize Board Rectangle
	mBoardRect = sf::RectangleShape(sf::Vector2f(BOARD_GRAPHIC_WIDTH, BOARD_GRAPHIC_HEIGHT));
	mBoardRect.setPosition(BOARD_GRAPHIC_X_COORDINATE, BOARD_GRAPHIC_Y_COORDINATE);
	mBoardRect.setFillColor(sf::Color::Blue);

	// Initialize Board Chips
	for (int row = 0; row < 6; ++row)
	{
		for (int column = 0; column < 7; ++column)
		{
			mChips[row][column] = sf::CircleShape(CHIP_GRAPHIC_RADIUS);
			mChips[row][column].setOrigin(CHIP_GRAPHIC_RADIUS, CHIP_GRAPHIC_RADIUS);
			mChips[row][column].setPosition(BOARD_GRAPHIC_X_COORDINATE + 50 + (100 * column),
				BOARD_GRAPHIC_Y_COORDINATE + 50 + (100 * row));
			mChips[row][column].setFillColor(sf::Color::Black);
		}
	}
}
Board::~Board()
{

}
void Board::draw(sf::RenderWindow &window)
{
	// Draw board
	window.draw(mBoardRect);

	// Draw chips
	for(int row = 0; row < 6; ++row)
	{
		for (int column = 0; column < 7; ++column)
		{
			window.draw(mChips[row][column]);
		}
	}
	
}

bool Board::isMoveValid(const int &column)
{
	bool valid = false;

	// Move is valid if the top spot in choosen column is empty
	if (mValues[0][column] == Empty)
	{
		valid = true;
	}
	return valid;
}
bool Board::move(const Value& player, const int& column)
{
	bool valid = false;
	
	// Determine if move at column is valid
	valid = isMoveValid(column);

	// Add a chip to this column
	if (valid)
	{
		// Find the bottom most empty spot in column
		int row = (BOARD_HEIGHT - 1);
		
		while(mValues[row][column] != Empty)
		{
			--row;
		}

		// Add a chip of player's color to this spot
		if (player == Player1)
		{
			mChips[row][column].setFillColor(PLAYER1_CHIP_COLOR);

		}
		else if (player == Player2)
		{
			mChips[row][column].setFillColor(PLAYER2_CHIP_COLOR);
		}
		// Update Board Values
		mValues[row][column] = player;
	}

	return valid;
}
bool Board::movePlayer1(const int& column)
{
	// Move Player1's chip to column if possible
	return move(Player1, column);
}

bool Board::movePlayer2(const int& column)
{
	// Move Player2's chip to column if possible
	return move(Player2, column);
}
Value Board::checkForWinner()
{
	return Empty;
}
