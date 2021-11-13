#include "Animation.h"

Animation::Animation(const std::string& name, const std::string& textureName, const sf::Time& duration, bool looping)
	:m_Name{ name }, m_TextureName{ textureName }, m_Duration{ duration }, m_Looping{looping}
{

}
//Adds frames horizontally
void Animation::AddFrames(const sf::Vector2i& startFrom, const sf::Vector2i& frameSize, unsigned int frames)
{
	sf::Vector2i current = startFrom;
	for (unsigned int i = 0; i < frames; i++)
	{
		//add current frame from position and frame size
		m_Frames.push_back(sf::IntRect(current.x, current.y, frameSize.x, frameSize.y));
		//adnave current frame horizontally
		current.x += frameSize.x;
	}
}
