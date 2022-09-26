#include "../include/player.h"
#include "../include/constants.h"

namespace
{
constexpr int kLeftRow { 1 };
constexpr int kMiddleRow { 2 };
constexpr int kRightRow { 3 };
} // namespace

Player::Player() : currentRow(kMiddleRow)
{
    this->position = { 0.0F, 0.0F, 0.0F };
}

Vector3 Player::getPosition() const { return this->position; }

void Player::move(Direction direction)
{
    Vector3 newPosition { this->position };

    {
        int row { this->currentRow }; // Get current row of player
        float distance { kCubeSize + kGroundGap / 2 };

        // Check direction and don't go beyond row boundary
        if (direction == Direction::Left && row > kLeftRow)
        {
            newPosition.x -= distance;
            this->currentRow = row - 1; // Shift row to left
        }
        else if (direction == Direction::Right && row < kRightRow)
        {
            newPosition.x += distance;
            this->currentRow = row + 1; // Shift row to right
        }
    }

    // Set player position
    this->position = newPosition;
}

void Player::draw() const
{
    DrawCube(this->position, kCubeSize, kCubeSize, kCubeSize, BLUE);
    DrawCubeWires(this->position, kCubeSize, kCubeSize, kCubeSize, BLACK);
}
