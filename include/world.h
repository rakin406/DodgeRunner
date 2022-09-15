#ifndef WORLD_H
#define WORLD_H

#include "raylib.h"
#include <vector>

#include "obstacle.h"
#include "player.h"

// This class contains the main functions of the game
class World
{
public:
    Camera3D camera;                 // Initialize camera
    Player player;                   // Initialize cube as player
    std::vector<Obstacle> obstacles; // Initialize obstacles
    bool isCollided;                 // Player and obstacle collision boolean
    bool isStarted;                  // Boolean for checking start
    bool isPaused;                   // Boolean for checking pause
    int score;                       // Player score

    World();
    void draw();
    void play();
    void start();
    void pause();
    void resume();
    void reset();

private:
};

#endif
