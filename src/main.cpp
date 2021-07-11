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

int main() {

	// create the window
	sf::RenderWindow  window(sf::VideoMode(FRAME_WIDTH, FRAME_HEIGHT), "SFML playground", sf::Style::Close | sf::Style::Resize);
	sf::View mainWiew(sf::Vector2f(0, 0), sf::Vector2f(FRAME_WIDTH, FRAME_HEIGHT));

	sf::Texture playerTexture;
	playerTexture.loadFromFile("./res/tux_from_linux.png");//need to add relative path to image// why from uper level of project not from exe file?

	//from with time one image switches to another
	const float imageSwitchTime = 0.2f;

	Player player(&playerTexture, sf::Vector2u(3, 9), imageSwitchTime, 100.5f);
	player.setPosition(sf::Vector2f((FRAME_WIDTH / 2) - (SHAPE_SIZE / 2), (FRAME_HEIGHT / 2) - (SHAPE_SIZE / 2)));

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

			case sf::Event::Resized: {
				//resize view
				float aspect_ratio = float(window.getSize().x) / float(window.getSize().y);
				mainWiew.setSize(FRAME_WIDTH * aspect_ratio, FRAME_HEIGHT);

				//mainWiew.setSize(evnt.size.width, evnt.size.height);
				break;
			}
			default:
				break;
			}
		}


		//animation part
		player.update(deltaTime);

		mainWiew.setCenter(player.getPosition());

		//displaying on screen part

		window.clear(sf::Color::White);
		window.setView(mainWiew);
		player.draw(window);

		//end the current frame;
		window.display();

	}

	return 0;
}

