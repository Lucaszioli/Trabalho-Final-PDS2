#ifndef ESCOLHAERRO
#define ESCOLHAERRO
#include <stdexcept>

class EscolhaError : public std::runtime_error{
    public:
        EscolhaError(const std::string& message): std::runtime_error(message){};
};



#endif