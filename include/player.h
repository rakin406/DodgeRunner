#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

// All possible directions for player cube
enum class Direction
{
    Left,
    Right
};

// This class contains all the functions of the player cube
class Player
{
public:
    Player();

    /**
     * Set player position.
     *
     * @param newPosition New position of player cube.
     */
    void setPosition(Vector3 newPosition) { position = newPosition; }

    /**
     * Get player cube position.
     *
     * @return player cube position.
     */
    Vector3 getPosition() { return position; }

    /**
     * Move player cube to specified direction.
     *
     * @param direction Desired direction for player cube.
     */
    void move(Direction direction);

    // Draw player cube on screen
    void draw();

private:
    // Player cube position
    Vector3 position;
};

#endif
