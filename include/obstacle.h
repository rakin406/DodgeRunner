#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "raylib.h"

// This class contains all the functions of a single obstacle
class Obstacle
{
public:
    Vector3 position; // Obstacle position
    float speed;      // Obstacle movement speed

    Obstacle();

    // Move obstacle towards viewer and reset position to starting point when
    // obstacle reaches screen height.
    void loopTowardsViewer();

    // Reset obstacle position to starting point
    void resetPosition();

    // Draw obstacle on screen
    void draw() const;

private:
};

#endif
