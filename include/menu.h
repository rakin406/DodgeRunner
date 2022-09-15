#ifndef MENU_H
#define MENU_H

#include <array>
#include <string>

#include "../include/world.h"

// Options for start menu. The gaps are for centering position.
const std::array<std::string, 2> OPTIONS_IN_START = {"  Play", "  Quit"};

// Options for pause menu. The gaps are for centering position.
const std::array<std::string, 3> OPTIONS_IN_PAUSE = {"Resume", "Restart",
                                                     "  Quit"};

// This class contains all the functions of menu screen
class Menu
{
public:
    bool isStartMenu;    // Whether it's start menu
    bool isPauseMenu;    // Whether it's pause menu
    bool isWorldOngoing; // Boolean for world
    int cursorIndex;     // Index of the option under cursor

    Menu();

    /**
     * Get movement direction and change cursor index according to that.
     *
     * @param direction Direction of the cursor.
     */
    void moveCursor(int direction);

    // Reset values
    void reset();

    /**
     * Draw options in menu screen.
     *
     * @param currentOption Option under cursor.
     */
    void drawOptions(const std::string &currentOption);

    /**
     * Draw menu screen.
     *
     * @param world World screen.
     */
    void draw(World &world);

private:
};

#endif
