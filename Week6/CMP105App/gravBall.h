#pragma once
#include "Framework/GameObject.h"
#include "SFML/Graphics.hpp"

class gravBall : public GameObject
{
public:
	gravBall();
	gravBall(sf::RenderWindow* hwnd, Input* in);
	~gravBall();

	void handleInput();
	void update(float dt) override;

protected:
	sf::RenderWindow* window;
	sf::Vector2f momentum;

	bool clicking;
	bool spacePrev;
};

