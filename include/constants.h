#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "raylib.h"
#include <array>
#include <string>

const float CUBE_SIZE = 2.0F;
const int FONT_SIZE = 30;

const int DEFAULT_OBSTACLES = 10;

// After the specified score, increase the obstacle speed.
const int SCORE_INCREMENT = 5000;

// Used for incrementing to the original speed
const float SPEED_INCREMENT = 0.5F;

namespace screen
{
const int WIDTH = 1000;
const int HEIGHT = 750;
const std::string TITLE = "Dodge Runner";
} // namespace screen

namespace camera
{
const Vector3 POSITION = {0.0F, 5.0F, 10.0F};
const float FOV = 45.0F;
} // namespace camera

namespace ground
{
const float GAP = CUBE_SIZE / 2;
const float WIDTH = (CUBE_SIZE * 3.5F) + GAP;
const Vector2 SIZE = {WIDTH, (float)screen::HEIGHT};
} // namespace ground

// The middle row position is 0.0F
const std::array<float, 3> ROW_POSITIONS = {-CUBE_SIZE - ground::GAP / 2, 0.0F,
                                            CUBE_SIZE + ground::GAP / 2};

#endif
