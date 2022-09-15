#include "../include/player.h"
#include "../include/constants.h"

void Player::move(Direction direction)
{
    Vector3 newPosition = this->position;
    int row = this->currentRow;

    // Check direction and don't go beyond row boundary
    if (direction == Direction::Left && row > LEFT_ROW)
    {
        newPosition.x -= CUBE_SIZE;

        // Shift row to left
        this->currentRow = row - 1;
    }
    else if (direction == Direction::Right && row < RIGHT_ROW)
    {
        newPosition.x += CUBE_SIZE;

        // Shift row to right
        this->currentRow = row + 1;
    }

    this->position = newPosition;
}

void Player::draw() const
{
    DrawCube(this->position, CUBE_SIZE, CUBE_SIZE, CUBE_SIZE, BLUE);
    DrawCubeWires(this->position, CUBE_SIZE, CUBE_SIZE, CUBE_SIZE, BLACK);
}
