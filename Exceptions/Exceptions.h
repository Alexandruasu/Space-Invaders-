#include <iostream>
#include <exception>
#include <string>

class CustomException : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override;
};

class CustomException2 : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override;
};
