#ifndef MENU_H
#define MENU_H

#include <string>

// This class contains all the functions of menu screen
class Menu
{
public:
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

    // Draw all options in menu
    void draw();

    /**
     * Get movement direction and change cursor index according to that.
     *
     * @param direction Direction of the cursor.
     */
    void moveCursor(int direction);

private:
    int cursorIndex = 0;        // Index of the option under cursor
    std::string selectedOption; // Selected menu option
};

#endif
