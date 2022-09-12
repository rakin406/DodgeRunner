#include "../include/constants.h"
#include "../include/obstacle.h"
#include "../include/player.h"
#include "raylib.h"
#include <fmt/core.h>
#include <iostream>
#include <vector>

#define DEFAULT_OBSTACLES 10

/**
 * Return true if player cube collides with any obstacles.
 *
 * @param player Player cube.
 * @param obstacles Obstacles.
 * @return boolean.
 */
bool checkCollision(Player player, const std::vector<Obstacle> &obstacles);

// Program main entry point
int main()
{
    // Initialization
    InitWindow(SCREEN::width, SCREEN::height, "Dodge Runner");

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

    // Initialize obstacles
    std::vector<Obstacle> obstacles;
    for (int i = 0; i < DEFAULT_OBSTACLES; ++i)
    {
        Obstacle obs;
        obstacles.push_back(obs);
    }

    int score = 0;
    bool collision = false;

    // Set a custom random seed for random number generation.
    // Needed for random obstacle position.
    SetRandomSeed(0xaabbccff);

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())
    {
        ////////////// Update //////////////

        // Ensure no collision
        if (!collision)
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
        }

        // Ensure no collision
        if (!collision)
        {
            // Updating obstacles
            for (auto &elem : obstacles)
            {
                // Move obstacles towards viewer
                elem.loopTowardsViewer();

                // Increase speed of obstacles according to score
                if (score % 5000 == 0)
                {
                    elem.setSpeed(elem.getSpeed() + 0.5F);
                }
            }

            ++score;
        }

        // Stop game if player and obstacle collides
        if (checkCollision(player, obstacles))
        {
            collision = true;
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

        // Draw obstacles
        for (auto &elem : obstacles)
        {
            elem.draw();
        }

        EndMode3D();

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}

bool checkCollision(Player player, const std::vector<Obstacle> &obstacles)
{
    Vector3 playerPosition = player.getPosition();
    for (const auto &elem : obstacles)
    {
        Vector3 obstaclePosition = elem.getPosition();
        // FIX: Collision only returns true if player touches the left and right
        // sides of the obstacle, not the front side.
        return CheckCollisionBoxes(
            (BoundingBox){(Vector3){playerPosition.x - CUBE_SIZE / 2,
                                    playerPosition.y - CUBE_SIZE / 2,
                                    playerPosition.z - CUBE_SIZE / 2},
                          (Vector3){playerPosition.x + CUBE_SIZE / 2,
                                    playerPosition.y + CUBE_SIZE / 2,
                                    playerPosition.z + CUBE_SIZE / 2}},
            (BoundingBox){(Vector3){obstaclePosition.x - CUBE_SIZE / 2,
                                    obstaclePosition.y - CUBE_SIZE / 2,
                                    obstaclePosition.z - CUBE_SIZE / 2},
                          (Vector3){obstaclePosition.x + CUBE_SIZE / 2,
                                    obstaclePosition.y + CUBE_SIZE / 2,
                                    obstaclePosition.z + CUBE_SIZE / 2}});
    }
    return false;
}
