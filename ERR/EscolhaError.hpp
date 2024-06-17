#ifndef ESCOLHAERRO
#define ESCOLHAERRO
#include <stdexcept>

class EscolhaError : public std::invalid_argument{
    public:
        EscolhaError(const std::string& message): std::invalid_argument(message){};
};



#endif