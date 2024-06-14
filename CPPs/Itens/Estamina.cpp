#include "../../HPPs/Itens-hpp/Estamina.hpp"
#include "../../ERR/EstaminaError.hpp"
#include "../../ERR/EscolhaError.hpp"
#include <iostream>

void Estamina::setEnergia(int e){
    energia = e;
}

int Estamina::getEnergia(){
    return energia;
}

void Estamina::pegarItem(){
    int dado = rand() % 100 + 1;
    setTipo("Estamina");
    if(dado>90 && dado<=100){
        setRaridade("Max");
        setEnergia(100);
        setNome("Max Estamina");
        setDescricao("Recupera toda a estamina de um ataque");
    }else if(dado>55 && dado<=90){
        setRaridade("Medio");
        setEnergia(10);
        setNome("Estamina média");
        setDescricao("Recupera 10 de estamina de um ataque");
    }else if(dado<=55 && dado>0){
        setRaridade("Pequena");
        setEnergia(5);
        setNome("Estamina média");
        setDescricao("Recupera 5 de estamina de um ataque");
    }
}

void Estamina::usarItem(Monstrinho* monstro){
    bool erro = 0;
    do{
        try{
            vector<Ataque>ataques = monstro -> getAtaques();
            int i = 1;
            int escolha;
            for(auto& ataque:ataques){
                if(ataque.getQuantidade() != ataque.getMaxQuantidade()){
                    cout<<i<<"- "<<ataque.getNome()<<endl;
                    i++;
                }
            }

            if(i == 1){
                throw EstaminaError("Escolha outro monstrinho");
            }

            cin>>escolha;
            if(escolha>i){
                throw EscolhaError("Escolha maior que o numero possível de opções");
            }

            Ataque& ataqueRenovado = ataques[escolha-1];

            int quantidade = getEnergia();
            int maximo = ataqueRenovado.getMaxQuantidade();
            ataqueRenovado.setQuantidade(quantidade);

            if(ataqueRenovado.getQuantidade() > maximo){
                ataqueRenovado.setQuantidade(maximo);
            }
            erro = 0;
        }catch(EscolhaError& e){
            erro = 1;
            cout<<e.what()<<endl;
        }
    }while(erro == 1);
}