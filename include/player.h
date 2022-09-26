#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>

namespace direction
{

/**
 * @brief All possible directions for player cube.
 */
enum class Direction
{
    left,
    right
};

} // namespace direction

/**
 * @brief This class contains all the functions of the player cube.
 */
class Player
{
public:
    /**
     * @brief Default constructor for Player initialization.
     */
    Player();

    /**
     * @brief Get player position.
     *
     * @return Vector3.
     */
    [[nodiscard]] Vector3 getPosition() const;

    /**
     * @brief Move player cube to specified direction.
     *
     * @param direction Desired direction for player cube.
     */
    void move(direction::Direction direction);

    /**
     * @brief Draw player cube on screen.
     */
    void draw() const;

private:
    Vector3 m_position {}; // Player cube position
    int m_currentRow {};   // Current ground row of player cube
};

#endif
