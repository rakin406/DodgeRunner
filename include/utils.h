#ifndef UTILS_H
#define UTILS_H

#include <vector>

#include "obstacle.h"
#include "player.h"

namespace utils::world
{
/**
 * @brief Draw ground on screen.
 */
void drawGround();

/**
 * @brief View score on screen.
 *
 * @param score Player score.
 */
void viewScore(int score);

/**
 * @brief Return true if player cube collides with obstacle.
 *
 * @param player Player cube.
 * @param obstacle Obstacle.
 *
 * @return boolean.
 */
bool checkCollision(const Player &player, const Obstacle &obstacle);
} // namespace utils::world

#endif
