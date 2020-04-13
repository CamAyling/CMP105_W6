#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"

class angryBird: public GameObject
{
public:
	angryBird();
	angryBird(sf::RenderWindow* hwnd, Input* in);
	~angryBird();

	void handleInput();
	void update(float dt);

protected:
	bool clickPrev;
	sf::Vector2f momentum;
	sf::Vector2f start;

	sf::RenderWindow* window;
};

