#include "../include/menu.h"
#include "../include/constants.h"
#include "raylib.h"
#include <array>

// All options for menu screen. The gaps are for centering position.
const std::array<std::string, 4> OPTIONS = {"  Play", "Resume", "Restart",
                                            "  Quit"};

// Directions to move cursor
const int UP = 1;
const int DOWN = -1;

void Menu::moveCursor(int direction)
{
    int currentIndex = this->getCursorIndex();
    int maxIndex = OPTIONS.size() - 1;

    // Don't go beyond limit
    if (direction == UP && currentIndex != 0)
    {
        this->setCursorIndex(currentIndex - 1);
    }
    else if (direction == DOWN && currentIndex != maxIndex)
    {
        this->setCursorIndex(this->getCursorIndex() + 1);
    }
}

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

    // Cursor movement
    if (IsKeyPressed(KEY_UP))
    {
        moveCursor(UP);
    }
    else if (IsKeyPressed(KEY_DOWN))
    {
        moveCursor(DOWN);
    }

    // Set selected option on Enter
    if (IsKeyPressed(KEY_ENTER))
    {
        this->setSelectedOption(OPTIONS[this->getCursorIndex()]);
    }

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
