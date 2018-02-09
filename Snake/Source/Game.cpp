#include "../Header/Game.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML\Window\Event.hpp>
#include "../Header/Snake.h"
#include "../Header/Board.h"
Game::Game()
{
	over = false;
}
void Game::start(sf::RenderWindow & window)
{
	bool czy_zwiekszyc = false;
	bool czy_reagowac = true;
	float speed = 0.07;
	/*std::cout << "Podaj szybkosc weza (ilosc kratek na sekunde): ";
	std::cin >> speed;
	if (!std::cin)
		speed = 0.05;
	else
		speed = 1. / speed;
	*/
	//static const sf::Time TIME_PER_FRAME = sf::seconds(speed);// 0.05f); ststic const
	sf::Time TIME_PER_FRAME = sf::seconds(speed);// 0.05f); ststic const
	sf::Clock clock;
	sf::Time timeSinceLastRender = sf::Time::Zero;
	sf::Time deltaTime;
	Snake snake;
	Board board(sf::Vector2i(600, 600));
	/*sf::RenderWindow window(sf::VideoMode(300, 300), "Snake!");
	window.setPosition(sf::Vector2i(100, 100));
	window.setSize(sf::Vector2u(800, 800));
	*/
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
			if (event.type == sf::Event::KeyPressed)
				if (event.key.code == sf::Keyboard::Escape);
					//pauza
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
				gameOver();
				break;
			}
			if (snake.getHeadPosition().x < 0 || snake.getHeadPosition().y < 0
				|| snake.getHeadPosition().x >= board.getBoardSize().x || snake.getHeadPosition().y >= board.getBoardSize().y)
			{
				//gameover
				gameOver();
				break;
			}
		}
		if (over == true)
		{
			over = false;
			break;
		}
		snake.drawSnake(window);
		board.drawFruit(window);
		window.display();
	}
}

void Game::gameOver()
{
	std::cout << "\nKoniec gry :<\n";
	over = true;
}
