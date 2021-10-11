#pragma once
#include <SFML/Graphics.hpp>
class Entity
{
public:
	void setVelocity(sf::Vector2f velocity) { mVelocity = velocity; };
	void setVelocity(float vx, float vy);
	sf::Vector2f getVelocity() const { return mVelocity; };
private:
	sf::Vector2f mVelocity;
};

