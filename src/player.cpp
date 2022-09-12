#include "../include/player.h"
#include "../include/constants.h"

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
