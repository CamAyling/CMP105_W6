#include "gravBall.h"

gravBall::gravBall(sf::RenderWindow* hwnd)
{
	window = hwnd;
	momentum = sf::Vector2f(0, 0);
	clicking = false;
	spacePrev = false;
}

gravBall::~gravBall()
{
}

void gravBall::handleInput()
{
	if (input->isMouseLDown())
	{
		setPosition(sf::Vector2f(float(input->getMouseX()), float(input->getMouseY())));
		clicking = true;
	}
	else
	{
		clicking = false;
	}

	if (input->isKeyDown(sf::Keyboard::Space) && !clicking && !spacePrev)
	{
		momentum.y = -500;
	}

	spacePrev = input->isKeyDown(sf::Keyboard::Space);
}

void gravBall::update(float dt)
{
	momentum.y += 0.5f;

	move(momentum * dt);

	if (getPosition().y > window->getSize().y - getSize().y || clicking)
	{
		if (!clicking)
		{
			setPosition(sf::Vector2f(getPosition().x, window->getSize().y - getSize().y));
		}
		momentum.y = 0;
	}
}