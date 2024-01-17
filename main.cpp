#include "Game/Game.h"
#include <chrono>
#include "Exceptions/Exceptions.h"

#ifdef __linux__
#include <X11/Xlib.h>
#endif

int main() {
#ifdef __linux__
    XInitThreads();
#endif

    Game game = Game();

    try {
        game.run();
    } catch (const GameError& e) {
        game.end();
        std::cerr << e.what() << std::endl;
    }
    return 0;
}