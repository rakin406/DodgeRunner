#include "../include/obstacle.h"
#include "../include/constants.h"
#include "raylib.h"

Obstacle::Obstacle()
{
    Vector3 startingPosition = {0.0F, 0.0F, (float)-SCREEN.height};
    this->setPosition(startingPosition);
}

void Obstacle::moveTowardsViewer(float speed)
{
    Vector3 newPosition = this->getPosition();
    newPosition.z += speed;
    this->setPosition(newPosition);
}

void Obstacle::draw()
{
    DrawCube(this->getPosition(), CUBE_SIZE, CUBE_SIZE, CUBE_SIZE, RED);
    DrawCubeWires(this->getPosition(), CUBE_SIZE, CUBE_SIZE, CUBE_SIZE, BLACK);
}
