#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

// This class contains all the functions of the player cube
class Player
{
public:
    Player();

    // Set player position
    void setPlayerPosition(Vector3 newPosition) { position = newPosition; }

    // Get player position
    Vector3 getPlayerPosition() { return position; }

    // TODO: Remove this function and change it to moveLeft() and moveRight()
    void moveForward();

    // Draw player cube on screen
    void draw();

private:
    // Player cube position
    Vector3 position;
};

#endif
