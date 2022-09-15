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
    Camera3D camera = {{0}};         // Initialize camera
    Player player;                   // Initialize cube as player
    std::vector<Obstacle> obstacles; // Initialize obstacles
    bool isCollided = false;         // Player and obstacle collision boolean
    int score = 0;                   // Player score

    World();
    void draw();
    void play();
    void pause();
    void restart();

private:
};

#endif
