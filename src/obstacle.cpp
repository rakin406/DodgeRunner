#include "../include/obstacle.h"
#include "../include/constants.h"

const int MIN_START_POS = -300;
const int MAX_START_POS = -200;

Obstacle::Obstacle() { this->resetPosition(); }

void Obstacle::loopTowardsViewer()
{
    Vector3 newPosition = this->position;
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
    int randomRowIndex = GetRandomValue(0, ROW_POSITIONS.size() - 1);
    float randomRow = ROW_POSITIONS[randomRowIndex];
    auto randomColumn = (float)GetRandomValue(MIN_START_POS, MAX_START_POS);
    Vector3 startingPosition = {randomRow, 0.0F, randomColumn};
    this->position = startingPosition;
}

void Obstacle::draw() const
{
    DrawCube(this->position, CUBE_SIZE, CUBE_SIZE, CUBE_SIZE, RED);
    DrawCubeWires(this->position, CUBE_SIZE, CUBE_SIZE, CUBE_SIZE, BLACK);
}
