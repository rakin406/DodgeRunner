#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "raylib.h"

// This class contains all the functions of a single obstacle
class Obstacle
{
public:
    Obstacle();

    // Get obstacle position
    [[nodiscard]] Vector3 getPosition() const;

    // Get obstacle speed
    [[nodiscard]] float getSpeed() const;

    // Set obstacle speed
    void setSpeed(float speed);

    // Move obstacle towards viewer and reset position to starting point when
    // obstacle reaches screen height.
    void loopTowardsViewer();

    // Reset obstacle position to starting point
    void resetPosition();

    // Draw obstacle on screen
    void draw() const;

private:
    Vector3 position{}; // Obstacle position
    float speed{};      // Obstacle movement speed
};

#endif
