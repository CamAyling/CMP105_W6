#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	gBall = gravBall(window, input);
	pBall = pathBall(window);

	ballSprite.loadFromFile("gfx/Beach_Ball.png");

	gBall.setTexture(&ballSprite);
	gBall.setSize(sf::Vector2f(50, 50));
	gBall.setPosition(300, 50);

	pBall.setTexture(&ballSprite);
	pBall.setSize(sf::Vector2f(50, 50));
	pBall.setPosition(0, 0);
}

Level::~Level()
{
}

// handle user input
void Level::handleInput(float dt)
{
	gBall.handleInput();
}

// Update game objects
void Level::update(float dt)
{
	gBall.update(dt);
	pBall.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(gBall);
	window->draw(pBall);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}