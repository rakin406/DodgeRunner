#include "../include/obstacle.h"
#include "../include/constants.h"
#include "raylib.h"

Obstacle::Obstacle()
{
    Vector3 startingPosition = {0.0F, 0.0F, 0.0F};
    this->setObstaclePosition(startingPosition);
}

void Obstacle::moveTowardsViewer()
{
    Vector3 newPosition = this->getObstaclePosition();
    newPosition.z += 0.1F;
    this->setObstaclePosition(newPosition);
}

void Obstacle::draw()
{
    DrawCube(this->getObstaclePosition(), CUBE_SIZE, CUBE_SIZE, CUBE_SIZE, RED);
    DrawCubeWires(this->getObstaclePosition(), CUBE_SIZE, CUBE_SIZE, CUBE_SIZE,
                  BLACK);
}
