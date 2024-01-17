#include <exception>
#include <string>

class GameError : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "Base exception occurred";
    }
};

class PlayerOutOfLivesException : public GameError {
public:
    [[nodiscard]] const char* what() const noexcept override;
};

class InvalidGameStateException : public GameError {
public:
    [[nodiscard]] const char* what() const noexcept override;
};