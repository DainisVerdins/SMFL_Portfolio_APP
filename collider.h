#pragma once
#include<SFML/Graphics.hpp>
class Collider
{
public:
	Collider(sf::RectangleShape& body);
	~Collider();

	//by how much by delta after collision will body move
	void move(float dx, float dy) { body.move(dx, dy); }

	//uses AABB colision technique, colission of objects at the same axes
	//push - how much the obj must be pushh out 'havines' of object
	bool checkCollision(Collider& other, float push);

	//get position of shape , be aware it is its center coordinates not from left corner
	sf::Vector2f getPosition() { return body.getPosition(); }
	//gets position of half size of the cube, its coordinates 
	sf::Vector2f getHalfPosition() { return body.getPosition() / 2.0f; }

private:
	sf::RectangleShape& body; //holds rederence to body of the texture
};

