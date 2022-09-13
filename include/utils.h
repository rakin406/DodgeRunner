#ifndef UTILS_H
#define UTILS_H

#include "../include/obstacle.h"
#include "../include/player.h"
#include <vector>

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

#endif
