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
     * Move obstacle towards viewer.
     *
     * @param speed Movement speed of obstacle.
     */
    void moveTowardsViewer(float speed);

    // Draw obstacle on screen
    void draw();

private:
    // Obstacle position
    Vector3 position;
};

#endif
