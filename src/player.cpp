#include "../include/player.h"
#include "raylib.h"

void Player::draw()
{
    DrawCube(Player::getPlayerPosition(), 2.0F, 2.0F, 2.0F, BLUE);
    DrawCubeWires(Player::getPlayerPosition(), 2.0F, 2.0F, 2.0F, BLACK);
}
