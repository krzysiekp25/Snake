#include "../Header/Menu.h"
#include <SFML/Graphics.hpp>
#include <SFML\Window\Event.hpp>
#include <iostream>
void Menu::setDifficulty(int speed)
{
}

void Menu::startGame()
{
	//ustawiamy flage wyboru na rozpoczecie gry i wychodzimy z petli menu
	//w glownej petli programu program czyta flage i uruchamia gre
}

void Menu::drawMenu(sf::RenderWindow & window)
{
	window.draw(mainMenu[0]);//moje krztalty
}

Menu::Menu()
{
	mousePosition = sf::Mouse::getPosition();
	mouseDelta = sf::Vector2i(0, 0);
	menuType = MAIN_MENU;
	font.loadFromFile("arial.ttf");
	sf::Text text("hello", font);
	mainMenu[0].setFont(font);
	mainMenu[0].setString("START");
	mainMenu[0].setCharacterSize(30);
	mainMenu[0].setStyle(sf::Text::Bold);
	mainMenu[0].setFillColor(sf::Color::Red);
	mainMenu[0].setPosition(sf::Vector2f(100.0, 100.0));
}

void Menu::start(sf::RenderWindow & window)
{
	bool koniec = false;
	float speed;
	bool buttonPressed = false;
	sf::FloatRect bounding;
	
	while (window.isOpen())
	{
		mouseDelta = mousePosition - sf::Mouse::getPosition(window);
		mousePosition = sf::Mouse::getPosition(window);
		if (mouseDelta != sf::Vector2i(0, 0))
		{
			std::cout << "Pozycja " << mousePosition.x << " " << mousePosition.y << std::endl;
			bounding = mainMenu[0].getGlobalBounds();
			if (bounding.contains(mousePosition.x*1, mousePosition.y*1) == true)//skala 2x wieksze
			{
				std::cout << "Kolizja\n";
				mainMenu[0].setFillColor(sf::Color::Blue);
			}
			else
			{
				std::cout << "else\n";
				mainMenu[0].setFillColor(sf::Color::Red);
			}

			mouseDelta = sf::Vector2i(0, 0);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			buttonPressed = true;
		}
		else if(buttonPressed == true)
		{
			buttonPressed = false;
			if (bounding.contains(mousePosition.x * 1, mousePosition.y * 1) == true)//ustawic zmienne odpowiadaj¹ce za skalowanie
				koniec = true;
		}
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
				if (event.key.code == sf::Keyboard::Escape)
				{
					exit();
					koniec = true;
				}
		}
		if (koniec == true)
			break;
		window.clear(sf::Color::Black);
		
		
		drawMenu(window);
		window.display();
	}
}

void Menu::exit()
{
}
