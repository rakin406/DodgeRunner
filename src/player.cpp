#include "../include/player.h"
#include "../include/constants.h"
#include "raylib.h"

Player::Player()
{
    Vector3 startingPosition = {0.0F, 0.0F, 0.0F};
    this->setPlayerPosition(startingPosition);
}

void Player::moveForward()
{
    Vector3 newPosition = this->getPlayerPosition();
    newPosition.z -= 0.1;
    this->setPlayerPosition(newPosition);
}

void Player::draw()
{
    DrawCube(this->getPlayerPosition(), CUBE_SIZE, CUBE_SIZE, CUBE_SIZE, BLUE);
    DrawCubeWires(this->getPlayerPosition(), CUBE_SIZE, CUBE_SIZE, CUBE_SIZE,
                  BLACK);
}
