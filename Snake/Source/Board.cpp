#include "../Header/Board.h"

Board::Board(sf::Vector2i v)
{
	boardSize = v;
	fruitPosition = sf::Vector2i(0, 0);
	for (int i = 10; i < boardSize.x; i += 10)
	{
		sf::RectangleShape l(sf::Vector2f(1, boardSize.y));
		l.setPosition(i, 0);
		l.setFillColor(sf::Color::Color(105, 105, 105));
		line.push_back(l);
	}
	for (int i = 10; i < boardSize.y; i += 10)
	{
		sf::RectangleShape l(sf::Vector2f(boardSize.x, 1));
		l.setPosition(0, i);
		l.setFillColor(sf::Color::Color(105, 105, 105));
		line.push_back(l);
	}
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
	r.setFillColor(sf::Color::Green);
	r.setSize(sf::Vector2f(10, 10));
	r.setPosition(fruitPosition.x, fruitPosition.y);
	w.draw(r);
	auto it = line.begin();
	for (int i = 10; i < boardSize.x; i += 10)
	{
		w.draw((*it++));
	}
	for (int i = 10; i < boardSize.y; i += 10)
	{
		w.draw((*it++));
	}
	
}

sf::Vector2i Board::getBoardSize()
{
	return boardSize;
}

