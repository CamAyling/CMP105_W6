#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	gBall = gravBall(window, input);
	pBall = pathBall(window);
	mBall = mouseBall(window, input);

	bird = angryBird(window, input);

	ballSprite.loadFromFile("gfx/Beach_Ball.png");

	gBall.setTexture(&ballSprite);
	gBall.setSize(sf::Vector2f(50, 50));
	gBall.setPosition(300, 50);

	pBall.setTexture(&ballSprite);
	pBall.setSize(sf::Vector2f(50, 50));
	pBall.setPosition(0, 0);

	mBall.setTexture(&ballSprite);
	mBall.setSize(sf::Vector2f(50, 50));
	mBall.setPosition(0, 0);

	bird.setTexture(&ballSprite);
	bird.setSize(sf::Vector2f(50, 50));
	bird.setPosition(0, 0);
}

Level::~Level()
{
}

// handle user input
void Level::handleInput(float dt)
{
	//gBall.handleInput();
	bird.handleInput();
}

// Update game objects
void Level::update(float dt)
{
	//gBall.update(dt);
	//pBall.update(dt);
	//mBall.update(dt);
	bird.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	//window->draw(gBall);
	//window->draw(pBall);
	//window->draw(mBall);
	window->draw(bird);

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