#pragma once

#include <SFML/Graphics.hpp>

#include "component/MovementComponent.h"

class Entity
{
protected:
	sf::Sprite sprite;

	MovementComponent *movementComponent;

public:
	Entity();

	virtual void update(const float &dt) = 0;
	virtual void render(sf::RenderTarget &target) = 0;
};
