#pragma once
#include<SFML/Graphics.hpp>
#include"animation.h"

class Player{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Player();

	void update(float deltaTime);
	void draw(sf::RenderWindow & window);


private:
	
	sf::RectangleShape body;// body of image
	Animation animation;


	unsigned int row;//row index of animation in texture

	float speed;//speed of animation
	bool faceRigth;//animation faces rigth

};

