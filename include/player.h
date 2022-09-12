#ifndef PLAYER_H
#define PLAYER_H

#include "./constants.h"
#include "raylib.h"

const int LEFT_ROW = 1;
const int MIDDLE_ROW = 2;
const int RIGHT_ROW = 3;

// All possible directions for player cube
enum class Direction
{
    Left,
    Right
};

// This class contains all the functions of the player cube
class Player
{
public:
    /**
     * Set player position.
     *
     * @param newPosition New position of player cube.
     */
    void setPosition(Vector3 newPosition) { position = newPosition; }

    /**
     * Get player cube position.
     *
     * @return player cube position.
     */
    [[nodiscard]] Vector3 getPosition() const { return position; }

    /**
     * Set current row of player cube.
     *
     * @param row New row of player cube.
     */
    void setCurrentRow(int row) { currentRow = row; }

    /**
     * Get current row of player cube.
     *
     * @return current row.
     */
    [[nodiscard]] int getCurrentRow() const { return currentRow; }

    /**
     * Move player cube to specified direction.
     *
     * @param direction Desired direction for player cube.
     */
    void move(Direction direction);

    // Draw player cube on screen
    void draw() const;

private:
    Vector3 position = {0.0F, 0.0F, 0.0F}; // Player cube position
    int currentRow = MIDDLE_ROW;           // Current ground row of player cube
};

#endif
