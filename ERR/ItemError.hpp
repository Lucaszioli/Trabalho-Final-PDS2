#ifndef ITEMERRO
#define ITEMERRO

#include <stdexcept>
#include <string>

class ItemError : public std::exception{
public:
    explicit ItemError(const std::string& message)
        : msg_(message) {}
    const char* what() const noexcept override {
    return msg_.c_str();
}
    private:
        std::string msg_;
};

#endif