#ifndef REVIVE
#define REVIVE
#include "Item.hpp"


class Revive : public Item{
    private:
        string raridade;
    public:
        void pegarItem() override;
        bool usarItem(Monstrinho* monstro) override;
};




#endif