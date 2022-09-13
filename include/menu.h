#ifndef MENU_H
#define MENU_H

#include <array>
#include <string>

namespace menu
{
// All options for menu screen. The gaps are for centering position.
const std::array<std::string, 4> OPTIONS = {"  Play", "Resume", "Restart",
                                            "  Quit"};

// Draw all options in menu
void draw();
} // namespace menu

#endif
