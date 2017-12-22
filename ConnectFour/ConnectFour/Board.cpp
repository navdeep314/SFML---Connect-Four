#include "Board.h"

Board::Board() 
{
	mBoardRect = sf::RectangleShape(sf::Vector2f(BOARD_WIDTH, BOARD_HEIGHT));
	mBoardRect.setPosition(200.0f, 200.0f);

	for (int row = 0; row < 6; ++row)
	{

	}
}
Board::~Board()
{

}
void Board::draw(const sf::RenderWindow &window)
{

}