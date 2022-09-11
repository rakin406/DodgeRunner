#include "../include/player.h"
#include "../include/constants.h"
#include "raylib.h"

Player::Player()
{
    Vector3 startingPosition = {0.0F, 0.0F, 0.0F};
    this->setPosition(startingPosition);
}

void Player::move(Direction direction)
{
    Vector3 newPosition = this->getPosition();

    // Move according to direction
    if (direction == Direction::Left)
    {
        newPosition.x -= CUBE_SIZE;
    }
    else
    {
        newPosition.x += CUBE_SIZE;
    }

    this->setPosition(newPosition);
}

void Player::draw() const
{
    DrawCube(this->getPosition(), CUBE_SIZE, CUBE_SIZE, CUBE_SIZE, BLUE);
    DrawCubeWires(this->getPosition(), CUBE_SIZE, CUBE_SIZE, CUBE_SIZE, BLACK);
}
