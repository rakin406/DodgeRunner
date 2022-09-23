#include "../include/player.h"
#include "../include/constants.h"

constexpr int LEFT_ROW = 1;
constexpr int MIDDLE_ROW = 2;
constexpr int RIGHT_ROW = 3;

Player::Player() : currentRow(MIDDLE_ROW)
{
    this->position = {0.0F, 0.0F, 0.0F};
}

Vector3 Player::getPosition() const { return this->position; }

void Player::move(Direction direction)
{
    Vector3 newPosition = this->position;
    int row = this->currentRow;
    float distance = CUBE_SIZE + GROUND_GAP / 2;

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
