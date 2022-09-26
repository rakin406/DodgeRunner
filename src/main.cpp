#include "../include/world.h"

#include <raylib.h>

#include <string_view>

namespace
{
// Screen constants
constexpr std::string_view kScreenTitle { "Dodge Runner" };
constexpr int kScreenWidth { 1000 };
constexpr int kScreenHeight { 750 };
} // namespace

int main()
{
    // Set window settings
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_MSAA_4X_HINT);

    // Initialize window
    InitWindow(kScreenWidth, kScreenHeight, kScreenTitle.data());

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
