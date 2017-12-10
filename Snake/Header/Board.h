#pragma once
#include <cstdlib>
#include <ctime>
#include <SFML\System\Vector2.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Graphics\RectangleShape.hpp>
#include <vector>

class Board
{
private:
	sf::Vector2i boardSize;
	sf::Vector2i fruitPosition;
	std::vector<sf::RectangleShape> line;
public:
	Board(sf::Vector2i v);
	sf::Vector2i randFruitPosition();
	sf::Vector2i getFruitPosition();
	void drawFruit(sf::RenderWindow & w);
	sf::Vector2i getBoardSize();
	
};