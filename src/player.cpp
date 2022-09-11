#include "../include/player.h"
#include "../include/constants.h"
#include "raylib.h"

Player::Player()
{
    Vector3 startingPosition = {0.0F, 0.0F, 0.0F};
    this->setPosition(startingPosition);
}

void Player::moveForward()
{
    Vector3 newPosition = this->getPosition();
    newPosition.z -= 0.1;
    this->setPosition(newPosition);
}

void Player::draw()
{
    DrawCube(this->getPosition(), CUBE_SIZE, CUBE_SIZE, CUBE_SIZE, BLUE);
    DrawCubeWires(this->getPosition(), CUBE_SIZE, CUBE_SIZE, CUBE_SIZE, BLACK);
}
