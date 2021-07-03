#pragma once
#include<SFML/Graphics.hpp>

/*
//animation class for image animation using SFML graphics lib

*/
class Animation
{
public:
	Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	~Animation();

	//row - what row of animation will be accesed
	//deltaTime - how long is took from one frame to another
	void update(int row, float deltaTime);

	sf::IntRect uvRect;//texture rect in order to display animation


private:
	sf::Vector2u imageCount;//how much images have in row or in col
	sf::Vector2u currentImage; // indexes of current image what will be displayed from texture

	float totalTime;// how long animation will go
	float switchTime;//amount of time to switch to another image


};

