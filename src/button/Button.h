#pragma once

#include <SFML/Graphics.hpp>

class Button
{
public:
	enum ButtonState : unsigned char
	{
		Null,	 // normal state
		Hover,	 // mouse hovering the button
		Pressed, // mouse click while hovering
		Disabled // button unclickable

	};

private:
	Button::ButtonState buttonState;

	sf::RectangleShape shape;

	sf::Color nullColor;
	sf::Color hoverColor;
	sf::Color pressedColor;
	sf::Color disabledColor;

	sf::Font *font;
	sf::Text text;

	void setButtonColor();

public:
	Button(
		float x, float y,
		float width, float height,
		sf::Color nullColor,
		sf::Color hoverColor,
		sf::Color pressedColor,
		sf::Color disabledColor,
		sf::Font *font, std::string text);

	void update(const sf::Vector2i &mousePosition);
	void render(sf::RenderTarget &target);

	bool isPressed();

	Button::ButtonState getButtonState();
	std::string getText();

	void disableButton();
	void enableButton();
};
