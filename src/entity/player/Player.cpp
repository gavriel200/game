#include "Player.h"

Player::Player() : Entity()
{
}

void Player::update(const float& dt)
{
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}
