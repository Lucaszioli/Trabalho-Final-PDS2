#ifndef ESTAMINAERRO
#define ESTAMINAERRO

#include <stdexcept>
#include <string>
#include "ItemError.hpp"

class EstaminaError : public ItemError {
public:
    EstaminaError(const std::string& message)
        : ItemError(message) {}
};

#endif