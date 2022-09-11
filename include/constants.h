#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "raylib.h"

const float CUBE_SIZE = 2.0F;

const struct
{
    int width = 1000;
    int height = 750;
} __attribute__((aligned(8))) SCREEN;

const struct
{
    int rows = (int)CUBE_SIZE * 3;
    Vector2 size = {(float)rows, (float)SCREEN.height};
} __attribute__((aligned(16))) GROUND;

#endif
