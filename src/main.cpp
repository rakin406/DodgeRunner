#include "raylib.h"

#include "../include/world.h"

// Screen constants
constexpr char SCREEN_TITLE[] = "Dodge Runner";
constexpr int SCREEN_WIDTH = 1000;
constexpr int SCREEN_HEIGHT = 750;

int main()
{
    // Set window settings
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_MSAA_4X_HINT);

    // Initialize window
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);

    // Initialize world
    World world;

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Start world
        world.play();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}
