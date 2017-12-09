#pragma once
#include <SFML\System\Vector2.hpp>

class Board
{
private:
	sf::Vector2i boardSize;
	sf::Vector2i fruitPosition;
public:
	Board(sf::Vector2i v);

};