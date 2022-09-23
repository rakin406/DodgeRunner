#include "raylib.h"

#include "../include/constants.h"
#include "../include/world.h"

int main()
{
    // Initialize window
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);

    // Initialize world
    World world;

    // Set FPS
    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())
    {
        world.play();
    }

    return 0;
}
