#ifndef MENU_H
#define MENU_H

#include <string>

#include "world.h"

// This class contains all the methods of menu screen
class Menu
{
public:
    /**
     * Default constructor for Menu initialization.
     *
     * @param world World object pointer.
     */
    explicit Menu(World *world);

    // Draw menu screen
    void draw();

private:
    World *world;                // Pointer to the main world
    bool isStartMenu = true;     // Whether it's start menu
    bool isPauseMenu = false;    // Whether it's pause menu
    bool isWorldOngoing = false; // Boolean for world
    int cursorIndex = 0;         // Index of the option under cursor

    /**
     * Get cursor movement direction and change cursor index according to that.
     *
     * @param direction Direction of the cursor.
     */
    void moveCursor(int direction);

    /**
     * Draw options in menu screen.
     *
     * @param currentOption Option under cursor.
     */
    void drawOptions(const std::string &currentOption);

    // Toggle pause screen
    void togglePause();

    /**
     * Select option under cursor and do it's action.
     *
     * @param option Option under cursor.
     */
    void selectOption(const std::string &option);

    // Reset member variables
    void reset();
};

#endif
