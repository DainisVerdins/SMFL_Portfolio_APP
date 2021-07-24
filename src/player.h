#pragma once
#include<SFML/Graphics.hpp>
#include"animation.h"
#include"./collider.h"
class Player{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Player();

	void update(float deltaTime);
	void draw(sf::RenderWindow & window);

	//sets position of body image // left corner
	void setPosition(sf::Vector2f position) { body.setPosition(position); };

	//sf::Rect
	sf::Vector2f getPosition()const { return body.getPosition(); }

	Collider getCollider() { return Collider(body); }

private:
	
	sf::RectangleShape body;// body of image
	Animation animation;


	unsigned int row;//row index of animation in texture

	float speed;//speed of animation
	bool faceRigth;//animation faces rigth

};

