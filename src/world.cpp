#include "raylib.h"
#include <fmt/core.h>
#include <vector>

#include "../include/constants.h"
#include "../include/menu.h"
#include "../include/world.h"

// Draw ground on screen
void drawGround();

/**
 * View score on screen.
 *
 * @param score Player score.
 */
void viewScore(int score);

/**
 * Return true if player cube collides with any obstacles.
 *
 * @param player Player cube.
 * @param obstacles Obstacles.
 * @return boolean.
 */
bool checkCollision(Player player, const std::vector<Obstacle> &obstacles);

World::World()
{
    // Define the camera to look into our 3d world
    this->camera.position = camera::POSITION;
    this->camera.target =
        (Vector3){0.0F, 1.0F, 0.0F}; // Camera looking at point
    this->camera.up = (Vector3){
        0.0F, 1.0F, 0.0F}; // Camera up vector (rotation towards target)
    this->camera.fovy = camera::FOV;              // Camera field-of-view Y
    this->camera.projection = CAMERA_PERSPECTIVE; // Camera mode type

    // Initialize obstacles
    for (int i = 0; i < DEFAULT_OBSTACLES; ++i)
    {
        Obstacle obs;
        this->obstacles.push_back(obs);
    }

    // Set a custom random seed for random number generation.
    // Needed for random obstacle position.
    SetRandomSeed(0xaabbccff);
}

void World::draw()
{
    BeginDrawing();

    ClearBackground(RAYWHITE);

    viewScore(this->score);

    BeginMode3D(this->camera);

    drawGround();

    // Draw player cube
    this->player.draw();

    // Draw obstacles
    for (auto &elem : this->obstacles)
    {
        elem.draw();
    }

    EndMode3D();

    EndDrawing();
}

void World::play()
{
    // TODO: Make this code branch shorter and refactor it
    // Stop game if player and obstacle collides
    if (checkCollision(player, obstacles))
    {
        this->isCollided = true;
    }

    // Stop movement if collision occurs
    if (!this->isCollided)
    {
        // Player movement
        if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A))
        {
            this->player.move(Direction::Left);
        }
        else if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D))
        {
            this->player.move(Direction::Right);
        }

        // Updating obstacles
        for (auto &elem : this->obstacles)
        {
            // Move obstacles towards viewer
            elem.loopTowardsViewer();

            // Increase speed of obstacles according to score
            if (this->score % SCORE_INCREMENT == 0)
            {
                elem.setSpeed(elem.getSpeed() + SPEED_INCREMENT);
            }
        }

        ++this->score;
    }

    // Finally draw the world
    this->draw();
}

void drawGround()
{
    DrawPlane((Vector3){0.0F, -CUBE_SIZE, 0.0F}, ground::SIZE, LIGHTGRAY);
}

void viewScore(int score)
{
    DrawText(fmt::format("Score: {}", score).c_str(), 15, 15, FONT_SIZE, BLACK);
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
