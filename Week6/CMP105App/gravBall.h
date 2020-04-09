#pragma once
#include "Framework/GameObject.h"
#include "SFML/Graphics.hpp"

class gravBall : public GameObject
{
public:
	gravBall() = default;
	gravBall(sf::RenderWindow* hwnd);
	~gravBall();

	void handleInput();
	void update(float dt) override;

protected:
	sf::RenderWindow* window;
	sf::Vector2f momentum;

	bool clicking;
	bool spacePrev;
};

