#include "MovementComponent.h"

MovementComponent::MovementComponent(sf::Sprite& sprite,
	float maxVelocity,
	float acceleration,
	float deceleration) : sprite(sprite),
	maxVelocity(maxVelocity),
	acceleration(acceleration),
	deceleration(deceleration),
	xDir(0), yDir(0),
	velocity(sf::Vector2f(0.f, 0.f))
{
}

void MovementComponent::accelerate(const float& dt)
{
	this->velocity.x += this->acceleration * this->xDir * dt;
	this->velocity.y += this->acceleration * this->yDir * dt;
}

void MovementComponent::decelerateRight(const float& dt)
{
	if (this->velocity.x > this->maxVelocity)
	{
		this->velocity.x = this->maxVelocity;
	}

	this->velocity.x -= deceleration * dt;

	if (this->velocity.x < 0.f)
	{
		this->velocity.x = 0.f;
	}
}

void MovementComponent::decelerateLeft(const float& dt)
{
	if (this->velocity.x < -this->maxVelocity)
	{
		this->velocity.x = -this->maxVelocity;
	}

	this->velocity.x += deceleration * dt;

	if (this->velocity.x > 0.f)
	{
		this->velocity.x = 0.f;
	}
}

void MovementComponent::decelerateDown(const float& dt)
{
	if (this->velocity.y > this->maxVelocity)
	{
		this->velocity.y = this->maxVelocity;
	}

	this->velocity.y -= deceleration * dt;

	if (this->velocity.y < 0.f)
	{
		this->velocity.y = 0.f;
	}
}

void MovementComponent::decelerateUp(const float& dt)
{
	if (this->velocity.y < -this->maxVelocity)
	{
		this->velocity.y = -this->maxVelocity;
	}

	this->velocity.y += deceleration * dt;

	if (this->velocity.y > 0.f)
	{
		this->velocity.y = 0.f;
	}
}

void MovementComponent::resetDir()
{
	this->xDir = 0.f;
	this->yDir = 0.f;
}

void MovementComponent::move(float x, float y)
{
	this->xDir += x;
	this->yDir += y;
}

void MovementComponent::update(const float& dt)
{

	this->accelerate(dt);

	this->resetDir();

	if (this->velocity.x > 0.f)
	{
		this->decelerateRight(dt);
	}
	else if (this->velocity.x < 0.f)
	{
		this->decelerateLeft(dt);
	}
	if (this->velocity.y > 0.f)
	{
		this->decelerateDown(dt);
	}
	else if (this->velocity.y < 0.f)
	{
		this->decelerateUp(dt);
	}

	this->sprite.move(this->velocity * dt);
}

MovementComponent::MovementState MovementComponent::getState()
{
	return MovementComponent::MovementState::Null;
}
