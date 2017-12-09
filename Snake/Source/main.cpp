#include <SFML/Graphics.hpp>
#include <SFML\Window\Event.hpp>
#include "../Header/Snake.h"

int main()
{
	static const sf::Time TIME_PER_FRAME = sf::seconds(0.5f);
	sf::Clock clock;
	sf::Time timeSinceLastRender = sf::Time::Zero;
	sf::Time deltaTime;
	Snake snake;
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

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
			snake.moveSnake();
		}
		snake.drawSnake(window);
		window.display();
	}
	return 0;
}