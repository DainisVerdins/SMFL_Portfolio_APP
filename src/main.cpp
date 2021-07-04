// Tetris.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include<filesystem>
#include<string>
#include<SFML/Graphics.hpp> //sf namespace
#include"animation.h"

constexpr auto FRAME_WIDTH = 680;
constexpr auto FRAME_HEIGHT = 480;
constexpr auto SHAPE_SIZE = 150.f;

int main(){

	// create the window
	sf::RenderWindow  window(sf::VideoMode(FRAME_WIDTH, FRAME_HEIGHT), "SFML playground", sf::Style::Close | sf::Style::Resize);

	sf::RectangleShape player(sf::Vector2f(SHAPE_SIZE, SHAPE_SIZE));
	player.setPosition((FRAME_WIDTH / 2) - (SHAPE_SIZE / 2), (FRAME_HEIGHT / 2) - (SHAPE_SIZE / 2));

	sf::Texture playerTexture;
	playerTexture.loadFromFile("./res/tux_from_linux.png");//need to add relative path to image// why from uper level of project not from exe file?
	player.setTexture(&playerTexture);


	Animation PlayerAnimation(&playerTexture, sf::Vector2u(3, 9), 0.3f);

	float deltaTime = 0.f;
	sf::Clock clock;

	// run the program as long as the window is open
	while (window.isOpen()) {
		
		deltaTime = clock.restart().asSeconds();
		
		
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
			}
		}

		
		//animation part
		PlayerAnimation.update(3, deltaTime,false);
		player.setTextureRect(PlayerAnimation.uvRect);

		//displaying on screen part

		window.clear(sf::Color::White);
		window.draw(player);

		//end the current frame;
		window.display();
	}

	return 0;
}

