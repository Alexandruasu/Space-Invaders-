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

    try {
        throw CustomException();
    } catch (const CustomException& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        throw CustomException2();
    } catch (const CustomException2& e) {
        std::cout << e.what() << std::endl;
    }

    Game game = Game();
    game.run();

    return 0;
}