#include "../include/player.h"
#include "raylib.h"

void Player::draw()
{
    DrawCube(Player::getPlayerPosition(), 2.0F, 2.0F, 2.0F, RED);
    DrawCubeWires(Player::getPlayerPosition(), 2.0F, 2.0F, 2.0F, MAROON);
}
