#include "raylib.h"
#include <vector>

#include "../include/constants.h"
#include "../include/menu.h"
#include "../include/world.h"

constexpr int SCREEN_WIDTH = 1000;
constexpr int SCREEN_HEIGHT = 750;

int main()
{
    // Initialize window
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);

    // Initialize world
    World world;

    // Initialize menu
    Menu menu(&world);

    // Don't quit on ESC
    SetExitKey(KEY_NULL);

    // Set FPS
    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())
    {
        // FIX: Transparent screen
        menu.draw();
        // world.play();
    }

    return 0;
}
