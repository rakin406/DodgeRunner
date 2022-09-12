#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "./constants.h"
#include "raylib.h"

const int MIN_START_POS = -300;
const int MAX_START_POS = -200;

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
    [[nodiscard]] Vector3 getPosition() const { return position; }

    /**
     * Set obstacle movement speed.
     *
     * @param newSpeed New speed of obstacle.
     */
    void setSpeed(float newSpeed) { speed = newSpeed; }

    /**
     * Get obstacle movement speed.
     *
     * @return obstacle movement speed.
     */
    [[nodiscard]] float getSpeed() const { return speed; }

    // Move obstacle towards viewer and reset position to starting point when
    // obstacle reaches screen height.
    void loopTowardsViewer();

    // Reset obstacle position to starting point
    void resetPosition();

    // Draw obstacle on screen
    void draw() const;

private:
    Vector3 position = {};                // Obstacle position
    float speed = DEFAULT_OBSTACLE_SPEED; // Obstacle movement speed
};

#endif
