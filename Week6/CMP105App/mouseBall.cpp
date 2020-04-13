#include "mouseBall.h"

mouseBall::mouseBall()
{}

mouseBall::mouseBall(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	setInput(in);
	momentum = sf::Vector2f(0, 0);
}

mouseBall::~mouseBall()
{

}

void mouseBall::update(float dt)
{
	toMouse = Vector::normalise(sf::Vector2f(input->getMouseX(), input->getMouseY()) - (getPosition() + (getSize() / 2.f)));
	momentum += toMouse;

	move(2.f * momentum * dt);
}