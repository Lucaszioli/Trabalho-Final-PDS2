#ifndef ESTAMINA
#define ESTAMINA

#include "Item.hpp"

/** 
* @class Estamina
* 
* @brief Classe que representa o item Estamina.
*
*/

class Estamina : public Item{
    private:
        int energia; ///< A energia do item 
    public:
        /**
        * @brief Método para pegar o item
        */
        void pegarItem() override;


        int getEnergia();

        
        void setEnergia(int energia);

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