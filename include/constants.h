#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "raylib.h"

const float CUBE_SIZE = 2.0F;

namespace SCREEN
{
const int width = 1000;
const int height = 750;
} // namespace SCREEN

namespace GROUND
{
const int rows = (int)CUBE_SIZE * 3;
const Vector2 size = {(float)rows, (float)SCREEN::height};
} // namespace GROUND

#endif
