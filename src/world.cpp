#include "../include/world.h"
#include "../include/constants.h"

#include <raylib.h>

#include <vector>

namespace
{

constexpr int kMaxObstacles { 10 };

// NOTE: It doesn't increment... This is used for division and the reminder is
// used for increasing speed. I just need a better name for this variable...
// After the specified score, increase the obstacle speed.
constexpr int kScoreIncrement { 5000 };

// Used for incrementing to the original speed
constexpr float kSpeedIncrement { 0.5F };

/**
 * @brief Return true if player cube collides with obstacle.
 *
 * @param player Player cube.
 * @param obstacle Obstacle.
 *
 * @return boolean.
 */
bool checkCollision(const Player &player, const Obstacle &obstacle)
{
    // Get player position
    Vector3 playerPos { player.getPosition() };
    // Get obstacle position
    Vector3 obstaclePos { obstacle.getPosition() };

    return CheckCollisionBoxes(
        (BoundingBox) { (Vector3) { playerPos.x - kCubeSize / 2,
                                    playerPos.y - kCubeSize / 2,
                                    playerPos.z - kCubeSize / 2 },
                        (Vector3) { playerPos.x + kCubeSize / 2,
                                    playerPos.y + kCubeSize / 2,
                                    playerPos.z + kCubeSize / 2 } },
        (BoundingBox) { (Vector3) { obstaclePos.x - kCubeSize / 2,
                                    obstaclePos.y - kCubeSize / 2,
                                    obstaclePos.z - kCubeSize / 2 },
                        (Vector3) { obstaclePos.x + kCubeSize / 2,
                                    obstaclePos.y + kCubeSize / 2,
                                    obstaclePos.z + kCubeSize / 2 } });
}

namespace camera
{
constexpr Vector3 POSITION { 0.0F, 5.0F, 10.0F };
constexpr float FOV { 45.0F };
} // namespace camera
} // namespace

World::World() : obstacles({})
{
    // Set a custom random seed for random number generation.
    // Needed for random obstacle position.
    SetRandomSeed(0xaabbccff);

    // Create 3D camera
    this->initializeCamera();

    // Create obstacle cubes
    this->initializeObstacles();
}

void World::play()
{
    // Stop movement if game is over
    if (!this->gameOver)
    {
        this->handlePlayerMovement();
        this->updateObstacles();
        ++this->score; // Increase score
    }

    // Finally draw the world
    this->draw();
}

void World::initializeCamera()
{
    // Define the camera to look into our 3d world
    this->camera.position = camera::POSITION;

    // Camera looking at point
    this->camera.target = (Vector3) { 0.0F, 1.0F, 0.0F };

    // Camera up vector (rotation towards target)
    this->camera.up = (Vector3) { 0.0F, 1.0F, 0.0F };

    // Camera field-of-view Y
    this->camera.fovy = camera::FOV;

    // Camera mode type
    this->camera.projection = CAMERA_PERSPECTIVE;
}

void World::initializeObstacles()
{
    for (int i = 0; i < kMaxObstacles; ++i)
    {
        Obstacle obs;
        this->obstacles.push_back(obs);
    }
}

void World::handlePlayerMovement()
{
    // Move left
    if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A))
    {
        this->player.move(Direction::Left);
    }
    // Move right
    else if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D))
    {
        this->player.move(Direction::Right);
    }
}

void World::updateObstacles()
{
    // Loop all obstacles
    for (auto &elem : this->obstacles)
    {
        // Move obstacles towards viewer
        elem.loopTowardsViewer();

        // Increase speed of obstacles according to score
        if (this->score % kScoreIncrement == 0)
        {
            elem.setSpeed(elem.getSpeed() + kSpeedIncrement);
        }

        // Stop game if player and obstacle collides
        if (checkCollision(this->player, elem))
        {
            this->gameOver = true;
        }
    }
}

void World::viewScore() const
{
    DrawText(TextFormat("Score: %i", this->score), 15, 15, kFontSize, BLACK);
}

void World::drawGround()
{
    float groundWidth { (kCubeSize * 3.5F) + kGroundGap };
    Vector2 groundSize { groundWidth, static_cast<float>(GetScreenHeight()) };
    DrawPlane((Vector3) { 0.0F, -kCubeSize, 0.0F }, groundSize, LIGHTGRAY);
}

void World::drawObstacles()
{
    // Loop all obstacles
    for (auto &elem : this->obstacles)
    {
        elem.draw();
    }
}

void World::draw()
{
    BeginDrawing();

    // Clear background
    ClearBackground(RAYWHITE);

    // View score at top left
    this->viewScore();

    // Start viewing in 3D
    BeginMode3D(this->camera);

    // Draw the ground/floor
    this->drawGround();

    // Draw player cube
    this->player.draw();

    // Draw obstacle cubes
    this->drawObstacles();

    EndMode3D();

    EndDrawing();
}
