#ifndef ITEM
#define ITEM

#include "Monstrinho.hpp"
#include <string>
using std::string;

/**
 * @file Item.hpp
 * @brief Classe que representa um item.
 */

/** 
* @class Item
* 
* @brief Classe que representa um item.
* 
* A classe Item representa um item com suas caraterísticas, como nome, descrição, tipo e raridade
* Ela também possui métodos para acessar e modificar essas características.
*/
class Item{
    private:
        string nome; ///< O nome do item
        string descricao; ///< A descrição do item
        string tipo; ///< O tipo do item
        string raridade; ///< A raridade do item
    public:
        /**
         * @brief Usa um item selecionado
         * 
         * @param Monstro O monstrinho em que o item será utilizado
         * @return true se o item foi usado com sucesso, false se não foi
         * 
         */
        virtual bool usarItem(Monstrinho* monstro) = 0; //mudar dependendo se for ponteiro ou não

        /**
        * @brief Obtém o tipo do item
        * @return string O tipo do item
        */
        string getTipo();

        /**
        * @brief Define o tipo do item
        * @param tipo O tipo do item
        */
        void setTipo(string tipo);

        /**
        * @brief Método para pegar o item
        */
        virtual void pegarItem() = 0;

        /**
        * @brief Obtém a raridade do item
        * @return string A raridade do item
        */
        string getRaridade();

        /**
        * @brief Define a raridade do item
        * @param raridade A raridade do item
        */
        void setRaridade(string raridade);

        /**
        * @brief Obtém o nome do item
        * @return string O nome do item
        */
        string getNome();

        /**
        * @brief Define o nome do item
        * @param nome O nome do item
        */
        void setNome(string nome); // <= Muda o nome

        /**
        * @brief Obtém a descrição
        * @return string A descrição
        */
        string getDescricao(); 

        /**
        * @brief Define a descrição do item
        * @param descricao A descrição do item
        */
        void setDescricao(string descricao); //<= Muda a descrição


};

#endif