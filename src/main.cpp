// Tetris.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include<filesystem>
#include<string>
#include<SFML/Graphics.hpp> //sf namespace
#include"animation.h"
#include"player.h"
constexpr auto FRAME_WIDTH = 680;
constexpr auto FRAME_HEIGHT = 480;
constexpr auto SHAPE_SIZE = 150.f;

int main(){

	// create the window
	sf::RenderWindow  window(sf::VideoMode(FRAME_WIDTH, FRAME_HEIGHT), "SFML playground", sf::Style::Close | sf::Style::Resize);

	//sf::RectangleShape player(sf::Vector2f(SHAPE_SIZE, SHAPE_SIZE));
	//player.setPosition((FRAME_WIDTH / 2) - (SHAPE_SIZE / 2), (FRAME_HEIGHT / 2) - (SHAPE_SIZE / 2));

	

	sf::Texture playerTexture;
	playerTexture.loadFromFile("./res/tux_from_linux.png");//need to add relative path to image// why from uper level of project not from exe file?
	//player.setTexture(&playerTexture);

	//from with time one image switches to another
	const float imageSwitchTime = 0.2f;
	//Animation PlayerAnimation(&playerTexture, sf::Vector2u(3, 9), imageSwitchTime);
	
	Player player(&playerTexture, sf::Vector2u(3, 9), imageSwitchTime, 100.5f);
	
	float deltaTime = 0.3f;

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
		player.update( deltaTime);


		//displaying on screen part

		window.clear(sf::Color::White);
		player.draw(window);

		//end the current frame;
		window.display();

	}

	return 0;
}

