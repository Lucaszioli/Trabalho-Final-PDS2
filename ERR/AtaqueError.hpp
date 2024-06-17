#ifndef ATAQUEERRO
#define ATAQUEERRO
#include <stdexcept>

class AtaqueError : public std::runtime_error{
    public:
        AtaqueError(const std::string& message): std::runtime_error(message){};
};

#endif