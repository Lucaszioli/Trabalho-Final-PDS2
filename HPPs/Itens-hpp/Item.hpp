#ifndef ITEM
#define ITEM

#include <string>
using std::string;

class Item{
    private:
        int id;
        string nome;
        string descrição;
        int quantidade;
    public:
        virtual void usarItem() = 0;
        virtual void pegarItem() = 0;
        string getNome();
        string getDescrição();
};

#endif