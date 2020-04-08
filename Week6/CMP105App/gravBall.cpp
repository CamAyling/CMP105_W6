#include "gravBall.h"

gravBall::gravBall()
{
	window = NULL;
	momentum = sf::Vector2f(0, 0);
}

gravBall::~gravBall()
{
}

void gravBall::setWindow(sf::RenderWindow* hwnd)
{
	window = hwnd;
}

void gravBall::update(float dt)
{
	momentum.y += 0.2;

	move(momentum * dt);

	if (getPosition().y > window->getSize().y - getSize().y) 
	{
		setPosition(sf::Vector2f(getPosition().x, window->getSize().y - getSize().y));
		momentum.y = 0;
	}
}