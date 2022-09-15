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
    this->isWorldOngoing = false;
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
    else if (this->isStartMenu)
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

void Menu::reset()
{
    this->isStartMenu = false;
    this->isPauseMenu = false;
    this->isWorldOngoing = true;
    this->cursorIndex = 0;
}

void Menu::drawOptions(const std::string &currentOption)
{
    // TODO: Remove all these hard-coded measurements
    int optionX = screen::WIDTH / 2 - 70;
    int optionY = screen::HEIGHT / 2 - 50;
    int optionFontSize = FONT_SIZE + 15;
    int gap = 75;

    // Don't draw if world is on
    if (!this->isWorldOngoing)
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // TODO: MUST refactor this large dirty code
        if (this->isPauseMenu)
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
        else if (this->isStartMenu)
        {
            for (const auto &option : OPTIONS_IN_START)
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

        EndDrawing();
    }
}

void Menu::draw(World &world)
{
    int titleFontSize = FONT_SIZE + 30;
    std::string currentOption;

    // World doesn't start automatically, so start menu is opened by default.
    this->isStartMenu = !world.isStarted;

    // Set current option differently for pause and menu screen
    if (this->isPauseMenu)
    {
        currentOption = OPTIONS_IN_PAUSE[this->cursorIndex];
    }
    else if (this->isStartMenu)
    {
        currentOption = OPTIONS_IN_START[this->cursorIndex];
    }

    // TODO: Remove these hard-coded measurements
    // Draw game title on top.
    // Don't draw if world is on.
    if (!this->isWorldOngoing)
    {
        DrawText(screen::TITLE.c_str(), screen::WIDTH / 2 - 190, 100,
                 titleFontSize, BLACK);
    }

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
        // Start game from menu screen
        if (currentOption == OPTIONS_IN_START[0])
        {
            world.start();
        }
        // Resume game from pause screen
        else if (currentOption == OPTIONS_IN_PAUSE[0])
        {
            world.resume();
        }
        // Restart game from pause screen
        else if (currentOption == OPTIONS_IN_PAUSE[1])
        {
            world.reset();
        }
        // This is the quit option. It's both in start menu and pause menu and
        // functions the same way.
        else if (currentOption == OPTIONS_IN_START[1])
        {
            CloseWindow();
        }

        this->reset();
    }

    // Draw menu
    this->drawOptions(currentOption);
}
