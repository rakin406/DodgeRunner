#include "../include/obstacle.h"
#include "../include/constants.h"
#include "raylib.h"

#define DEFAULT_SPEED 1.0F

Obstacle::Obstacle()
{
    this->resetPosition();
    this->setSpeed(DEFAULT_SPEED);
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
    Vector3 startingPosition = {0.0F, 0.0F, (float)-SCREEN::height};
    this->setPosition(startingPosition);
}

void Obstacle::draw() const
{
    DrawCube(this->getPosition(), CUBE_SIZE, CUBE_SIZE, CUBE_SIZE, RED);
    DrawCubeWires(this->getPosition(), CUBE_SIZE, CUBE_SIZE, CUBE_SIZE, BLACK);
}
