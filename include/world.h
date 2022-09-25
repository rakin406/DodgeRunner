#ifndef WORLD_H
#define WORLD_H

#include "obstacle.h"
#include "player.h"

#include <raylib.h>

#include <vector>

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
     * @brief Play the world.
     */
    void play();

private:
    Camera3D camera {};                 // Initialize camera
    Player player {};                   // Initialize cube as player
    std::vector<Obstacle> obstacles {}; // Initialize obstacles
    bool gameOver {};                   // Boolean for ending game
    int score {};                       // Player score

    /**
     * @brief Initialize 3D camera.
     */
    void initializeCamera();

    /**
     * @brief Initialize obstacle cubes.
     */
    void initializeObstacles();

    /**
     * @brief Detect key and move player according to direction.
     */
    void handlePlayerMovement();

    /**
     * @brief Update and move obstacles.
     */
    void updateObstacles();

    /**
     * @brief View score on screen.
     */
    void viewScore() const;

    /**
     * @brief Draw ground/floor.
     */
    void drawGround();

    /**
     * @brief Draw obstacle cubes.
     */
    void drawObstacles();

    /**
     * @brief Draw the whole world.
     */
    void draw();
};

#endif
