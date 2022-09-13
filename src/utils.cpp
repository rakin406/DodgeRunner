#include "../include/utils.h"
#include "../include/constants.h"
#include "raylib.h"
#include <fmt/core.h>

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
