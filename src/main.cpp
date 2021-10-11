#include<SFML/Graphics.hpp>


void initShape(sf::RectangleShape& shape, sf::Vector2f const& pos, sf::Color const& color) 
{
	shape.setFillColor(color);
	shape.setPosition(pos);
	shape.setOrigin(shape.getSize() * 0.5f);//center of rect
}

int main()
{
	sf::RenderWindow window{ sf::VideoMode{480,180},"bad squares"};
	//sets frames per second
	window.setFramerateLimit(60);

	sf::Vector2f startPos = sf::Vector2f{ 50,50 };
	sf::RectangleShape playerRect{ sf::Vector2f{ 50,50 } };
	initShape(playerRect, startPos,sf::Color::Green);

	sf::RectangleShape targetRect{ sf::Vector2f {50,50} };
	initShape(targetRect, sf::Vector2f{ 400,50 }, sf::Color::Blue);

	sf::RectangleShape badRect{ sf::Vector2f {50,100} };
	initShape(badRect, sf::Vector2f{ 250,50 }, sf::Color::Red);
	
	while (window.isOpen())
	{
		//handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			
			if (event.type==sf::Event::EventType::Closed)
			{
				window.close();
			}
			//Always moving rigth
			playerRect.move(1, 0);

			//directions of movement
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
			{
				playerRect.move(0, 1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
			{
				playerRect.move(0, -1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
			{
				playerRect.move(1, 0);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
			{
				playerRect.move(-1, 0);
			}

			//targer reached , you win exit game
			if (playerRect.getGlobalBounds().intersects(targetRect.getGlobalBounds())) 
			{
				window.close();
			}

			//bad squer intersects you ose and restart game
			if (playerRect.getGlobalBounds().intersects(badRect.getGlobalBounds()))
			{
				playerRect.setPosition(startPos);
			}

		}
		//update scene


		//Render cycle 
		window.clear(sf::Color::Black);

		window.draw(playerRect);
		window.draw(targetRect);
		window.draw(badRect);

		//render obj
		window.display();

	}
	return 0;
}