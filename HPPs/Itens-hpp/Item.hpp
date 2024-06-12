#ifndef ITEM
#define ITEM

#include "../Jogador.hpp"
#include "../Monstrinho.hpp"
#include <string>
using std::string;

class Item{
    private:
        int id;
        string nome;
        string descricao;
    public:
        /**
         * @brief Usa um item selecionado
         * 
         * @param Monstro O monstro que o item será utilizado
         */
        virtual void usarItem(Monstrinho monstro) = 0;

        /**
         * @brief Pega um item aleatorio
         * 
         * @param jogador Jogador que o item é atribuido para
         */
        string getNome(); //<= Retorna o nome
        void setNome(string nome); // <= Muda o nome
        string getDescricao(); //<= Retorna a descrição
        void setDescricao(string descricao); //<= Muda a descrição
};

#endif