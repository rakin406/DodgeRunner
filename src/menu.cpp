#include "raylib.h"
#include <array>
#include <string>
#include <vector>

#include "../include/constants.h"
#include "../include/menu.h"
#include "../include/utils.h"

// Directions to move cursor
constexpr int UP = 1;
constexpr int DOWN = -1;

// TODO: Find a cleaner way to center position.
// Options for start menu. The spaces between are for centering position
// on screen.
const std::array<std::string, 2> START_OPTIONS = {"  Play", "  Quit"};

// Options for pause menu.
const std::array<std::string, 3> PAUSE_OPTIONS = {"Resume", "Restart",
                                                  "  Quit"};

Menu::Menu(World *world) : world(world) {}

void Menu::moveCursor(int direction)
{
    int currentIndex = this->cursorIndex;
    int maxIndex = 0;

    // Set option indexes differently for pause and menu screen
    if (this->isPauseMenu)
    {
        maxIndex = static_cast<int>(PAUSE_OPTIONS.size() - 1);
    }
    else if (this->isStartMenu)
    {
        maxIndex = static_cast<int>(START_OPTIONS.size() - 1);
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
        options = {START_OPTIONS.begin(), START_OPTIONS.end()};
    }
    else if (this->isPauseMenu)
    {
        options = {PAUSE_OPTIONS.begin(), PAUSE_OPTIONS.end()};
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
        optionY += gap; // Give y-axis gap between options
    }

    EndDrawing();
}

void Menu::draw()
{
    int titleFontSize = FONT_SIZE + 30;
    std::string currentOption;

    // World doesn't start automatically, so start menu is opened by default.
    this->isStartMenu = !this->world->isStarted();

    // Set current option differently for pause and menu screen
    if (this->isPauseMenu)
    {
        currentOption = PAUSE_OPTIONS[this->cursorIndex];
    }
    else if (this->isStartMenu)
    {
        currentOption = PAUSE_OPTIONS[this->cursorIndex];
    }

    // Toggle pause on Escape key
    if (!this->isStartMenu && IsKeyPressed(KEY_ESCAPE))
    {
        this->togglePause();
    }

    // TODO: Remove these hard-coded measurements. Refactor this whole branch.
    // Draw game title on top.
    // Don't draw if world is on.
    if (!this->isWorldOngoing)
    {
        // Draw game title
        DrawText(SCREEN_TITLE, GetScreenWidth() / 2 - 190, 100, titleFontSize,
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
            // Perform task on option
            this->selectOption(currentOption);
        }

        // Draw menu
        this->drawOptions(currentOption);
    }
}

void Menu::togglePause()
{
    this->isPauseMenu = !this->isPauseMenu;
    this->isWorldOngoing = !this->isWorldOngoing;
    this->cursorIndex = 0;

    // Pause game when in menu screen
    if (this->isPauseMenu)
    {
        this->world->pause();
    }
    // Otherwise continue playing
    else
    {
        this->world->resume();
    }
}

void Menu::selectOption(const std::string &option)
{
    // Start game from menu screen
    if (option == START_OPTIONS[0])
    {
        this->world->start();
    }
    // Resume game from pause screen
    else if (option == PAUSE_OPTIONS[0])
    {
        this->world->resume();
    }
    // Restart game from pause screen
    else if (option == PAUSE_OPTIONS[1])
    {
        this->world->reset();
    }
    // This is the quit option. It's both in start menu and pause menu and
    // functions the same way.
    else if (option == START_OPTIONS[1])
    {
        CloseWindow();
    }

    // Reset member variables
    this->reset();
}

void Menu::reset()
{
    this->isStartMenu = false;
    this->isPauseMenu = false;
    this->isWorldOngoing = true;
    this->cursorIndex = 0;
}
