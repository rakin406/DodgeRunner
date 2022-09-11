#include "../include/obstacle.h"
#include "../include/constants.h"
#include "raylib.h"

Obstacle::Obstacle() { this->resetPosition(); }

void Obstacle::loopTowardsViewer(float speed)
{
    Vector3 newPosition = this->getPosition();
    newPosition.z += speed;
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
    Vector3 startingPosition = {0.0F, 0.0F, (float)-SCREEN.height};
    this->setPosition(startingPosition);
}

void Obstacle::draw()
{
    DrawCube(this->getPosition(), CUBE_SIZE, CUBE_SIZE, CUBE_SIZE, RED);
    DrawCubeWires(this->getPosition(), CUBE_SIZE, CUBE_SIZE, CUBE_SIZE, BLACK);
}
