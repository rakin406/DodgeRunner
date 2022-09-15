#include "../include/player.h"
#include "../include/constants.h"

#define LEFT_ROW 1
#define MIDDLE_ROW 2
#define RIGHT_ROW 3

Player::Player()
{
    this->position = {0.0F, 0.0F, 0.0F};
    this->currentRow = MIDDLE_ROW;
}

void Player::move(Direction direction)
{
    Vector3 newPosition = this->position;
    int row = this->currentRow;
    float distance = CUBE_SIZE + ground::GAP / 2;

    // Check direction and don't go beyond row boundary
    if (direction == Direction::Left && row > LEFT_ROW)
    {
        newPosition.x -= distance;

        // Shift row to left
        this->currentRow = row - 1;
    }
    else if (direction == Direction::Right && row < RIGHT_ROW)
    {
        newPosition.x += distance;

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
