#include "animation.h"
#include<cstdlib>//abs

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
	:imageCount(imageCount), switchTime(switchTime)
{

	this->totalTime = 0;
	currentImage.x = 0;

	//from image get only one part of it of animation
	uvRect.width = int(texture->getSize().x / float(imageCount.x));
	uvRect.height = int(texture->getSize().y / float(imageCount.y));

}

Animation::~Animation()
{
}

void Animation::update(int row, float deltaTime, bool faceRight)
{
	currentImage.y = row;
	totalTime += deltaTime;

	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;

		//get next image in animation row
		++currentImage.x;

		if (currentImage.x == imageCount.x)
		{
			currentImage.x = 0;
		}
	}
	//where new animation image starts from texture (index of image * size of image)
	uvRect.top = currentImage.y * uvRect.height;

	if (faceRight)
	{
		uvRect.left = currentImage.x * uvRect.width;
		uvRect.width = std::abs(uvRect.width);
	}
	else
	{
		//change drawing line of image from left side to rigth side
		uvRect.left = (currentImage.x + 1) *std::abs(uvRect.width);
		//abs need here otherwise avery frame image aka animation will be changing
		uvRect.width = -std::abs(uvRect.width);
	}

}
