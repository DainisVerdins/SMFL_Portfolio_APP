#include<SFML/Graphics.hpp>
#include<iostream>

constexpr auto WINDOW_WIDTH = 640;
constexpr auto WINDOW_HEIGHT = 480;

int main(int argc, char** argv[]) {
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),"Bouncing mushroom.");
	sf::Texture mushroomTexture;

	if (!mushroomTexture.loadFromFile("./res/filename.png"))
	{
		return -1;
	}
	
	sf::Sprite mushroom(mushroomTexture);

	sf::Vector2u size = mushroomTexture.getSize();
	
	mushroom.setOrigin(size.x / 2, size.y / 2);
	sf::Vector2f increment(0.4f, 0.4f);

	


	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		if ((mushroom.getPosition().x + (size.x / 2) >window.getSize().x && increment.x > 0) ||
			(mushroom.getPosition().x - (size.x / 2) < 0 &&increment.x < 0))
		{
			// Reverse the direction on X axis.
			increment.x = -increment.x;
		}
		if ((mushroom.getPosition().y + (size.y / 2) >window.getSize().y && increment.y > 0) ||
			(mushroom.getPosition().y - (size.y / 2) < 0 &&increment.y < 0))
		{// Reverse the direction on Y axis.
			increment.y = -increment.y;
		}
		mushroom.setPosition(mushroom.getPosition() + increment);
		window.clear(sf::Color(16, 16, 16, 255)); // Dark gray.
		window.draw(mushroom); // Drawing our sprite.
		window.display();
	}
	return 0;
}