#ifndef CURA
#define CURA

#include "Item.hpp"

class Cura: public Item{
    private:
        int cura;
    public:
        void pegarItem() override;
        bool usarItem(Monstrinho* monstro) override;
        void setCura(int cura);
        int getCura();
};

#endif