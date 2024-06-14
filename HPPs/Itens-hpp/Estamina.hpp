#ifndef ESTAMINA
#define ESTAMINA

#include "Item.hpp"

class Estamina : public Item{
    private:
        int energia;
    public:
        void pegarItem() override;
        int getEnergia();
        void setEnergia(int energia);
        void usarItem(Monstrinho* monstro) override;
};

#endif