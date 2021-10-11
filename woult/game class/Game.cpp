#include "Game.h"
#include<iostream>
Game::Game(int width, int height, const std::string& label)
	: mWindow{ sf::VideoMode(width, height), label }
	, mPlayer{},
	mTexture{}
{

	if (!mTexture.loadFromFile("./res/plane_212.png"))
	{
		//some error handling
		std::cout << "Error can not load file\n";
	}
	mPlayer.setTexture(mTexture);
	mPlayer.setPosition(100.f,100.f);

	mIsMovingUp=false;
	 mIsMovingDown = false;
	 mIsMovingLeft = false;
	mIsMovingRight = false;

	TimePerFrame= sf::seconds(1.f / 60.f);//60fps

}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}
		render();
	}
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::W)
		mIsMovingUp = isPressed;
	else if (key == sf::Keyboard::S)
		mIsMovingDown = isPressed;
	else if (key == sf::Keyboard::A)
		mIsMovingLeft = isPressed;
	else if (key == sf::Keyboard::D)
		mIsMovingRight = isPressed;
}
//responsible for player input
void Game::processEvents()
{

	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
			break;
		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}

}
// updates the game logic 
// everything that happens int hte game
void Game::update(sf::Time deltaTime)
{
	
	sf::Vector2f movement(0.f, 0.f);
	if (mIsMovingUp)
		movement.y -= playerSpeed;
	if (mIsMovingDown)
		movement.y += playerSpeed;
	if (mIsMovingLeft)
		movement.x -= playerSpeed;
	if (mIsMovingRight)
		movement.x += playerSpeed;

	mPlayer.move(movement*deltaTime.asSeconds());
}
void Game::render()
{
	mWindow.clear();
	mWindow.draw(mPlayer);
	mWindow.display();
}