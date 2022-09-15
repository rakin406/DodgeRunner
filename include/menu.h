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
    /**
     * Set whether it's start menu.
     *
     * @param start Boolean for pause menu.
     */
    void setIsStartMenu(bool start) { isStartMenu = start; }

    /**
     * Get whether it's start menu.
     *
     * @return isStartMenu.
     */
    [[nodiscard]] bool getIsStartMenu() const { return isStartMenu; }

    /**
     * Set whether it's pause menu.
     *
     * @param pause Boolean for pause menu.
     */
    void setIsPauseMenu(bool pause) { isPauseMenu = pause; }

    /**
     * Get whether it's pause menu.
     *
     * @return isPauseMenu.
     */
    [[nodiscard]] bool getIsPauseMenu() const { return isPauseMenu; }

    /**
     * Set index of option under cursor.
     *
     * @param index New index of cursor option.
     */
    void setCursorIndex(int index) { cursorIndex = index; }

    /**
     * Get index of option under cursor.
     *
     * @return cursor index.
     */
    [[nodiscard]] int getCursorIndex() const { return cursorIndex; }

    /**
     * Set selected option.
     *
     * @param option New option.
     */
    void setSelectedOption(const std::string &option)
    {
        selectedOption = option;
    }

    /**
     * Get selected option.
     *
     * @return selected option.
     */
    [[nodiscard]] std::string getSelectedOption() const
    {
        return selectedOption;
    }

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
    bool isStartMenu = true;    // Whether it's start menu.
    bool isPauseMenu = false;   // Whether it's pause menu.
    int cursorIndex = 0;        // Index of the option under cursor
    std::string selectedOption; // Selected menu option
};

#endif
