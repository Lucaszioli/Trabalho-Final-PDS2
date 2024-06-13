#ifndef REVIVE
#define REVIVE
#include "Item.hpp"


class Revive : public Item{
    private:
        string tipo;
    public:
        string getTipo();
        void pegarItem() override;
        void usarItem(Monstrinho monstro) override;
        void setTipo(string tipo);
};




#endif