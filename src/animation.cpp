#include "animation.h"

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

 void Animation::update(int row, float deltaTime)
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

	uvRect.left = currentImage.x * uvRect.width;
	uvRect.top = currentImage.y * uvRect.height;
}
