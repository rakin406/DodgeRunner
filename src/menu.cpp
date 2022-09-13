#include "../include/menu.h"
#include "../include/constants.h"
#include "raylib.h"
#include <array>
#include <string>

// All options for menu screen. The gaps are for centering position.
const std::array<std::string, 4> OPTIONS = {"  Play", "Resume", "Restart",
                                            "  Quit"};

void Menu::draw()
{
    // TODO: Remove all these hard-coded measurements
    int optionX = screen::WIDTH / 2 - 70;
    int optionY = screen::HEIGHT / 2 - 105;
    int menuFontSize = FONT_SIZE + 15;
    int gap = 65;

    int cursorIndex = 0;

    // Draw all options
    for (const auto &option : OPTIONS)
    {
        // Highlight option on cursor
        if (option == OPTIONS[cursorIndex])
        {
            DrawText(option.c_str(), optionX, optionY, menuFontSize, GREEN);
        }
        else
        {
            DrawText(option.c_str(), optionX, optionY, menuFontSize, BLACK);
        }
        optionY += gap;
    }
}
