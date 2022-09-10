#include "../include/player.h"
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
    DrawCube(this->getPlayerPosition(), 2.0F, 2.0F, 2.0F, BLUE);
    DrawCubeWires(this->getPlayerPosition(), 2.0F, 2.0F, 2.0F, BLACK);
}
