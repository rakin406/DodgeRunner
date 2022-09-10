#include "../include/player.h"
#include "raylib.h"

void Player::draw()
{
    DrawCube(this->getPlayerPosition(), 2.0F, 2.0F, 2.0F, BLUE);
    DrawCubeWires(this->getPlayerPosition(), 2.0F, 2.0F, 2.0F, BLACK);
}
