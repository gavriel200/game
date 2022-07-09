#pragma once

#include "states/MainMenu.h"
#include "states/Level.h"

class Game
{
private:
	sf::RenderWindow *window;

	// delta
	sf::Clock dtClock;
	float dt;

	// States
	State::StateId currentStateId = State::StateId::Null;
	State::StateId nextStateId = State::StateId::Null;
	State *currentState = NULL;

	void initWindow();
	void initState();

	void updateDt();

	void changeState();

public:
	Game();
	~Game();
	void run();
};
