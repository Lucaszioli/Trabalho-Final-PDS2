#ifndef REVIVE
#define REVIVE
#include "Item.hpp"


class Revive : public Item{
    private:
        string raridade;
    public:
        string getRaridade();
        void pegarItem() override;
        bool usarItem(Monstrinho* monstro) override;
        void setRaridade(string tipo);
};




#endif