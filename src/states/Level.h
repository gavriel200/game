#pragma once

#include "State.h"
#include "../entity/player/Player.h"

class Level : public State
{
private:
	Player* player;

	void handelPlayerInput();

public:
	Level(sf::RenderWindow* window, State::StateId& nextStateId);
	~Level();

	void handelEvents();
	void update(const float& dt);
	void render();
};
