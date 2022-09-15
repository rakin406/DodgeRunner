#include "raylib.h"
#include <string>

#include "../include/constants.h"
#include "../include/menu.h"
#include "../include/utils.h"

// Directions to move cursor
#define UP 1
#define DOWN -1

Menu::Menu()
{
    this->isStartMenu = true;
    this->isPauseMenu = false;
    this->cursorIndex = 0;
}

void Menu::moveCursor(int direction)
{
    int currentIndex = this->cursorIndex;
    int maxIndex = 0;

    // Set options indexes differently for pause and menu screen
    if (this->isPauseMenu)
    {
        maxIndex = OPTIONS_IN_PAUSE.size() - 1;
    }
    else
    {
        maxIndex = OPTIONS_IN_START.size() - 1;
    }

    // Don't go beyond limit
    if (direction == UP && currentIndex != 0)
    {
        this->cursorIndex = currentIndex - 1;
    }
    else if (direction == DOWN && currentIndex != maxIndex)
    {
        this->cursorIndex = this->cursorIndex + 1;
    }
}

void Menu::draw()
{
    int titleFontSize = FONT_SIZE + 30;
    std::string currentOption;

    // Set current option differently for pause and menu screen
    if (this->isPauseMenu)
    {
        currentOption = OPTIONS_IN_PAUSE[this->cursorIndex];
    }
    else
    {
        currentOption = OPTIONS_IN_START[this->cursorIndex];
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
        this->selectedOption = currentOption;
    }

    utils::menu::drawOptions(currentOption, this->isPauseMenu);
}
