#include "raylib.h"

#include "../include/constants.h"
#include "../include/utils.h"

void utils::world::drawGround()
{
    DrawPlane((Vector3){0.0F, -CUBE_SIZE, 0.0F}, ground::SIZE, LIGHTGRAY);
}

void utils::world::viewScore(int score)
{
    DrawText(TextFormat("Score: %i", score), 15, 15, FONT_SIZE, BLACK);
}

bool utils::world::checkCollision(Player player, Obstacle obstacle)
{
    Vector3 playerPos = player.getPosition();
    Vector3 obstaclePos = obstacle.getPosition();

    return CheckCollisionBoxes(
        (BoundingBox){
            (Vector3){playerPos.x - CUBE_SIZE / 2, playerPos.y - CUBE_SIZE / 2,
                      playerPos.z - CUBE_SIZE / 2},
            (Vector3){playerPos.x + CUBE_SIZE / 2, playerPos.y + CUBE_SIZE / 2,
                      playerPos.z + CUBE_SIZE / 2}},
        (BoundingBox){(Vector3){obstaclePos.x - CUBE_SIZE / 2,
                                obstaclePos.y - CUBE_SIZE / 2,
                                obstaclePos.z - CUBE_SIZE / 2},
                      (Vector3){obstaclePos.x + CUBE_SIZE / 2,
                                obstaclePos.y + CUBE_SIZE / 2,
                                obstaclePos.z + CUBE_SIZE / 2}});
}
