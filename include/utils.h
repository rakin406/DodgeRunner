#ifndef UTILS_H
#define UTILS_H

#include <vector>

#include "obstacle.h"
#include "player.h"

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
