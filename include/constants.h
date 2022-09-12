#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "raylib.h"
#include <array>

const float CUBE_SIZE = 2.0F;

// The middle row position is 0.0F
const std::array<float, 3> ROW_POSITIONS = {-CUBE_SIZE, 0.0F, CUBE_SIZE};

namespace SCREEN
{
const int width = 1000;
const int height = 750;
} // namespace SCREEN

namespace GROUND
{
const float width = CUBE_SIZE * 3.5F;
const Vector2 size = {width, (float)SCREEN::height};
} // namespace GROUND

#endif
