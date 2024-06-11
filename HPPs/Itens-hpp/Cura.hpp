#ifndef CURA
#define CURA

#include "Item.hpp"

class Cura: public Item{
    private:
        int cura;
    public:
        void usarItem() override;
};

#endif