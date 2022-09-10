#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

class Player
{
public:
    Player() { cubePosition = {0.0F, 0.0F, 0.0F}; }

    // Set player position
    void setPlayerPosition(Vector3 newPosition) { cubePosition = newPosition; }

    // Get player position
    Vector3 getPlayerPosition() { return cubePosition; }

    void draw();

private:
    Vector3 cubePosition{};
};

#endif
