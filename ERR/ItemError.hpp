#ifndef ITEMERRO
#define ITEMERRO

#include <stdexcept>
#include <string>

class ItemError : public std::runtime_error {
public:
    ItemError(const std::string& message)
        : std::runtime_error(message) {}
};

#endif