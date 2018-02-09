#include <SFML/Graphics.hpp>
#include <SFML\Window\Event.hpp>
//#include "../Header/Snake.h"
//#include "../Header/Board.h"
#include "../Header/Game.h"
#include "../Header/Menu.h"
#include <iostream>
int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "Snake!");
	window.setPosition(sf::Vector2i(100, 100));
	//window.setSize(sf::Vector2u(400, 400));
	Menu menu;
	Game game;
	float skala;//ustawic skale i przy jej pomocy uzywac setsize i ustawiac pozycje kolizji menu z myszka
	while (true)
	{
		menu.start(window);
		game.start(window);//niech game przesyla okno do board a board pobiera wielkosc okna i ustawia identyczna wielkosc dla siebie
	}
	return 0;
}