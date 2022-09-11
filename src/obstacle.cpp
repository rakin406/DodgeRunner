#include "../include/obstacle.h"
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
    DrawCube(this->getObstaclePosition(), 2.0F, 2.0F, 2.0F, RED);
    DrawCubeWires(this->getObstaclePosition(), 2.0F, 2.0F, 2.0F, BLACK);
}
