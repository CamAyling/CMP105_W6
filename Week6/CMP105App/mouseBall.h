#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"

class mouseBall : public GameObject
{
public:
	mouseBall();
	mouseBall(sf::RenderWindow* hwnd, Input* in);
	~mouseBall();

	void update(float dt);

protected:
	sf::RenderWindow* window;
	sf::Vector2f toMouse;
	sf::Vector2f momentum;
};