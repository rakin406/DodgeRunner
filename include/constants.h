#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "raylib.h"
#include <array>

constexpr float CUBE_SIZE = 2.0F;
constexpr int FONT_SIZE = 30;

constexpr int DEFAULT_OBSTACLES = 10;

// After the specified score, increase the obstacle speed.
constexpr int SCORE_INCREMENT = 5000;

// Used for incrementing to the original speed
constexpr float SPEED_INCREMENT = 0.5F;

namespace screen
{
constexpr int WIDTH = 1000;
constexpr int HEIGHT = 750;
constexpr char TITLE[] = "Dodge Runner";
} // namespace screen

namespace camera
{
constexpr Vector3 POSITION = {0.0F, 5.0F, 10.0F};
constexpr float FOV = 45.0F;
} // namespace camera

namespace ground
{
constexpr float GAP = CUBE_SIZE / 2;
constexpr float WIDTH = (CUBE_SIZE * 3.5F) + GAP;
constexpr Vector2 SIZE = {WIDTH, static_cast<float>(screen::HEIGHT)};
} // namespace ground

// The middle row position is 0.0F
constexpr std::array<float, 3> ROW_POSITIONS = {
    -CUBE_SIZE - ground::GAP / 2, 0.0F, CUBE_SIZE + ground::GAP / 2};

#endif
