#include "Entity.h"

#include <iostream>

Entity::Entity()
{
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
	this->shape.setFillColor(sf::Color::Cyan);
	this->shape.setPosition(sf::Vector2f(50.f, 50.f));
	this->resetMovementDir();
}

void Entity::updateMovementDir(float x, float y)
{
	this->movementDir.x += x;
	this->movementDir.y += y;
}

void Entity::resetMovementDir()
{
	this->movementDir.x = 0.f;
	this->movementDir.y = 0.f;
}

void Entity::move(const float &dt)
{
	this->shape.move(sf::Vector2f(this->movementDir.x * this->speed * dt,
								  this->movementDir.y * this->speed * dt));
	this->resetMovementDir();
}
