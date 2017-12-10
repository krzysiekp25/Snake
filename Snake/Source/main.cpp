#include <SFML/Graphics.hpp>
#include <SFML\Window\Event.hpp>
#include "../Header/Snake.h"
#include "../Header/Board.h"

int main()
{
	bool czy_zwiekszyc = false;
	static const sf::Time TIME_PER_FRAME = sf::seconds(0.5f);
	sf::Clock clock;
	sf::Time timeSinceLastRender = sf::Time::Zero;
	sf::Time deltaTime;
	Snake snake;
	Board board(sf::Vector2i(200, 200));
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			snake.changeDirection(Snake::DIRECTION::RIGHT);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			snake.changeDirection(Snake::DIRECTION::LEFT);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			snake.changeDirection(Snake::DIRECTION::UP);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			snake.changeDirection(Snake::DIRECTION::DOWN);
		window.clear();
		while (timeSinceLastRender > TIME_PER_FRAME)
		{
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
		}
		snake.drawSnake(window);
		board.drawFruit(window);
		window.display();
	}
	return 0;
}