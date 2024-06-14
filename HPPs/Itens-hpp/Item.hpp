#ifndef ITEM
#define ITEM

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
        virtual bool usarItem(Monstrinho* monstro) = 0; //mudar dependendo se for ponteiro ou não

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