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
    int optionFontSize = FONT_SIZE + 15;
    int titleFontSize = optionFontSize + 15;
    int gap = 65;

    // TODO: Replace complex abstractions
    // Draw game title on top
    DrawText(screen::TITLE.c_str(), optionX - 120, 100, titleFontSize, BLACK);

    // Draw all options
    for (const auto &option : OPTIONS)
    {
        // Highlight option on cursor
        if (option == OPTIONS[this->getCursorIndex()])
        {
            DrawText(option.c_str(), optionX, optionY, optionFontSize, GREEN);
        }
        else
        {
            DrawText(option.c_str(), optionX, optionY, optionFontSize, BLACK);
        }
        optionY += gap;
    }
}
