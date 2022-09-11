#include "../include/player.h"
#include "../include/constants.h"
#include "raylib.h"

#define LEFT_ROW 1
#define MIDDLE_ROW 2
#define RIGHT_ROW 3

Player::Player()
{
    Vector3 startingPosition = {0.0F, 0.0F, 0.0F};
    this->setPosition(startingPosition);
    this->setCurrentRow(MIDDLE_ROW);
}

void Player::move(Direction direction)
{
    Vector3 newPosition = this->getPosition();

    // Check direction
    if (direction == Direction::Left)
    {
        // Don't go beyond row boundary
        if (this->getCurrentRow() > LEFT_ROW)
        {
            newPosition.x -= CUBE_SIZE;

            // Shift row to left
            int currentRow = this->getCurrentRow();
            this->setCurrentRow(currentRow - 1);
        }
    }
    else
    {
        // Don't go beyond row boundary
        if (this->getCurrentRow() < RIGHT_ROW)
        {
            newPosition.x += CUBE_SIZE;

            // Shift row to right
            int currentRow = this->getCurrentRow();
            this->setCurrentRow(currentRow + 1);
        }
    }

    this->setPosition(newPosition);
}

void Player::draw() const
{
    DrawCube(this->getPosition(), CUBE_SIZE, CUBE_SIZE, CUBE_SIZE, BLUE);
    DrawCubeWires(this->getPosition(), CUBE_SIZE, CUBE_SIZE, CUBE_SIZE, BLACK);
}
