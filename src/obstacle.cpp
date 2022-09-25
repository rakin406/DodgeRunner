#include "../include/obstacle.h"
#include "../include/constants.h"

#include <array>

namespace
{
constexpr int MIN_START_POS { -800 };
constexpr int MAX_START_POS { -200 };
constexpr float DEFAULT_SPEED { 1.0F };

// The middle row position is 0.0F
constexpr std::array<float, 3> ROW_POSITIONS { -CUBE_SIZE - GROUND_GAP / 2,
                                               0.0F,
                                               CUBE_SIZE + GROUND_GAP / 2 };
} // namespace

Obstacle::Obstacle() : speed(DEFAULT_SPEED) { this->resetPosition(); }

Vector3 Obstacle::getPosition() const { return this->position; }

float Obstacle::getSpeed() const { return this->speed; }

void Obstacle::setSpeed(float speed) { this->speed = speed; }

void Obstacle::loopTowardsViewer()
{
    Vector3 newPosition { this->position };
    newPosition.z += this->speed;
    this->position = newPosition;

    // TODO: Refactor this code to ACTUALLY reach screen height and NOT count on
    // cube size.
    // Reset position if obstacle reaches screen height
    if (this->position.z >= CUBE_SIZE * 2)
    {
        this->resetPosition();
    }
}

void Obstacle::resetPosition()
{
    // Get random row index
    int randomRowIndex { GetRandomValue(0, ROW_POSITIONS.size() - 1) };

    // Get random row
    float randomRow { ROW_POSITIONS[randomRowIndex] };

    // Get a random column, which is forward or backward, the z-axis
    auto randomColumn { static_cast<float>(
        GetRandomValue(MIN_START_POS, MAX_START_POS)) };

    // Combine both positions
    Vector3 startingPosition { randomRow, 0.0F, randomColumn };

    // Set random position
    this->position = startingPosition;
}

void Obstacle::draw() const
{
    DrawCube(this->position, CUBE_SIZE, CUBE_SIZE, CUBE_SIZE, RED);
    DrawCubeWires(this->position, CUBE_SIZE, CUBE_SIZE, CUBE_SIZE, BLACK);
}
