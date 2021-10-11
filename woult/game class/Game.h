#pragma once
#include <SFML/Graphics.hpp>
#include<string>
class Game
{
public:
	Game(int width,int height,const std::string&label );
	void run();
private:
	void handlePlayerInput(sf::Keyboard::Key key,bool isPressed);

	void processEvents();//  responsible for player input
	void update(sf::Time deltaTime); //updates the game
	void render();//renders object on screen
private:
	sf::RenderWindow mWindow;

	sf::Texture mTexture;
	sf::Sprite mPlayer;

	bool mIsMovingUp;
	bool mIsMovingDown;
	bool mIsMovingLeft;
	bool mIsMovingRight;

	float playerSpeed = 10.0f;
	sf::Time TimePerFrame ;
};

