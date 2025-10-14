#include <exception>
#include <iostream>
#include <string>

enum class ErrorCause
{
    Invalide = 0,
    Autre = 1
};

class StateException : public std::exception
{
private:
    ErrorCause cause_;
    std::string msg_;

public:
    explicit StateException(ErrorCause cause, std::string msg = {})
        : cause_(cause), msg_(std::move(msg)) {}

    const char *what() const noexcept override
    {
        return msg_.empty() ? "Erreur applicative" : msg_.c_str();
    }

    ErrorCause cause() const noexcept { return cause_; }
};
