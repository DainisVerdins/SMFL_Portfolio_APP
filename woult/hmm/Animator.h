#pragma once
#include"Animation.h"
#include"AssetManager.h"
#include<string>
#include<list>
class Animator
{
public:
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
	Animator(sf::Sprite& sprite);
	Animator::Animation& CreateAnimation(const std::string& name, const std::string& textureName,
		const sf::Time& duration, bool loop = false);

	void Update(sf::Time const& dt);
	//returns if the switch was successful
	bool SwitchAnimation(std::string const& name);

	std::string GetCurrentAnimationName()const;
private:
	//returns the animation with the passed name
	//returns nullptr if no sunc animation is found
	Animator::Animation* FindAnimation(std::string const& name);
	void SwitchAnimation(Animator::Animation* animation);

	//reference to the sprite
	sf::Sprite& m_Sprite;
	sf::Time m_CurrentTime;
	std::list<Animator::Animation>m_Animations;
	Animator::Animation* m_CurrentAnimation;
};

