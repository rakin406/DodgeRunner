#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

class Player
{
public:
    Player();

    // Set player position
    void setPlayerPosition(Vector3 newPosition) { position = newPosition; }

    // Get player position
    Vector3 getPlayerPosition() { return position; }

    void moveForward();
    void draw();

private:
    Vector3 position;
};

#endif
