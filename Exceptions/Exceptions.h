#include <exception>
#include <string>

class MyBaseException : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "Base exception occurred";
    }
};

class PlayerOutOfLivesException : public MyBaseException {
public:
    [[nodiscard]] const char* what() const noexcept override;
};

class InvalidGameStateException : public MyBaseException {
public:
    [[nodiscard]] const char* what() const noexcept override;
};