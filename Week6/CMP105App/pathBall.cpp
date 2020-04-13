#include "pathBall.h"

pathBall::pathBall()
{}

pathBall::pathBall(sf::RenderWindow* hwnd)
{
	window = hwnd;
}

pathBall::~pathBall()
{

}

void pathBall::update(float dt)
{
	AtoB = Vector::normalise(sf::Vector2f(window->getSize()) - (getPosition() + getSize()));
	move(40.f * AtoB * dt);
	if (getPosition().x + getSize().x > window->getSize().x)
	{
		setPosition(sf::Vector2f(window->getSize().x - getSize().x, getPosition().y));
	}
	if (getPosition().y + getSize().y > window->getSize().y)
	{
		setPosition(sf::Vector2f(getPosition().x, window->getSize().y - getSize().y));
	}
}