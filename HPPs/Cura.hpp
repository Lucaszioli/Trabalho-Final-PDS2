#ifndef CURA
#define CURA

#include "Item.hpp"

/*
* @class Cura
* 
* @brief Classe que representa o item Cura.
*
*/
class Cura: public Item{
    private:
        int cura; ///< A cura do item
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

        /**
        * @brief Define a quantidade de cura do item.
        * @param cura A quantidade de cura.
        */
        void setCura(int cura);

        /**
        * @brief Obtém a quantidade de cura do item.
        * @return A quantidade de cura.
        */
        int getCura();
};

#endif