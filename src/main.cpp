// Tetris.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include<filesystem>
#include<string>
#include<SFML/Graphics.hpp> //sf namespace


constexpr auto FRAME_WIDTH = 680;
constexpr auto FRAME_HEIGHT = 480;
constexpr auto SHAPE_SIZE = 150.f;
namespace fs = std::filesystem;

int main()
{
	// create the window
	sf::RenderWindow  window(sf::VideoMode(FRAME_WIDTH, FRAME_HEIGHT), "First app", sf::Style::Close | sf::Style::Resize);
	
	sf::CircleShape pepeShape(SHAPE_SIZE);
	sf::Texture textureShape;

	fs::path pic_path{ "./res/background.jpg" };
	pic_path.make_preferred(); //makes to specific OS path

	if (!textureShape.loadFromFile(pic_path.string()))
	{
		std::cout << "the texture does not load\n";
		return -1;
	}

	pepeShape.setTexture(&textureShape);
	pepeShape.setPosition((FRAME_WIDTH / 2) - (SHAPE_SIZE / 2), (FRAME_HEIGHT / 2) - (SHAPE_SIZE / 2));

	//set picture size
	pepeShape.setOrigin(SHAPE_SIZE, SHAPE_SIZE);

	//background stuff
	sf::Sprite backgroundSprite;
	sf::Vector2 background_size = textureShape.getSize();


	//TODO need to make if background picture is smaller than screen size
	backgroundSprite.setTexture(textureShape);
	backgroundSprite.scale(sf::Vector2f(static_cast<float>(FRAME_WIDTH)/ background_size.x,
										static_cast<float>(FRAME_HEIGHT)/ background_size.y));


	// run the program as long as the window is open
	while (window.isOpen()) {
		sf::Event event;
		//event loop
		while (window.pollEvent(event)) {
			// "close requested" event: we close the window

			if (event.type == sf::Event::Closed) {
				window.close();
			}
			else if (event.type == sf::Event::KeyPressed)
			{

				if (event.key.code == sf::Keyboard::Right)
				{
					pepeShape.rotate(10.f);
				}
				else if (event.key.code == sf::Keyboard::Left) {
					pepeShape.rotate(-10.f);
				}
			}
		}

		window.clear();
		window.draw(backgroundSprite);
		window.draw(pepeShape);

		//end the current frame;
		window.display();
	}

	return 0;
}

