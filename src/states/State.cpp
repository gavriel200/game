#include "State.h"

State::State(sf::RenderWindow *window, State::StateId &nextStateId) : window(window), nextStateId(nextStateId)
{
	initFont();
}

void State::initFont()
{
	if (!this->font.loadFromFile("resources/fonts/MetalVengeance.ttf"))
	{
		throw("State::initFont failed to load font");
	}
}

void State::pollEvents()
{
	while (this->window->pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == sf::Event::Closed)
		{
			this->setNextState(State::StateId::Exit);
		}
	}
}

void State::setMousePosition()
{
	this->mousePosition = sf::Mouse::getPosition(*this->window);
}

void State::setNextState(State::StateId nextStateId)
{
	if (this->nextStateId != State::StateId::Exit)
	{
		this->nextStateId = nextStateId;
	}
}
