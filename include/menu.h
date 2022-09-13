#ifndef MENU_H
#define MENU_H

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

    // Draw all options in menu
    void draw();

private:
    int cursorIndex = 0; // Index of the option under cursor
};

#endif
