// Tetris.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


// left on adding to linker librarries of SFML



#include <iostream>
#include<SFML/Graphics.hpp>
constexpr auto FRAME_WIDTH = 680;
constexpr auto FRAME_HEIGHT = 480;


constexpr auto SHAPE_SIZE = 150.f;
//s

int main()
{
	// create the window
	sf::RenderWindow  window(sf::VideoMode(FRAME_WIDTH, FRAME_HEIGHT), "Hello World", sf::Style::Close | sf::Style::Resize);
	sf::CircleShape pepeShape(SHAPE_SIZE);
	sf::Texture textureShape;

	if (!textureShape.loadFromFile(".\\res\\background.jpg")) //Pepe path //D:\\Projects\\C++\\VisualTetris\\res\\pics\\pepe.png
	{
		std::cout << "the texture does not load\n";
		return -1;
	}


	pepeShape.setTexture(&textureShape);


	pepeShape.setPosition((FRAME_WIDTH / 2) - (SHAPE_SIZE / 2), (FRAME_HEIGHT / 2) - (SHAPE_SIZE / 2));
	// pepeShape.setRe
	pepeShape.setOrigin(SHAPE_SIZE, SHAPE_SIZE);

	//background stuff
	sf::Sprite backgroundSprite;
	sf::Vector2 size = textureShape.getSize();
	std::cout << size.x << " " << size.y << std::endl;
	backgroundSprite.setTexture(textureShape);
	backgroundSprite.scale(sf::Vector2f(0.66f, 0.52f));// frame_width/ texture_size.x
	//backgroundSprite.setOrigin(size480/1.x / 2, size.y / 2);




	// run the program as long as the window is open
	while (window.isOpen()) {
		sf::Event event;
		//event loop
		while (window.pollEvent(event)) {
			// "close requested" event: we close the window

			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::KeyPressed)
			{

				if (event.key.code == sf::Keyboard::Right)
				{
					pepeShape.rotate(10.f);
					//pepeShape.move(10, 0);
				}
				else if (event.key.code == sf::Keyboard::Left) {
					//pepeShape.move(-10, 0);
					pepeShape.rotate(-10.f);
				}
			}
		}
		window.clear();
		window.draw(backgroundSprite);
		//draw everything here 
		//shape.setFillColor(sf::Color(100, 250, 50));
		//shape.setRotation(45.f);



		window.draw(pepeShape);


		//end the current frame;
		window.display();


	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
