#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow* window, State::StateId& nextStateId) : State(window, nextStateId)
{
	this->initButtons();
}

MainMenu::~MainMenu()
{

	for (auto const& [key, val] : this->buttons)
	{
		delete val;
	}
}

void MainMenu::initButtons()
{
	buttons[MainMenu::ButtonType::Continue] = new Button(50, 50,
		200.f, 100.f,
		sf::Color::Blue,
		sf::Color::Red,
		sf::Color::Yellow,
		sf::Color(100, 100, 100),
		&this->font, "CONTINUE");

	buttons[MainMenu::ButtonType::NewGame] = new Button(50, 200,
		200.f, 100.f,
		sf::Color::Blue,
		sf::Color::Red,
		sf::Color::Yellow,
		sf::Color(100, 100, 100),
		&this->font, "NEW GAME");

	buttons[MainMenu::ButtonType::Settings] = new Button(50, 350,
		200.f, 100.f,
		sf::Color::Blue,
		sf::Color::Red,
		sf::Color::Yellow,
		sf::Color(100, 100, 100),
		&this->font, "SETTINGS");

	buttons[MainMenu::ButtonType::Stats] = new Button(50, 500,
		200.f, 100.f,
		sf::Color::Blue,
		sf::Color::Red,
		sf::Color::Yellow,
		sf::Color(100, 100, 100),
		&this->font, "STATS");

	buttons[MainMenu::ButtonType::Exit] = new Button(50, 650,
		200.f, 100.f,
		sf::Color::Blue,
		sf::Color::Red,
		sf::Color::Yellow,
		sf::Color(100, 100, 100),
		&this->font, "EXIT");

	buttons[MainMenu::ButtonType::Continue]->disableButton();
}

void MainMenu::updateButtons()
{
	for (auto const& [key, val] : this->buttons)
	{
		val->update(this->mousePosition);
	}
}

void MainMenu::checkIfButtonPressed()
{
	for (auto const& [key, val] : this->buttons)
	{
		if (val->isPressed())
		{
			switch (key)
			{
			case MainMenu::ButtonType::NewGame:
				this->setNextState(State::StateId::Level);
				break;
			case MainMenu::ButtonType::Exit:
				this->setNextState(State::StateId::Exit);
				break;
			}
		}
	}
}

void MainMenu::handelEvents()
{
	this->pollEvents();
	this->setMousePosition();
}

void MainMenu::update(const float& dt)
{
	this->updateButtons();
	this->checkIfButtonPressed();
}

void MainMenu::render()
{
	for (auto const& [key, val] : this->buttons)
	{
		val->render(*this->window);
	}
}
