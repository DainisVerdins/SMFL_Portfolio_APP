#pragma once
#include<SFML/Graphics.hpp>
#include<string>
#include<vector>
struct Animation
{
	std::string m_Name;
	std::string m_TextureName;
	std::vector<sf::IntRect>m_Frames;
	sf::Time m_Duration;
	bool m_Looping;

	Animation(const std::string& name, const std::string& textureName,
			  const sf::Time& duration, bool looping);
	void AddFrames(const sf::Vector2i& startFrom, const sf::Vector2i& frameSize, unsigned int frames);
};

