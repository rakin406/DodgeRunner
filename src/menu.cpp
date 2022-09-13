#include "../include/menu.h"
#include "../include/constants.h"
#include "raylib.h"

void menu::draw()
{
    // TODO: Remove all these hard-coded measurements
    int optionX = screen::WIDTH / 2 - 70;
    int optionY = screen::HEIGHT / 2 - 105;
    int menuFontSize = FONT_SIZE + 15;
    int gap = 65;

    // Draw all options
    for (const auto &option : menu::OPTIONS)
    {
        DrawText(option.c_str(), optionX, optionY, menuFontSize, BLACK);
        optionY += gap;
    }
}
