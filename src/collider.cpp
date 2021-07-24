#include "collider.h"

Collider::Collider(sf::RectangleShape& body)
	:body(body)
{

}

Collider::~Collider()
{
}

bool Collider::checkCollision(Collider   &other, float push)
{
	//uses AABB colision technique colission of objects at the same axes
	//1.calc deltas of center points of shape of coliding objects
	//in this case shapes are rectangles
	//2. abs(deltaX) - (thisCollider.x + otherCollider.x )
	//same for delta X
	//if delta is negative, x or y it means collision happened



	sf::Vector2f otherPosition = other.getPosition();
	sf::Vector2f otherHalfPosition = other.getHalfPosition();

	sf::Vector2f thisPosition = this->getPosition();
	sf::Vector2f thisHalfPosition = this->getHalfPosition();

	float deltaX = thisHalfPosition.x - otherHalfPosition.x;
	float deltaY = thisHalfPosition.y - otherHalfPosition.y;

	//check if one object intersects with another
	float intersectX = std::abs(deltaX) - (otherHalfPosition.x + thisHalfPosition.x);
	float intersectY = std::abs(deltaY) - (otherHalfPosition.y + thisHalfPosition.y);

	if (intersectX<0.0f&&intersectY<0.0f)
	{
		push = std::min(std::max(push, 0.0f), 1.0f); //clamping
		//check with intersection is bigger because you want to get smallest one
		if (intersectX>intersectY)
		{
			//push in x axis
			// 
			//check on what direction this must be pushed
			if (deltaX>0.0f)
			{
				this->move(intersectX * (1.0f - push), 0.0f);
				other.move(-intersectX * push, 0.0f);
			}
			else {
				this->move(-intersectX * (1.0f - push), 0.0f);
				other.move(intersectX * push, 0.0f);
			}
		}
		else {
			//push by y axis

				//check on what direction this must be pushed
			if (deltaY > 0.0f)
			{
				this->move(0.0f,intersectY * (1.0f - push));
				other.move(-intersectY * push, 0.0f);
			}
			else {
				this->move(0.0f ,-intersectY * (1.0f - push));
				other.move(0.0f,intersectY * push);
			}
		}




		return true;
	}

	
	return false;
}
