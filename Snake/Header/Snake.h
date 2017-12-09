#pragma once
#include <list>
#include <SFML\System\Vector2.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Graphics\RectangleShape.hpp>


class Snake
{
public:
	enum DIRECTION { RIGHT, LEFT, UP, DOWN };
private:
	std::list<sf::Vector2i> snakePosition;
	DIRECTION direction;
public:
	Snake();
	void changeDirection(DIRECTION d);//na tej podstawie wiadomo jak przesunac snake'a
	void enlargeSnake();//zwieksza wielkosc dodajac blok z przodu
	void moveSnake();//aktualizuje pozycje o jeden ruch
	bool isCollision(sf::Vector2i v2i);//do sprawdzania kolizji z jedzeniem
	void drawSnake(sf::RenderWindow & w);
};