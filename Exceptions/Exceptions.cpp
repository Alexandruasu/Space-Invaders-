#include "Exceptions.h"

const char* PlayerOutOfLivesException::what() const noexcept {
    return "Player ran out of lives";
}

const char* InvalidGameStateException::what() const noexcept {
    return "Invalid game state";
}