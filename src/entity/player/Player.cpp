#include "Player.h"

Player::Player() : Entity()
{
	this->texture.loadFromFile("resources/sprites/player/test2.png");

	this->sprite.setTexture(texture);
	this->sprite.setTextureRect(sf::IntRect(0, 0, 36, 32));
	this->sprite.setScale(sf::Vector2f(2.f, 2.f));
	this->sprite.setPosition(200, 200);
	this->movementComponent = new MovementComponent(this->sprite, 500.f, 2800.f, 2000.f);
}

void Player::move(float x, float y)
{
	this->movementComponent->move(x, y);
}

void Player::update(const float& dt)
{
	this->movementComponent->update(dt);
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
