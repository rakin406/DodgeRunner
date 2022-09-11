#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "raylib.h"

// This class contains all the functions of a single obstacle
class Obstacle
{
public:
    Obstacle();

    // Set obstacle position
    void setObstaclePosition(Vector3 newPosition) { position = newPosition; }

    // Get obstacle position
    Vector3 getObstaclePosition() { return position; }

    // Move obstacle towards viewer
    void moveTowardsViewer();

    // Draw obstacle on screen
    void draw();

private:
    // Obstacle position
    Vector3 position;
};

#endif
