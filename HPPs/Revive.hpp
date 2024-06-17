#ifndef REVIVE
#define REVIVE
#include "Item.hpp"

/*
* @class Revive
* 
* @brief Classe que representa o item Revive
* 
*/
class Revive : public Item{
    private:
        string raridade; ///< A raridade do item
    public:
        /**
        * @brief Método para pegar o item
        */
        void pegarItem() override;

        /**
         * @brief Usa um item selecionado
         * 
         * @param Monstro O monstrinho em que o item será utilizado
         * @return true se o item foi usado com sucesso, false se não foi
         * 
         */
        bool usarItem(Monstrinho* monstro) override;
};




#endif