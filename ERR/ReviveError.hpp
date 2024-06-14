#ifndef REVIVEERRO
#define REVIVEERRO

#include <stdexcept>
#include <string>
#include "ItemError.hpp"

class ReviveError : public ItemError {
public:
    ReviveError(const std::string& message)
        : ItemError(message) {}
};

#endif