#ifndef WORLD_H
#define WORLD_H

#include "raylib.h"
#include <vector>

#include "obstacle.h"
#include "player.h"

/**
 * @brief This class contains the main functions of the game.
 */
class World
{
public:
    /**
     * @brief Default constructor for World initialization.
     */
    World();

    /**
     * @brief Play and draw the world.
     */
    void play();

private:
    Camera3D camera{};                 // Initialize camera
    Player player{};                   // Initialize cube as player
    std::vector<Obstacle> obstacles{}; // Initialize obstacles
    bool gameOver = false;             // Boolean for checking pause
    int score = 0;                     // Player score

    void draw();
};

#endif
