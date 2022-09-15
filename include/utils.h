#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

#include "obstacle.h"
#include "player.h"

namespace utils::menu
{
/**
 * Draw options in menu screen.
 *
 * @param currentOption Option under cursor.
 */
void drawOptions(const std::string &currentOption, bool isPaused);
} // namespace utils::menu

namespace utils::world
{
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
} // namespace utils::world

#endif
