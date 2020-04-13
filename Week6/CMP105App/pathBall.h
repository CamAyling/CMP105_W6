#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"

class pathBall: public GameObject
{
public:
	pathBall();
	pathBall(sf::RenderWindow* hwnd);
	~pathBall();

	void update(float dt);

protected:
	sf::RenderWindow* window;
	sf::Vector2f AtoB;
};

