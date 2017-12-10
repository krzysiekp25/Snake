#include "../Header/Snake.h"

Snake::Snake()
{
	snakePosition.push_front(sf::Vector2i(10, 10));
	snakePosition.push_front(sf::Vector2i(10, 20));
	snakePosition.push_front(sf::Vector2i(10, 30));
	direction = DIRECTION::DOWN;
}

void Snake::changeDirection(DIRECTION d)//nie mozna skrecac do tylu
{
	switch (direction)
	{
	case DIRECTION::DOWN:
		if(d != DIRECTION::UP)
			direction = d;
		break;
	case DIRECTION::LEFT:
		if (d != DIRECTION::RIGHT)
			direction = d;
		break;
	case DIRECTION::RIGHT:
		if (d != DIRECTION::LEFT)
			direction = d;
		break;
	case DIRECTION::UP:
		if (d != DIRECTION::DOWN)
			direction = d;
		break;
	default:
		break;
	}
}

void Snake::enlargeSnake()
{
	sf::Vector2i temp = snakePosition.front();
	
	switch (direction)
	{
	case DIRECTION::DOWN:
		temp.y += 10;
		break;
	case DIRECTION::LEFT:
		temp.x -= 10;
		break;
	case DIRECTION::RIGHT:
		temp.x += 10;
		break;
	case DIRECTION::UP:
		temp.y -= 10;
		break;
	default:
		break;
	}
	snakePosition.push_front(temp);
}

void Snake::moveSnake()
{
	enlargeSnake();
	snakePosition.pop_back();
}

bool Snake::isCollision(sf::Vector2i v2i)
{
	bool returnValue = false;
	
	for (auto it = snakePosition.begin(); it != snakePosition.end(); it++)
	{
		if ((*it) == v2i)
			returnValue = true;
	}
	return returnValue;
}

void Snake::drawSnake(sf::RenderWindow & w)
{
	sf::RectangleShape r;
	r.setFillColor(sf::Color::Blue);
	r.setSize(sf::Vector2f(10,10));
	for (auto it = snakePosition.begin(); it != snakePosition.end(); it++)
	{
		r.setPosition((*it).x,(*it).y);
		w.draw(r);
	}
}

bool Snake::isHeadBodyCollision()
{
	bool returnValue = false;
	auto it = snakePosition.begin();
	for (it++; it != snakePosition.end(); it++)
	{
		if ((*it) == getHeadPosition())
			returnValue = true;
	}
	return returnValue;
}

sf::Vector2i Snake::getHeadPosition()
{
	return snakePosition.front();
}
