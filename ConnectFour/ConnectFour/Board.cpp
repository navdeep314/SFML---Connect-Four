#include "Board.h"

Board::Board() 
{
	// Initialize Board Rectangle
	mBoardRect = sf::RectangleShape(sf::Vector2f(BOARD_WIDTH, BOARD_HEIGHT));
	mBoardRect.setPosition(BOARD_X_COORDINATE, BOARD_Y_COORDINATE);
	mBoardRect.setFillColor(sf::Color::Blue);

	// Initialize Board Chips
	for (int row = 0; row < 6; ++row)
	{
		for (int column = 0; column < 7; ++column)
		{
			mChips[row][column] = sf::CircleShape(CHIP_RADIUS);
			mChips[row][column].setOrigin(CHIP_RADIUS, CHIP_RADIUS);
			mChips[row][column].setPosition(BOARD_X_COORDINATE + 50 + (100 * column),
				BOARD_Y_COORDINATE + 50 + (100 * row));
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