#include <SFML/Graphics.hpp>
#include <SFML\Window\Event.hpp>
#include "../Header/Snake.h"
#include "../Header/Board.h"

int main()
{
	bool czy_zwiekszyc = false;
	bool czy_reagowac = true;
	static const sf::Time TIME_PER_FRAME = sf::seconds(0.1f);
	sf::Clock clock;
	sf::Time timeSinceLastRender = sf::Time::Zero;
	sf::Time deltaTime;
	Snake snake;
	Board board(sf::Vector2i(300, 300));
	sf::RenderWindow window(sf::VideoMode(300, 300), "SFML works!");
	window.setPosition(sf::Vector2i(100, 100));
	window.setSize(sf::Vector2u(800, 800));
	while (snake.isCollision(board.randFruitPosition()))
	{
		continue;
	}
	while (window.isOpen())
	{
		deltaTime = clock.restart();
		timeSinceLastRender += deltaTime;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && czy_reagowac)
		{
			snake.changeDirection(Snake::DIRECTION::RIGHT);
			czy_reagowac = false;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && czy_reagowac)
		{
			snake.changeDirection(Snake::DIRECTION::LEFT);
			czy_reagowac = false;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && czy_reagowac)
		{
			snake.changeDirection(Snake::DIRECTION::UP);
			czy_reagowac = false;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && czy_reagowac)
		{
			snake.changeDirection(Snake::DIRECTION::DOWN);
			czy_reagowac = false;
		}
		window.clear(sf::Color::White);
		while (timeSinceLastRender > TIME_PER_FRAME)
		{
			czy_reagowac = true;
			timeSinceLastRender -= TIME_PER_FRAME;
			if (czy_zwiekszyc)
			{
				snake.enlargeSnake();
				czy_zwiekszyc = false;
			}
			else
				snake.moveSnake();
			if (snake.isCollision(board.getFruitPosition()))
			{
				czy_zwiekszyc = true;
				while (snake.isCollision(board.randFruitPosition()))
				{
					continue;
				}
			}
			if (snake.isHeadBodyCollision())
			{
				//gameover
			}
			if (snake.getHeadPosition().x < 0 || snake.getHeadPosition().y < 0
				|| snake.getHeadPosition().x > board.getBoardSize().x || snake.getHeadPosition().y > board.getBoardSize().y)
			{
				//gameover
			}
		}
		snake.drawSnake(window);
		board.drawFruit(window);
		window.display();
	}
	return 0;
}