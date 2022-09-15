#ifndef MENU_H
#define MENU_H

#include <array>
#include <string>

// Options for start menu. The gaps are for centering position.
const std::array<std::string, 2> OPTIONS_IN_START = {"  Play", "  Quit"};

// Options for pause menu. The gaps are for centering position.
const std::array<std::string, 3> OPTIONS_IN_PAUSE = {"Resume", "Restart",
                                                     "  Quit"};

// This class contains all the functions of menu screen
class Menu
{
public:
    bool isStartMenu;           // Whether it's start menu.
    bool isPauseMenu;           // Whether it's pause menu.
    int cursorIndex;            // Index of the option under cursor
    std::string selectedOption; // Selected menu option

    Menu();

    /**
     * Draw menu screen.
     */
    void draw();

    /**
     * Get movement direction and change cursor index according to that.
     *
     * @param direction Direction of the cursor.
     */
    void moveCursor(int direction);

private:
};

#endif
