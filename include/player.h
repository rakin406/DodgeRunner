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

    // Get player position
    Vector3 getPosition();

    /**
     * Move player cube to specified direction.
     *
     * @param direction Desired direction for player cube.
     */
    void move(Direction direction);

    // Draw player cube on screen
    void draw() const;

private:
    Vector3 position{}; // Player cube position
    int currentRow{};   // Current ground row of player cube
};

#endif
