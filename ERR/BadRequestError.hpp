#ifndef BADREQUESTERRO
#define BADREQUESTERRO

#include <stdexcept>

class BadRequestError : public std::runtime_error{
    public:
        BadRequestError(const std::string& message): std::runtime_error(message){};
};


#endif