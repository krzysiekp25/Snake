#pragma once
#include "Game.h"
#include <SFML/Graphics.hpp>
class Menu
{
private:
	sf::Vector2i mousePosition;
	sf::Vector2i mouseDelta;
	sf::Font font;
	sf::Text mainMenu[3];
	sf::Text options[2];
	enum MENU { MAIN_MENU, OPTIONS };
	MENU menuType;
	void setDifficulty(int speed);
	void startGame();
	void drawMenu(sf::RenderWindow & window);
public:
	Menu();
	void start(sf::RenderWindow & window);
	void exit();

};