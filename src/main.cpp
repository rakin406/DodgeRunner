#include <raylib.h>
#include <string_view>

#include "../include/world.h"

namespace
{
// Screen constants
constexpr std::string_view SCREEN_TITLE = "Dodge Runner";
constexpr int SCREEN_WIDTH = 1000;
constexpr int SCREEN_HEIGHT = 750;
} // namespace

int main()
{
    // Set window settings
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_MSAA_4X_HINT);

    // Initialize window
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE.data());

    // Initialize world
    World world;

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Start world
        world.play();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}
