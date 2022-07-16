#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>

class MovementComponent
{
public:
    enum MovementState : unsigned char
    {
        Null
    };

private:
    sf::Sprite &sprite;

    float maxVelocity;
    float acceleration;
    float deceleration;

    float xDir;
    float yDir;

    sf::Vector2f velocity;

    void accelerate(const float &dt);

    void decelerateRight(const float &dt);
    void decelerateLeft(const float &dt);
    void decelerateDown(const float &dt);
    void decelerateUp(const float &dt);

    void resetDir();

public:
    MovementComponent(sf::Sprite &sprite, float maxVelocity, float acceleration, float deceleration);

    MovementComponent::MovementState getState();

    void move(float x, float y);
    void update(const float &dt);
};
