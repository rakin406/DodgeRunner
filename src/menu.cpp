#include "../include/menu.h"
#include "../include/constants.h"
#include "raylib.h"
#include <array>
#include <string>

// Options for menu screen. The gaps are for centering position.
const std::array<std::string, 2> OPTIONS_IN_MENU = {"  Play", "  Quit"};

// Options for pause screen. The gaps are for centering position.
const std::array<std::string, 3> OPTIONS_IN_PAUSE = {"Resume", "Restart",
                                                     "  Quit"};

// Directions to move cursor
const int UP = 1;
const int DOWN = -1;

/**
 * Draw options in menu screen.
 *
 * @param currentOption Option under cursor.
 */
void drawOptions(const std::string &currentOption, bool isPause);

void Menu::moveCursor(int direction)
{
    int currentIndex = this->getCursorIndex();
    int maxIndex = 0;

    // Set options indexes differently for pause and menu screen
    if (this->getIsPauseMenu())
    {
        maxIndex = OPTIONS_IN_PAUSE.size() - 1;
    }
    else
    {
        maxIndex = OPTIONS_IN_MENU.size() - 1;
    }

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
    int titleFontSize = FONT_SIZE + 30;
    std::string currentOption;

    // Set current option differently for pause and menu screen
    if (this->getIsPauseMenu())
    {
        currentOption = OPTIONS_IN_PAUSE[this->getCursorIndex()];
    }
    else
    {
        currentOption = OPTIONS_IN_MENU[this->getCursorIndex()];
    }

    // TODO: Remove these hard-coded measurements
    // Draw game title on top
    DrawText(screen::TITLE.c_str(), screen::WIDTH / 2 - 190, 100, titleFontSize,
             BLACK);

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
        this->setSelectedOption(currentOption);
    }

    drawOptions(currentOption, this->getIsPauseMenu());
}

void drawOptions(const std::string &currentOption, bool isPause)
{
    // TODO: Remove all these hard-coded measurements
    int optionX = screen::WIDTH / 2 - 70;
    int optionY = screen::HEIGHT / 2 - 105;
    int optionFontSize = FONT_SIZE + 15;
    int gap = 65;

    // TODO: MUST refactor this large dirty code
    if (isPause)
    {
        for (const auto &option : OPTIONS_IN_PAUSE)
        {
            // Highlight option on cursor
            if (option == currentOption)
            {
                DrawText(option.c_str(), optionX, optionY, optionFontSize,
                         GREEN);
            }
            else
            {
                DrawText(option.c_str(), optionX, optionY, optionFontSize,
                         BLACK);
            }
            optionY += gap;
        }
    }
    else
    {
        for (const auto &option : OPTIONS_IN_MENU)
        {
            // Highlight option on cursor
            if (option == currentOption)
            {
                DrawText(option.c_str(), optionX, optionY, optionFontSize,
                         GREEN);
            }
            else
            {
                DrawText(option.c_str(), optionX, optionY, optionFontSize,
                         BLACK);
            }
            optionY += gap;
        }
    }
}
