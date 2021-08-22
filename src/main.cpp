// Tetris.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>

#include<SFML/Graphics.hpp> //sf namespace

constexpr auto FRAME_WIDTH = 680;
constexpr auto FRAME_HEIGHT = 480;
constexpr auto SHAPE_SIZE = 150.f;

int main() 
{

	// create the window
	sf::RenderWindow  window(sf::VideoMode(FRAME_WIDTH, FRAME_HEIGHT), "SFML playground", sf::Style::Close | sf::Style::Resize);
	sf::View mainWiew(sf::Vector2f(0, 0), sf::Vector2f(FRAME_WIDTH, FRAME_HEIGHT));

	// run the program as long as the window is open
	while (window.isOpen()) {

		sf::Event evnt;
		//event loop
		while (window.pollEvent(evnt)) 
		{

			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			default:
				break;
			}
		}

		window.clear();

		//end the current frame;
		window.display();

	}

	return 0;
}

