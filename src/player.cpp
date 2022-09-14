#include "../include/player.h"
#include "../include/constants.h"

void Player::move(Direction direction)
{
    Vector3 newPosition = this->getPosition();
    int currentRow = this->getCurrentRow();

    // Check direction and don't go beyond row boundary
    if (direction == Direction::Left && currentRow > LEFT_ROW)
    {
        newPosition.x -= CUBE_SIZE;

        // Shift row to left
        this->setCurrentRow(currentRow - 1);
    }
    else if (direction == Direction::Right && currentRow < RIGHT_ROW)
    {
        newPosition.x += CUBE_SIZE;

        // Shift row to right
        this->setCurrentRow(currentRow + 1);
    }

    this->setPosition(newPosition);
}

void Player::draw() const
{
    DrawCube(this->getPosition(), CUBE_SIZE, CUBE_SIZE, CUBE_SIZE, BLUE);
    DrawCubeWires(this->getPosition(), CUBE_SIZE, CUBE_SIZE, CUBE_SIZE, BLACK);
}
