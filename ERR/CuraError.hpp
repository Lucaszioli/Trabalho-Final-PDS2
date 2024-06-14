#ifndef CURAERRO
#define CURAERRO

#include <stdexcept>
#include <string>
#include "ItemError.hpp"

class CuraError : public ItemError {
public:
    CuraError(const std::string& message)
        : ItemError(message) {}
};

#endif