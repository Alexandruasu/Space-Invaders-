#include "Exceptions.h"

const char* CustomException::what() const noexcept {
    return "Custom exception";
}

const char* CustomException2::what() const noexcept {
    return "Custom exception 2";
}