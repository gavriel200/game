#pragma once

#include "../Entity.h"

#include <SFML/Graphics.hpp>

class Player : public Entity
{
private:
public:
	Player();

	void update(const float& dt);
	void render(sf::RenderTarget& target);
};
