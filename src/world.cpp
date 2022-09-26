#include "../include/world.h"
#include "../include/constants.h"

#include <raylib.h>
#include <vector>

namespace
{

constexpr int MAX_OBSTACLES { 10 };

// NOTE: It doesn't increment... This is used for division and the reminder is
// used for increasing speed. I just need a better name for this variable...
// After the specified score, increase the obstacle speed.
constexpr int SCORE_INCREMENT { 5000 };

// Used for incrementing to the original speed
constexpr float SPEED_INCREMENT { 0.5F };

/**
 * @brief Return true if player cube collides with obstacle.
 *
 * @param player Player cube.
 * @param obstacle Obstacle.
 *
 * @return boolean.
 */
bool checkCollision(const Player& player, const Obstacle& obstacle)
{
    using constants::CUBE_SIZE;

    Vector3 playerPos { player.getPosition() };
    Vector3 obstaclePos { obstacle.getPosition() };

    return CheckCollisionBoxes(
        (BoundingBox) { (Vector3) { playerPos.x - CUBE_SIZE / 2,
                                    playerPos.y - CUBE_SIZE / 2,
                                    playerPos.z - CUBE_SIZE / 2 },
                        (Vector3) { playerPos.x + CUBE_SIZE / 2,
                                    playerPos.y + CUBE_SIZE / 2,
                                    playerPos.z + CUBE_SIZE / 2 } },
        (BoundingBox) { (Vector3) { obstaclePos.x - CUBE_SIZE / 2,
                                    obstaclePos.y - CUBE_SIZE / 2,
                                    obstaclePos.z - CUBE_SIZE / 2 },
                        (Vector3) { obstaclePos.x + CUBE_SIZE / 2,
                                    obstaclePos.y + CUBE_SIZE / 2,
                                    obstaclePos.z + CUBE_SIZE / 2 } });
}

namespace camera
{
constexpr Vector3 POSITION { 0.0F, 5.0F, 10.0F };
constexpr float FOV { 45.0F };
} // namespace camera
} // namespace

World::World() : m_obstacles({})
{
    // Needed for random obstacle position.
    SetRandomSeed(0xaabbccff);

    // Create 3D camera
    initializeCamera();

    // Create obstacle cubes
    initializeObstacles();
}

void World::play()
{
    if (!m_gameOver)
    {
        handlePlayerMovement();
        updateObstacles();
        ++m_score;
    }

    draw();
}

void World::initializeCamera()
{
    // Define the camera to look into our 3d world
    m_camera.position = camera::POSITION;

    // Camera looking at point
    m_camera.target = (Vector3) { 0.0F, 1.0F, 0.0F };

    // Camera up vector (rotation towards target)
    m_camera.up = (Vector3) { 0.0F, 1.0F, 0.0F };

    // Camera field-of-view Y
    m_camera.fovy = camera::FOV;

    // Camera mode type
    m_camera.projection = CAMERA_PERSPECTIVE;
}

void World::initializeObstacles()
{
    for (int i { 0 }; i < MAX_OBSTACLES; ++i)
    {
        Obstacle obs;
        m_obstacles.push_back(obs);
    }
}

void World::handlePlayerMovement()
{
    using direction::Direction;

    if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A))
    {
        m_player.move(Direction::left);
    }
    else if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D))
    {
        m_player.move(Direction::right);
    }
}

void World::updateObstacles()
{
    for (auto& elem : m_obstacles)
    {
        // Move obstacle towards viewer
        elem.loopTowardsViewer();

        // Increase speed of obstacles according to score
        if (m_score % SCORE_INCREMENT == 0)
        {
            elem.setSpeed(elem.getSpeed() + SPEED_INCREMENT);
        }

        // Stop game if player and obstacle collides
        if (checkCollision(m_player, elem))
        {
            m_gameOver = true;
        }
    }
}

void World::viewScore() const
{
    // Draw score text at top left of screen
    DrawText(TextFormat("Score: %i", m_score), 15, 15, constants::FONT_SIZE,
             BLACK);
}

void World::drawGround()
{
    float groundWidth { (constants::CUBE_SIZE * 3.5F) + constants::GROUND_GAP };
    Vector2 groundSize { groundWidth, static_cast<float>(GetScreenHeight()) };
    DrawPlane((Vector3) { 0.0F, -constants::CUBE_SIZE, 0.0F }, groundSize,
              LIGHTGRAY);
}

void World::drawObstacles()
{
    for (auto& elem : m_obstacles)
    {
        elem.draw();
    }
}

void World::draw()
{
    BeginDrawing();

    ClearBackground(RAYWHITE);

    viewScore();

    BeginMode3D(m_camera);

    drawGround();
    m_player.draw();
    drawObstacles();

    EndMode3D();

    EndDrawing();
}
