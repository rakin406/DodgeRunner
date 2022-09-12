#include "../include/obstacle.h"
#include "../include/constants.h"
#include "raylib.h"

Obstacle::Obstacle()
{
    this->resetPosition();
    this->setSpeed(DEFAULT_OBSTACLE_SPEED);
}

void Obstacle::loopTowardsViewer()
{
    Vector3 newPosition = this->getPosition();
    newPosition.z += this->getSpeed();
    this->setPosition(newPosition);

    // TODO: Refactor this code to ACTUALLY reach screen height and NOT count on
    // cube size.
    // Reset position if obstacle reaches screen height
    if (this->getPosition().z >= CUBE_SIZE * 2)
    {
        this->resetPosition();
    }
}

void Obstacle::resetPosition()
{
    float randomRow =
        ROW_POSITIONS[GetRandomValue(0, ROW_POSITIONS.size() - 1)];
    auto randomColumn = (float)GetRandomValue(-300, -200);
    Vector3 startingPosition = {randomRow, 0.0F, randomColumn};
    this->setPosition(startingPosition);
}

void Obstacle::draw() const
{
    DrawCube(this->getPosition(), CUBE_SIZE, CUBE_SIZE, CUBE_SIZE, RED);
    DrawCubeWires(this->getPosition(), CUBE_SIZE, CUBE_SIZE, CUBE_SIZE, BLACK);
}
