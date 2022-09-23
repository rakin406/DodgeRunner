#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "raylib.h"

/**
 * @brief This class contains all the functions of a single obstacle.
 */
class Obstacle
{
public:
    /**
     * @brief Default constructor for Obstacle initialization.
     */
    Obstacle();

    /**
     * @brief Get obstacle position.
     *
     * @return Vector3.
     */
    [[nodiscard]] Vector3 getPosition() const;

    /**
     * @brief Get obstacle speed.
     *
     * @return float.
     */
    [[nodiscard]] float getSpeed() const;

    /**
     * @brief Set obstacle speed.
     *
     * @param speed.
     */
    void setSpeed(float speed);

    /**
     * @brief Move obstacle towards viewer and reset position to starting point
     * when obstacle reaches screen height.
     */
    void loopTowardsViewer();

    /**
     * @brief Reset obstacle position to starting point.
     */
    void resetPosition();

    /**
     * @brief Draw obstacle on screen.
     */
    void draw() const;

private:
    Vector3 position{}; // Obstacle position
    float speed{};      // Obstacle movement speed
};

#endif
