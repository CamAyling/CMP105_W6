#pragma once
#include "Framework/GameObject.h"
#include "SFML/Graphics.hpp"

class gravBall : public GameObject
{
public:
	gravBall();
	~gravBall();

	void update(float dt) override;
	void setWindow(sf::RenderWindow* hwnd);

protected:
	sf::RenderWindow* window;
	sf::Vector2f momentum;
};
