#include "raylib.h"
#include <vector>

#include "../include/constants.h"
#include "../include/utils.h"
#include "../include/world.h"

constexpr int DEFAULT_OBSTACLES = 10;

// NOTE: It doesn't increment... This is used for division and the reminder is
// used for increasing speed. I just need a better name for this variable...
// After the specified score, increase the obstacle speed.
constexpr int SCORE_INCREMENT = 5000;

// Used for incrementing to the original speed
constexpr float SPEED_INCREMENT = 0.5F;

namespace camera
{
constexpr Vector3 POSITION = {0.0F, 5.0F, 10.0F};
constexpr float FOV = 45.0F;
} // namespace camera

World::World() : obstacles({})
{
    // Set a custom random seed for random number generation.
    // Needed for random obstacle position.
    SetRandomSeed(0xaabbccff);

    // Define the camera to look into our 3d world
    this->camera.position = camera::POSITION;
    this->camera.target =
        (Vector3){0.0F, 1.0F, 0.0F}; // Camera looking at point
    this->camera.up = (Vector3){
        0.0F, 1.0F, 0.0F}; // Camera up vector (rotation towards target)
    this->camera.fovy = camera::FOV;              // Camera field-of-view Y
    this->camera.projection = CAMERA_PERSPECTIVE; // Camera mode type

    // Re-initialize obstacles
    for (int i = 0; i < DEFAULT_OBSTACLES; ++i)
    {
        Obstacle obs;
        this->obstacles.push_back(obs);
    }
}

void World::draw()
{
    BeginDrawing();

    // Clear background
    ClearBackground(RAYWHITE);

    // View score at top left
    utils::world::viewScore(this->score);

    // Start viewing in 3D
    BeginMode3D(this->camera);

    // Draw the ground/floor
    utils::world::drawGround();

    // Draw player cube
    this->player.draw();

    // Draw obstacle cubes
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
    // Stop movement if game is over
    if (!this->gameOver)
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

            // Stop game if player and obstacle collides
            if (utils::world::checkCollision(player, elem))
            {
                this->gameOver = true;
            }
        }

        ++this->score;
    }

    // Finally draw the world
    this->draw();
}
