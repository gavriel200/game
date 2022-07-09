#pragma once

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class State
{
public:
	enum StateId : unsigned char
	{
		Null,
		MainMenu,
		Level,
		Exit,
	};

private:
	void initFont();

protected:
	sf::Event sfEvent;

	sf::RenderWindow* window;
	State::StateId& nextStateId;

	sf::Vector2i mousePosition;

	sf::Font font;

	State(sf::RenderWindow* window, State::StateId& nextStateId);

	virtual void pollEvents();
	void setMousePosition();
	void setNextState(State::StateId nextStateId);

public:
	virtual void handelEvents() = 0;
	virtual void update(const float& dt) = 0;
	virtual void render() = 0;
	virtual ~State() {};
};
