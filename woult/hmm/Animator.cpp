#include "Animator.h"

Animator::Animator(sf::Sprite& sprite)
:m_Sprite(sprite),m_CurrentTime(),m_CurrentAnimation(nullptr)
{
}

Animator::Animation& Animator::CreateAnimation(const std::string& name, const std::string& textureName, const sf::Time& duration, bool loop)
{
	m_Animations.push_back(Animator::Animation{name,textureName,duration,loop});
	
	//if do not have any other animations, user that as current animation
	if (m_CurrentAnimation==nullptr)
	{
		SwitchAnimation(&m_Animations.back());
	}
	return m_Animations.back();
}

void Animator::Update(sf::Time const& dt)
{
	//if do not have any anumations yet return
	if (m_CurrentAnimation==nullptr)
	{
		return;
	}
	m_CurrentTime += dt;
	//get the curent animation frame
	float scaledTime =( m_CurrentTime.asSeconds() / m_CurrentAnimation->m_Duration.asSeconds());
	int numFrames = m_CurrentAnimation->m_Frames.size();
	int currentFrame = static_cast<int>(scaledTime * numFrames);

	//if the animation is looping ,calc the correct frame
	if (m_CurrentAnimation->m_Looping)
	{
		currentFrame %= numFrames;
	}
	else if (currentFrame>=numFrames)//if the current frame is greater thab bumFrames
	{
		currentFrame = numFrames - 1;
	}

	///set the texture rectangle m depending on the frame
	m_Sprite.setTextureRect(m_CurrentAnimation->m_Frames[currentFrame]);
}

bool Animator::SwitchAnimation(std::string const& name)
{
	auto animation = FindAnimation(name);
	if (animation!=nullptr)
	{
		SwitchAnimation(animation);
		return true;
	}

	return false;
}

std::string Animator::GetCurrentAnimationName() const
{
	if (m_CurrentAnimation!=nullptr)
	{
		return m_CurrentAnimation->m_Name;

	}
	//if no animation return empty string;
	return "";
}

Animator::Animation* Animator::FindAnimation(std::string const& name)
{
	for (auto it = m_Animations.begin(); it != m_Animations.end(); it++)
	{
		if (it->m_Name==name)
		{
			return &*it;
		}
	}
	return nullptr;
}

void Animator::SwitchAnimation(Animator::Animation* animation)
{
	if (animation!=nullptr)
	{
		m_Sprite.setTexture(AssetManager::GetTexture(animation->m_TextureName));
		m_CurrentAnimation = animation;
		m_CurrentTime = sf::Time::Zero;
	}
}

