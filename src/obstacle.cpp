#include "../include/obstacle.h"
#include "../include/constants.h"

#include <array>

namespace
{
constexpr int kMinStartPos { -800 };
constexpr int kMaxStartPos { -200 };
constexpr float kDefaultSpeed { 1.0F };

// The middle row position is 0.0F
constexpr std::array<float, 3> kRowPositions { -kCubeSize - kGroundGap / 2,
                                               0.0F,
                                               kCubeSize + kGroundGap / 2 };
} // namespace

Obstacle::Obstacle() : speed(kDefaultSpeed) { this->resetPosition(); }

Vector3 Obstacle::getPosition() const { return this->position; }

float Obstacle::getSpeed() const { return this->speed; }

void Obstacle::setSpeed(float speed) { this->speed = speed; }

void Obstacle::loopTowardsViewer()
{
    {
        Vector3 newPosition { this->position };
        newPosition.z += this->speed;
        this->position = newPosition;
    }

    // TODO: Refactor this code to ACTUALLY reach screen height and NOT count on
    // cube size.
    // Reset position if obstacle reaches screen height
    if (this->position.z >= kCubeSize * 2)
    {
        this->resetPosition();
    }
}

void Obstacle::resetPosition()
{
    Vector3 startingPosition {};

    {
        // Get random row index
        int randomRowIndex { GetRandomValue(0, kRowPositions.size() - 1) };

        // Get random row
        float randomRow { kRowPositions[randomRowIndex] };

        // Get a random column, which is forward or backward, the z-axis
        auto randomColumn { static_cast<float>(
            GetRandomValue(kMinStartPos, kMaxStartPos)) };

        // Combine both positions
        startingPosition = { randomRow, 0.0F, randomColumn };
    }

    // Set random position
    this->position = startingPosition;
}

void Obstacle::draw() const
{
    DrawCube(this->position, kCubeSize, kCubeSize, kCubeSize, RED);
    DrawCubeWires(this->position, kCubeSize, kCubeSize, kCubeSize, BLACK);
}
