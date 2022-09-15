#include "raylib.h"
#include <fmt/core.h>
#include <vector>

#include "../include/constants.h"
#include "../include/menu.h"
#include "../include/utils.h"
#include "../include/world.h"

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
