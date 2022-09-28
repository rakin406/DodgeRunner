#include "../include/obstacle.h"
#include "../include/constants.h"

#include <array>

namespace
{
    constexpr int MIN_START_POS{ -800 };
    constexpr int MAX_START_POS{ -200 };
    constexpr float DEFAULT_SPEED{ 1.0F };

    // The middle row position is 0.0F
    constexpr std::array ROW_POSITIONS{
        -constants::CUBE_SIZE - constants::GROUND_GAP / 2, 0.0F,
        constants::CUBE_SIZE + constants::GROUND_GAP / 2
    };
} // namespace

Obstacle::Obstacle() : m_speed(DEFAULT_SPEED) { resetPosition(); }

Vector3 Obstacle::getPosition() const { return m_position; }

float Obstacle::getSpeed() const { return m_speed; }

void Obstacle::setSpeed(float speed) { m_speed = speed; }

void Obstacle::loopTowardsViewer()
{
    {
        Vector3 newPosition{ m_position };
        newPosition.z += m_speed;
        m_position = newPosition;
    }

    // TODO: Refactor this code to ACTUALLY reach screen height and NOT count on
    // cube size.
    // Reset position if obstacle reaches screen height
    if (m_position.z >= constants::CUBE_SIZE * 2)
    {
        resetPosition();
    }
}

void Obstacle::resetPosition()
{
    Vector3 startingPosition{};

    {
        int randomRowIndex{ GetRandomValue(0, ROW_POSITIONS.size() - 1) };
        float randomRow{ ROW_POSITIONS[randomRowIndex] };
        auto randomColumn{ static_cast<float>(
            GetRandomValue(MIN_START_POS, MAX_START_POS)) };
        startingPosition = { randomRow, 0.0F, randomColumn };
    }

    m_position = startingPosition;
}

void Obstacle::draw() const
{
    using constants::CUBE_SIZE;

    DrawCube(m_position, CUBE_SIZE, CUBE_SIZE, CUBE_SIZE, RED);
    DrawCubeWires(m_position, CUBE_SIZE, CUBE_SIZE, CUBE_SIZE, BLACK);
}
