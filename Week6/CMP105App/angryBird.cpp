#include "angryBird.h"

angryBird::angryBird()
{}

angryBird::angryBird(sf::RenderWindow* hwnd, Input* in)
{
	clickPrev = false;
	window = hwnd;
	setInput(in);
	momentum = sf::Vector2f(0, 0);
}

angryBird::~angryBird()
{}

void angryBird::handleInput()
{
	if (input->isMouseLDown())
	{
		setPosition(sf::Vector2f(input->getMouseX() - (getSize().x / 2.f), input->getMouseY() - (getSize().y / 2.f)));
	}

	if (input->isMouseLDown() && !clickPrev)
	{
		start = sf::Vector2f(input->getMouseX(), input->getMouseY());
	}
	if (!input->isMouseLDown() && clickPrev)
	{
		momentum = 5.f * Vector::normalise(start - sf::Vector2f(input->getMouseX(), input->getMouseY())) 
			* Vector::magnitude(start - sf::Vector2f(input->getMouseX(), input->getMouseY()));
	}

	clickPrev = input->isMouseLDown();
}

void angryBird::update(float dt)
{
	move(momentum * dt);
	momentum.y += 0.4;

	if (getPosition().x + getSize().x >= window->getSize().x || getPosition().x <= 0)
	{
		momentum.x = -momentum.x;
		if (getPosition().x <= 0)
		{
			setPosition(sf::Vector2f(0, getPosition().y));
		}
		else
		{
			setPosition(sf::Vector2f(window->getSize().x - getSize().x, getPosition().y));
		}
	}

	if (getPosition().y + getSize().y >= window->getSize().y)
	{
		setPosition(sf::Vector2f(getPosition().x, window->getSize().y - getSize().y));
		momentum.y = -0.6 * momentum.y;
	}

	if (-10 <= momentum.y && momentum.y <= 10 && getPosition().y >= window->getSize().y - getSize().y - 30)
	{
		if (momentum.x > 0)
		{
			momentum.x -= 0.4;
		}
		if (momentum.x < 0)
		{
			momentum.x += 0.4;
		}
	}
}