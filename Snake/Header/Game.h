#pragma once
#include <SFML/Graphics.hpp>
class Game
{
private:
	bool over;
public:
	Game();
	void start(sf::RenderWindow & window);
	void gameOver();
};