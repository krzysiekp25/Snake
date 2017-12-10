#include "../Header/Board.h"

Board::Board(sf::Vector2i v)
{
	boardSize = v;
	fruitPosition = sf::Vector2i(0, 0);
}

sf::Vector2i Board::randFruitPosition()
{
	srand(time(NULL));
	sf::Vector2i temp;
	temp.x = (rand() % (boardSize.x / 10))*10;
	temp.y = (rand() % (boardSize.y / 10))*10;
	fruitPosition = temp;
	return temp;
}

sf::Vector2i Board::getFruitPosition()
{
	return fruitPosition;
}

void Board::drawFruit(sf::RenderWindow & w)
{
	sf::RectangleShape r;
	r.setFillColor(sf::Color::Blue);
	r.setSize(sf::Vector2f(10, 10));
	r.setPosition(fruitPosition.x, fruitPosition.y);
	w.draw(r);
}

