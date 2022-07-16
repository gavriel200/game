#pragma once

#include "../Entity.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Player : public Entity
{
private:
	sf::Texture texture;

public:
	Player();

	void move(float x, float y);

	void update(const float &dt);
	void render(sf::RenderTarget &target);
};
