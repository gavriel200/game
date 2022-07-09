#pragma once

#include <map>

#include "State.h"
#include "../button/Button.h"

class MainMenu : public State
{
private:
	enum ButtonType : unsigned char
	{
		Continue,
		NewGame,
		Settings,
		Stats,
		Exit
	};

	std::map<MainMenu::ButtonType, Button *> buttons;

	void initButtons();
	void updateButtons();
	void checkIfButtonPressed();

public:
	MainMenu(sf::RenderWindow *window, State::StateId &nextStateId);
	~MainMenu();

	void handelEvents();
	void update(const float &dt);
	void render();
};
