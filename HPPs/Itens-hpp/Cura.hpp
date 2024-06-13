#ifndef CURA
#define CURA

#include "Item.hpp"
#include "../Monstrinho.hpp"

class Cura: public Item{
    private:
        int cura;
    public:
        void pegarItem() override;
        void usarItem(Monstrinho monstro) override;
        void setCura(int cura);
        int getCura();
};

#endif