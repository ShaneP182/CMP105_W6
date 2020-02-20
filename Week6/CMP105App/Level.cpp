#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	ballTexture.loadFromFile("gfx/Beach_Ball.png");
	missileTexture.loadFromFile("gfx/Brian.png");
	birdTexture.loadFromFile("gfx/Bird.png");

	ball.setTexture(&ballTexture);
	ball.setSize(sf::Vector2f(100, 100));
	ball.setPosition(500, 100);
	ball.setInput(input);
	ball.setWindow(window);

	missile.setTexture(&missileTexture);
	missile.setSize(sf::Vector2f(50, 50));
	missile.setPosition(0, 0);
	missile.setWindow(window);

	missile2.setTexture(&missileTexture);
	missile2.setSize(sf::Vector2f(50, 50));
	missile2.setPosition(0, 0);
	missile2.setWindow(window);
	missile2.setInput(input);

	birb.setTexture(&birdTexture);
	birb.setSize(sf::Vector2f(50, 50));
	birb.setPosition(100, 100);
	birb.setWindow(window);
	birb.setInput(input);

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	ball.handleInput(dt);
	birb.handleInput(dt);

}

// Update game objects
void Level::update(float dt)
{
	ball.update(dt);
	missile.update(dt);
	missile2.update(dt);
	birb.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	//window->draw(ball);
	//window->draw(missile);
	//window->draw(missile2);
	window->draw(birb);

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