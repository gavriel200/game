#include "Button.h"

Button::Button(float x, float y,
	float width, float height,
	sf::Color nullColor,
	sf::Color hoverColor,
	sf::Color pressedColor,
	sf::Color disabledColor,
	sf::Font* font, std::string text)
{
	this->buttonState = Button::ButtonState::Null;

	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));
	this->shape.setFillColor(nullColor);

	this->nullColor = nullColor;
	this->hoverColor = hoverColor;
	this->pressedColor = pressedColor;
	this->disabledColor = disabledColor;

	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setCharacterSize(20);

	this->text.setPosition(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f);
}

void Button::setButtonColor()
{
	switch (this->buttonState)
	{
	case Button::ButtonState::Null:
		this->shape.setFillColor(this->nullColor);
		break;
	case Button::ButtonState::Hover:
		this->shape.setFillColor(this->hoverColor);
		break;
	case Button::ButtonState::Pressed:
		this->shape.setFillColor(this->pressedColor);
		break;
	case Button::ButtonState::Disabled:
		this->shape.setFillColor(this->disabledColor);
		break;
	}
}

void Button::update(const sf::Vector2i& mousePosition)
{
	if (this->buttonState != Button::ButtonState::Disabled)
	{
		this->buttonState = Button::ButtonState::Null;
		if (this->shape.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
		{
			this->buttonState = Button::ButtonState::Hover;
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				this->buttonState = Button::ButtonState::Pressed;
			}
		}
	}

	this->setButtonColor();
}

void Button::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
	target.draw(this->text);
}

bool Button::isPressed()
{
	return this->buttonState == Button::ButtonState::Pressed;
}

Button::ButtonState Button::getButtonState()
{
	return this->buttonState;
}

std::string Button::getText()
{
	return this->text.getString();
}

void Button::disableButton()
{
	this->buttonState = Button::ButtonState::Disabled;
}

void Button::enableButton()
{
	this->buttonState = Button::ButtonState::Null;
}
