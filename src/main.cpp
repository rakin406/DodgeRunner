#include "../include/world.h"

#include <raylib.h>
#include <string_view>

namespace
{
// Screen constants
constexpr std::string_view SCREEN_TITLE{ "Dodge Runner" };
constexpr int SCREEN_WIDTH{ 1000 };
constexpr int SCREEN_HEIGHT{ 750 };
} // namespace

int main()
{
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_MSAA_4X_HINT);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE.data());

    World world;

    SetTargetFPS(60);

    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        world.play();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}
