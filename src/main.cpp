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

int main()
{


	// create the window
	sf::RenderWindow  window(sf::VideoMode(FRAME_WIDTH, FRAME_HEIGHT), "SFML playground", sf::Style::Close | sf::Style::Resize);
	
	sf::RectangleShape player(sf::Vector2f(SHAPE_SIZE, SHAPE_SIZE));
	player.setPosition((FRAME_WIDTH / 2) - (SHAPE_SIZE / 2), (FRAME_HEIGHT / 2) - (SHAPE_SIZE / 2));

	sf::Texture playerTexture;
	playerTexture.loadFromFile("./res/tux_from_linux.png");//need to add relative path to image// why from uper level of project not from exe file?
	player.setTexture(&playerTexture);

	sf::Vector2u textureSize = playerTexture.getSize();

	//get size of one pinguine block
	textureSize.x /= 3;
	textureSize.y /= 9;

	//get needed image part from whole image
	player.setTextureRect(sf::IntRect(textureSize.x * 2, textureSize.y * 8,textureSize.x,textureSize.y));

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
			default:
				break;
				//return -1;
			}
		}

		window.clear();

		window.draw(player);
		//end the current frame;
		window.display();
	}

	return 0;
}

