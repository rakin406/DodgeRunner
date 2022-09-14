#include "raylib.h"
#include <vector>

#include "../include/constants.h"
#include "../include/menu.h"
#include "../include/obstacle.h"
#include "../include/player.h"
#include "../include/utils.h"

// Program main entry point
int main()
{
    // Initialization
    InitWindow(screen::WIDTH, screen::HEIGHT, screen::TITLE.c_str());

    // Define the camera to look into our 3d world
    Camera3D camera = {{0}};
    camera.position = camera::POSITION;
    camera.target = (Vector3){0.0F, 1.0F, 0.0F}; // Camera looking at point
    camera.up = (Vector3){0.0F, 1.0F,
                          0.0F}; // Camera up vector (rotation towards target)
    camera.fovy = camera::FOV;   // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE; // Camera mode type

    // Initialize cube as player
    Player player;

    // Initialize obstacles
    std::vector<Obstacle> obstacles;
    for (int i = 0; i < DEFAULT_OBSTACLES; ++i)
    {
        Obstacle obs;
        obstacles.push_back(obs);
    }

    // Initialize menu
    Menu menu;

    int score = 0;
    bool collision = false;

    // Set a custom random seed for random number generation.
    // Needed for random obstacle position.
    SetRandomSeed(0xaabbccff);

    // Don't quit on ESC
    SetExitKey(KEY_NULL);

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())
    {
        ////////////// Update //////////////

        // TODO: Make this code branch shorter and refactor it
        // Don't start game automatically
        if (!menu.getIsStartMenu() && !menu.getIsPauseMenu())
        {
            // Stop game if player and obstacle collides
            if (checkCollision(player, obstacles))
            {
                collision = true;
            }

            // Toggle pause whenever player presses ESC
            if (IsKeyPressed(KEY_ESCAPE))
            {
                menu.setIsPauseMenu(!menu.getIsPauseMenu());
            }

            // Stop movement if collision occurs and if pause is true
            if (!collision && !menu.getIsPauseMenu())
            {
                // Player movement
                if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A))
                {
                    player.move(Direction::Left);
                }
                else if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D))
                {
                    player.move(Direction::Right);
                }

                // Updating obstacles
                for (auto &elem : obstacles)
                {
                    // Move obstacles towards viewer
                    elem.loopTowardsViewer();

                    // Increase speed of obstacles according to score
                    if (score % SCORE_INCREMENT == 0)
                    {
                        elem.setSpeed(elem.getSpeed() + SPEED_INCREMENT);
                    }
                }

                ++score;
            }
        }

        ////////////// Draw ///////////////

        BeginDrawing();

        ClearBackground(RAYWHITE);

        // TODO: Make this code branch cleaner and shorter
        // Draw menu if pause is true
        if (menu.getIsStartMenu() || menu.getIsPauseMenu())
        {
            menu.draw();
        }
        else if (!menu.getIsStartMenu() && !menu.getIsPauseMenu())
        {
            viewScore(score);

            BeginMode3D(camera);

            // Draw ground
            DrawPlane((Vector3){0.0F, -CUBE_SIZE, 0.0F}, ground::SIZE,
                      LIGHTGRAY);

            // Draw player cube
            player.draw();

            // Draw obstacles
            for (auto &elem : obstacles)
            {
                elem.draw();
            }

            EndMode3D();
        }

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}
