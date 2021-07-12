#include "collider.h"

Collider::Collider(sf::RectangleShape& body)
	:body(body)
{

}

Collider::~Collider()
{
}

bool Collider::checkCollision(Collider& other, float push)
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

	
	//TODO :
	//CHECK IF COLLISION HAPPENED
	//REACTION OF COLLISION

	
	return false;
}
