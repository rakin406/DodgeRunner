#include "../include/obstacle.h"
#include "../include/constants.h"

#include <array>

namespace
{
constexpr int MIN_START_POS { -800 };
constexpr int MAX_START_POS { -200 };
constexpr float DEFAULT_SPEED { 1.0F };

// The middle row position is 0.0F
constexpr std::array<float, 3> ROW_POSITIONS {
    -constants::CUBE_SIZE - constants::GROUND_GAP / 2, 0.0F,
    constants::CUBE_SIZE + constants::GROUND_GAP / 2
};
} // namespace

Obstacle::Obstacle() : m_speed(DEFAULT_SPEED) { this->resetPosition(); }

Vector3 Obstacle::getPosition() const { return m_position; }

float Obstacle::getSpeed() const { return m_speed; }

void Obstacle::setSpeed(float speed) { m_speed = speed; }

void Obstacle::loopTowardsViewer()
{
    {
        Vector3 newPosition { m_position };
        newPosition.z += m_speed;
        m_position = newPosition;
    }

    // TODO: Refactor this code to ACTUALLY reach screen height and NOT count on
    // cube size.
    // Reset position if obstacle reaches screen height
    if (m_position.z >= constants::CUBE_SIZE * 2)
    {
        this->resetPosition();
    }
}

void Obstacle::resetPosition()
{
    Vector3 startingPosition {};

    {
        // Get random row index
        int randomRowIndex { GetRandomValue(0, ROW_POSITIONS.size() - 1) };

        // Get random row
        float randomRow { ROW_POSITIONS[randomRowIndex] };

        // Get a random column, which is forward or backward, the z-axis
        auto randomColumn { static_cast<float>(
            GetRandomValue(MIN_START_POS, MAX_START_POS)) };

        // Combine both positions
        startingPosition = { randomRow, 0.0F, randomColumn };
    }

    // Set random position
    m_position = startingPosition;
}

void Obstacle::draw() const
{
    DrawCube(m_position, constants::CUBE_SIZE, constants::CUBE_SIZE,
             constants::CUBE_SIZE, RED);
    DrawCubeWires(m_position, constants::CUBE_SIZE, constants::CUBE_SIZE,
                  constants::CUBE_SIZE, BLACK);
}
