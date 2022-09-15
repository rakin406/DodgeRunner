#include "raylib.h"
#include <fmt/core.h>

#include "../include/constants.h"
#include "../include/menu.h"
#include "../include/utils.h"

void drawOptions(const std::string &currentOption, bool isPaused)
{
    // TODO: Remove all these hard-coded measurements
    int optionX = screen::WIDTH / 2 - 70;
    int optionY = screen::HEIGHT / 2 - 50;
    int optionFontSize = FONT_SIZE + 15;
    int gap = 75;

    // TODO: MUST refactor this large dirty code
    if (isPaused)
    {
        for (const auto &option : OPTIONS_IN_PAUSE)
        {
            // Highlight option on cursor
            if (option == currentOption)
            {
                DrawText(option.c_str(), optionX, optionY, optionFontSize,
                         GREEN);
            }
            else
            {
                DrawText(option.c_str(), optionX, optionY, optionFontSize,
                         BLACK);
            }
            optionY += gap;
        }
    }
    else
    {
        for (const auto &option : OPTIONS_IN_START)
        {
            // Highlight option on cursor
            if (option == currentOption)
            {
                DrawText(option.c_str(), optionX, optionY, optionFontSize,
                         GREEN);
            }
            else
            {
                DrawText(option.c_str(), optionX, optionY, optionFontSize,
                         BLACK);
            }
            optionY += gap;
        }
    }
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
