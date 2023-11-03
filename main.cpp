#include "Game/Game.h"
#include <chrono>

#ifdef __linux__
#include <X11/Xlib.h>
#endif

int main() {
#ifdef __linux__
    XInitThreads();
#endif

    Game game = Game();
    game.run();

    return 0;
}