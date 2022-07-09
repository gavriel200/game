#pragma once

#include <SFML/Graphics.hpp>

class Entity
{
protected:
	sf::RectangleShape shape;
	sf::Vector2f movementDir;

	float speed = 500.f;

public:
	Entity();

	virtual void update(const float &dt) = 0;
	virtual void render(sf::RenderTarget &target) = 0;

	void updateMovementDir(float x, float y);
	void resetMovementDir();
	void move(const float &dt);
};
