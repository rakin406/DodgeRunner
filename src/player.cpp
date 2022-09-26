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
        float distance { g_CUBE_SIZE + g_GROUND_GAP / 2 };

        // Check direction and don't go beyond row boundary
        if (direction == Direction::Left && row > LEFT_ROW)
        {
            newPosition.x -= distance;
            m_currentRow = row - 1; // Shift row to left
        }
        else if (direction == Direction::Right && row < RIGHT_ROW)
        {
            newPosition.x += distance;
            m_currentRow = row + 1; // Shift row to right
        }
    }

    // Set player position
    m_position = newPosition;
}

void Player::draw() const
{
    DrawCube(m_position, g_CUBE_SIZE, g_CUBE_SIZE, g_CUBE_SIZE, BLUE);
    DrawCubeWires(m_position, g_CUBE_SIZE, g_CUBE_SIZE, g_CUBE_SIZE, BLACK);
}
