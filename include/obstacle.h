#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "raylib.h"

// This class contains all the functions of a single obstacle
class Obstacle
{
public:
    Obstacle();

    /**
     * Set obstacle position.
     *
     * @param newPosition New position of obstacle.
     */
    void setPosition(Vector3 newPosition) { position = newPosition; }

    /**
     * Get obstacle position.
     *
     * @return obstacle position.
     */
    Vector3 getPosition() { return position; }

    /**
     * Move obstacle towards viewer and reset position to starting point when
     * obstacle reaches screen height.
     *
     * @param speed Movement speed of obstacle.
     */
    void loopTowardsViewer(float speed);

    // Reset obstacle position to starting point
    void resetPosition();

    // Draw obstacle on screen
    void draw();

private:
    // Obstacle position
    Vector3 position;
};

#endif
