#include "raylib.h"
#include <string>
#include <vector>

#include "../include/constants.h"
#include "../include/menu.h"
#include "../include/utils.h"

// Directions to move cursor
constexpr int UP = 1;
constexpr int DOWN = -1;

void Menu::moveCursor(int direction)
{
    int currentIndex = this->cursorIndex;
    int maxIndex = 0;

    // Set options indexes differently for pause and menu screen
    if (this->isPauseMenu)
    {
        maxIndex = this->OPTIONS_IN_PAUSE.size() - 1;
    }
    else if (this->isStartMenu)
    {
        maxIndex = this->OPTIONS_IN_START.size() - 1;
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

void Menu::drawOptions(const std::string &currentOption)
{
    // TODO: Remove all these hard-coded measurements
    int optionX = GetScreenWidth() / 2 - 70;
    int optionY = GetScreenHeight() / 2 - 50;
    int optionFontSize = FONT_SIZE + 15;
    int gap = 75;
    std::vector<std::string> options;

    // Set options differently for menu and pause screen
    if (this->isStartMenu)
    {
        options = {this->OPTIONS_IN_START.begin(),
                   this->OPTIONS_IN_START.end()};
    }
    else if (this->isPauseMenu)
    {
        options = {this->OPTIONS_IN_PAUSE.begin(),
                   this->OPTIONS_IN_PAUSE.end()};
    }

    BeginDrawing();
    ClearBackground(RAYWHITE);

    // Draw options
    for (const auto &opt : options)
    {
        // Highlight option on cursor
        if (opt == currentOption)
        {
            DrawText(opt.c_str(), optionX, optionY, optionFontSize, GREEN);
        }
        else
        {
            DrawText(opt.c_str(), optionX, optionY, optionFontSize, BLACK);
        }
        optionY += gap;
    }

    EndDrawing();
}

void Menu::draw(World &world)
{
    int titleFontSize = FONT_SIZE + 30;
    std::string currentOption;

    // World doesn't start automatically, so start menu is opened by default.
    this->isStartMenu = !world.isStarted();

    // Set current option differently for pause and menu screen
    if (this->isPauseMenu)
    {
        currentOption = this->OPTIONS_IN_PAUSE[this->cursorIndex];
    }
    else if (this->isStartMenu)
    {
        currentOption = this->OPTIONS_IN_START[this->cursorIndex];
    }

    // Toggle pause on Escape key
    if (!this->isStartMenu && IsKeyPressed(KEY_ESCAPE))
    {
        this->isPauseMenu = !this->isPauseMenu;
        this->isWorldOngoing = !this->isWorldOngoing;
        this->cursorIndex = 0;

        // Pause game when in menu screen
        if (this->isPauseMenu)
        {
            world.pause();
        }
        else
        {
            world.resume();
        }
    }

    // TODO: Remove these hard-coded measurements. Refactor this whole branch.
    // Draw game title on top.
    // Don't draw if world is on.
    if (!this->isWorldOngoing)
    {
        DrawText(screen::TITLE, GetScreenWidth() / 2 - 190, 100, titleFontSize,
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
            // Start game from menu screen
            if (currentOption == this->OPTIONS_IN_START[0])
            {
                world.start();
            }
            // Resume game from pause screen
            else if (currentOption == this->OPTIONS_IN_PAUSE[0])
            {
                world.resume();
            }
            // Restart game from pause screen
            else if (currentOption == this->OPTIONS_IN_PAUSE[1])
            {
                world.reset();
            }
            // This is the quit option. It's both in start menu and pause menu
            // and functions the same way.
            else if (currentOption == this->OPTIONS_IN_START[1])
            {
                CloseWindow();
            }

            this->reset();
        }

        // Draw menu
        this->drawOptions(currentOption);
    }
}

void Menu::reset()
{
    this->isStartMenu = false;
    this->isPauseMenu = false;
    this->isWorldOngoing = true;
    this->cursorIndex = 0;
}
