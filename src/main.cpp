// Tetris.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include<filesystem>
#include<string>
#include<SFML/Graphics.hpp> //sf namespace
#include<SFML/Audio.hpp>

constexpr auto FRAME_WIDTH = 680;
constexpr auto FRAME_HEIGHT = 480;
constexpr auto SHAPE_SIZE = 150.f;
namespace fs = std::filesystem;

int main()
{


	// create the window
	sf::RenderWindow  window(sf::VideoMode(FRAME_WIDTH, FRAME_HEIGHT), "First app", sf::Style::Close | sf::Style::Resize);
	sf::RectangleShape player(sf::Vector2f(SHAPE_SIZE, SHAPE_SIZE));
	player.setFillColor(sf::Color::Green);

	// run the program as long as the window is open
	while (window.isOpen()) {
		sf::Event evnt;
		
		//event loop
		while (window.pollEvent(evnt)) {
			

			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::TextEntered:
				std::printf("%c", evnt.text.unicode);
				//break;
				break;
			default:
				break;
				//return -1;
			}
		}

		//arrows control
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			player.move(0.1f,0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			player.move(0.0f, 0.1f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			player.move(-0.1f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			player.move(0.0f,-0.1f);
		}




		window.clear();

		window.draw(player);
		//end the current frame;
		window.display();
	}

	return 0;
}

