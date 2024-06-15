#include "../HPPs/Estamina.hpp"
#include "../ERR/EstaminaError.hpp"
#include "../ERR/EscolhaError.hpp"
#include "../HPPs/Ataque.hpp"
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
        setNome("Estamina pequena");
        setDescricao("Recupera 5 de estamina de um ataque");
    }
}

bool Estamina::usarItem(Monstrinho* monstro){
    bool erro = 0;
    do{
        try{
            if(monstro->getHPAtual() == 0){
                throw EstaminaError("O monstrinho já está morto, use um Revive ou escolha outro monstro");
            }
            vector<Ataque*> ataques = monstro -> getAtaques();
            int i = 1;
            int escolha;
            for(auto& ataque:ataques){
                cout<<i<<"- "<<ataque->getNome()<<"Estamina: "<<ataque->getQuantidadeAtual()<<"/"<<ataque->getQuantidade()<<endl;
                i++;
            }
            cout<<i<<"- Voltar"<<endl;
            cout<<"Escolha um ataque para recuperar Estamina"<<endl;
            cin>>escolha;
            if(escolha>i){
                throw EscolhaError("Escolha maior que o numero possível de opções");
            }
            if(escolha == i){
                return true;
            }
            Ataque* ataqueRenovado = ataques[escolha-1];
            int atual = ataqueRenovado->getQuantidadeAtual();
            int maximo = ataqueRenovado->getQuantidade();
            if(maximo == atual){
                throw EscolhaError("O Ataque ja apresenta Estamina maxima");
            }
            int quantidade = getEnergia();
            int mudanca = quantidade + atual;
            if(mudanca > maximo){
                ataqueRenovado->setQuantidadeAtual(maximo);
            }else{
                ataqueRenovado->setQuantidadeAtual(mudanca);
            }
            erro = 0;
        }catch(EscolhaError& e){
            erro = 1;
            cout<<e.what()<<endl;
        }
    }while(erro == 1);
    return false;
}