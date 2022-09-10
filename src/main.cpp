#include "../include/player.h"
#include "raylib.h"

// Program main entry point
int main()
{
    // Initialization
    const int SCREEN_WIDTH = 1000;
    const int SCREEN_HEIGHT = 750;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Jumperino");

    // Define the camera to look into our 3d world
    Camera3D camera = {0};
    camera.position = (Vector3){0.0F, 10.0F, 10.0F}; // Camera position
    camera.target = (Vector3){0.0F, 0.0F, 0.0F};     // Camera looking at point
    camera.up = (Vector3){0.0F, 1.0F,
                          0.0F}; // Camera up vector (rotation towards target)
    camera.fovy = 45.0F;         // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE; // Camera mode type

    Player player;

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        // TODO: Update your variables here

        // Draw
        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        player.draw();

        EndMode3D();

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}
