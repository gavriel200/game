#include "Level.h"

Level::Level(sf::RenderWindow* window, State::StateId& nextStateId) : State(window, nextStateId)
{
	this->player = new Player();
}

Level::~Level()
{
	delete this->player;
}

void Level::handelPlayerInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->player->updateMovementDir(0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->player->updateMovementDir(-1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->player->updateMovementDir(0.f, 1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->player->updateMovementDir(1.f, 0.f);
	}
}

void Level::handelEvents()
{
	this->pollEvents();
	this->handelPlayerInput();
}

void Level::update(const float& dt) {
	this->player->move(dt);
}

void Level::render()
{
	this->player->render(*this->window);
}
