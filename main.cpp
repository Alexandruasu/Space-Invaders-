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
    } catch (const MyBaseException& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}