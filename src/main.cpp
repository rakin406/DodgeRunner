#include "../include/constants.h"
#include "../include/obstacle.h"
#include "../include/player.h"
#include "raylib.h"
#include <fmt/core.h>

// Program main entry point
int main()
{
    // Initialization
    InitWindow(SCREEN::width, SCREEN::height, "Jumperino");

    // Define the camera to look into our 3d world
    Camera3D camera = {0};
    camera.position = (Vector3){0.0F, 5.0F, 10.0F}; // Camera position
    camera.target = (Vector3){0.0F, 1.0F, 0.0F};    // Camera looking at point
    camera.up = (Vector3){0.0F, 1.0F,
                          0.0F}; // Camera up vector (rotation towards target)
    camera.fovy = 45.0F;         // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE; // Camera mode type

    // Initialize cube as player
    Player player;

    // Initialize obstacle
    // TODO: Create a vector of obstacles
    Obstacle obstacle;

    // TODO: Increment score with a bit of delay
    int score = 0;

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())
    {
        ////////////// Update //////////////

        // Player movement
        if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A))
        {
            player.move(Direction::Left);
        }
        else if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D))
        {
            player.move(Direction::Right);
        }

        obstacle.loopTowardsViewer();

        ++score;
        switch (score)
        {
        case 5000:
            obstacle.setSpeed(1.5F);
            break;
        case 10000:
            obstacle.setSpeed(2.0F);
            break;
        default:
            break;
        }

        ////////////// Draw ///////////////

        BeginDrawing();

        ClearBackground(RAYWHITE);

        // View score
        DrawText(fmt::format("Score: {}", score).c_str(), 15, 15, 30, BLACK);

        BeginMode3D(camera);

        // Draw ground
        DrawPlane((Vector3){0.0F, -CUBE_SIZE, 0.0F}, GROUND::size, LIGHTGRAY);

        // Draw player cube
        player.draw();

        // Draw obstacle
        obstacle.draw();

        EndMode3D();

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}
