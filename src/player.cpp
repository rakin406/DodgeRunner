#include "../include/player.h"
#include "../include/constants.h"

namespace
{
constexpr int LEFT_ROW { 1 };
constexpr int MIDDLE_ROW { 2 };
constexpr int RIGHT_ROW { 3 };
} // namespace

Player::Player() : m_currentRow(MIDDLE_ROW)
{
    m_position = { 0.0F, 0.0F, 0.0F };
}

Vector3 Player::getPosition() const { return m_position; }

void Player::move(Direction direction)
{
    Vector3 newPosition { m_position };

    {
        int row { m_currentRow }; // Get current row of player
        float distance { constants::CUBE_SIZE + constants::GROUND_GAP / 2 };

        // Check direction and don't go beyond row boundary
        if (direction == Direction::left && row > LEFT_ROW)
        {
            newPosition.x -= distance;
            m_currentRow = row - 1; // Shift row to left
        }
        else if (direction == Direction::right && row < RIGHT_ROW)
        {
            newPosition.x += distance;
            m_currentRow = row + 1; // Shift row to right
        }
    }

    m_position = newPosition;
}

void Player::draw() const
{
    using constants::CUBE_SIZE;

    DrawCube(m_position, CUBE_SIZE, CUBE_SIZE, CUBE_SIZE, BLUE);
    DrawCubeWires(m_position, CUBE_SIZE, CUBE_SIZE, CUBE_SIZE, BLACK);
}
