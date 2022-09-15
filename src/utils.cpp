#include "raylib.h"
#include <fmt/core.h>

#include "../include/constants.h"
#include "../include/utils.h"

void utils::world::drawGround()
{
    DrawPlane((Vector3){0.0F, -CUBE_SIZE, 0.0F}, ground::SIZE, LIGHTGRAY);
}

void utils::world::viewScore(int score)
{
    DrawText(fmt::format("Score: {}", score).c_str(), 15, 15, FONT_SIZE, BLACK);
}

bool utils::world::checkCollision(Player player,
                                  const std::vector<Obstacle> &obstacles)
{
    Vector3 playerPosition = player.position;
    for (const auto &elem : obstacles)
    {
        Vector3 obstaclePosition = elem.position;
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
