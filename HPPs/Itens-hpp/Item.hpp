#ifndef ITEM
#define ITEM

#include "../Jogador.hpp"
#include "../Monstrinho.hpp"
#include <string>
using std::string;

class Item{
    private:
        string nome;
        string descricao;
        string tipo;
        string raridade;
    public:
        /**
         * @brief Usa um item selecionado
         * 
         * @param Monstro O monstro que o item será utilizado
         */
        virtual void usarItem(Monstrinho* monstro) = 0; //mudar dependendo se for ponteiro ou não

        /**
         * @brief Pega um item aleatorio
         * 
         * @param jogador Jogador que o item é atribuido para
         */

        string getTipo();
        void setTipo(string tipo);
        virtual void pegarItem() = 0;
        string getRaridade();
        void setRaridade(string raridade);
        string getNome(); //<= Retorna o nome
        void setNome(string nome); // <= Muda o nome
        string getDescricao(); //<= Retorna a descrição
        void setDescricao(string descricao); //<= Muda a descrição
};

#endif