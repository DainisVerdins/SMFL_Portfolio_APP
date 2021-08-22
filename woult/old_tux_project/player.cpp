#include "player.h"
#include<iostream>
Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed)
	:animation(texture, imageCount, switchTime)
{
	this->faceRigth = true;
	this->speed = speed;

	body.setSize(sf::Vector2f(150.0f, 150.0f));
	body.setOrigin(body.getSize() / 2.0f);

	body.setPosition(sf::Vector2f(260.0f, 160.0f));
	this->row = 0;
	this->body.setTexture(texture);

}

Player::~Player()
{
}

void Player::update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);

	//kaypress control part
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		movement.x -= speed * deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		movement.x += speed * deltaTime;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		movement.y += speed * deltaTime;

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		movement.y -= speed * deltaTime;
	}

	//from where image draw side start
	if (movement.x == 0.f)
	{
		//from left side draw image
		this->row = 0;
	}
	else
	{
		//from rigth side draw image
		this->row = 1;

		//on with direction is image will watch 
		if (movement.x > 0.0f)// is  animation goes to rigth
		{
			this->faceRigth = true;
		}
		else {
			this->faceRigth = false;
		}
	}

	this->animation.update(row, deltaTime, this->faceRigth);
	this->body.setTextureRect(animation.uvRect);
	this->body.move(movement);
}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(body);
}
