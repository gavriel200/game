#include "Game.h"

Game::Game()
{
	this->initWindow();
	this->initState();
}

Game::~Game()
{
	delete this->window;
}

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(500, 500), "MY GAME!", sf::Style::Fullscreen);
}

void Game::initState()
{
	this->currentStateId = State::StateId::MainMenu;
	this->currentState = new MainMenu(this->window, this->nextStateId);
}

void Game::updateDt()
{
	this->dt = this->dtClock.restart().asSeconds();
}

void Game::changeState()
{
	if (this->nextStateId != State::StateId::Null)
	{
		// Delete the current state
		if (this->nextStateId != State::StateId::Exit)
		{
			delete this->currentState;
		}

		switch (this->nextStateId)
		{
		case State::StateId::MainMenu:
			this->currentState = new MainMenu(this->window, this->nextStateId);
			break;

		case State::StateId::Level:
			this->currentState = new Level(this->window, this->nextStateId);
			break;
		}

		this->currentStateId = this->nextStateId;
		this->nextStateId = State::StateId::Null;
	}
}

void Game::run()
{
	// check if state is not null
	while (this->currentStateId != State::StateId::Exit)
	{
		// update delta time
		this->updateDt();

		// current state handle evens
		this->currentState->handelEvents();

		// current state update
		this->currentState->update(this->dt);

		// change current state if needed
		this->changeState();

		// clear windows
		this->window->clear();

		// current state render
		this->currentState->render();

		// window display
		this->window->display();
	}
}
