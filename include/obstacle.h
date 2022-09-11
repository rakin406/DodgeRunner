#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "raylib.h"

class Obstacle
{
public:
    Obstacle();

    // Set obstacle position
    void setObstaclePosition(Vector3 newPosition) { position = newPosition; }

    // Get obstacle position
    Vector3 getObstaclePosition() { return position; }

    void moveTowardsViewer();
    void draw();

private:
    Vector3 position;
};

#endif
