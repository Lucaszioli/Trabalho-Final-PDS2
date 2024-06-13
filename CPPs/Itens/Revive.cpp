#include "../../HPPs/Itens-hpp/Revive.hpp"
#include "../../ERR/ReviveError.hpp"
#include <iostream>
using std::cout;
string Revive::getTipo(){
    return tipo;
}

void Revive::setTipo(string tipo){
    this->tipo = tipo;
}


void Revive::pegarItem(){
    int dado = (rand() % 100) + 1;
    if(dado>90 && dado<=100){
        setNome("Max Revive");
        setDescricao("Revive seu mostrinho com a vida máxima");
        setTipo("Max");
    }else if(dado<=90 && dado>0){
        setNome("Revive");
        setDescricao("Revive seu monstrinho com 50% da vida dele");
        setTipo("Normal");
    }
}

void Revive::usarItem(Monstrinho monstro){

    if(monstro.getHP() > 0){
        throw ReviveError("Selecione outro monstro");
    }
    int vidaTotal = monstro.getMaxHP();
    string tipo = getTipo();
    if(tipo == "Normal"){
        monstro.setHP(vidaTotal/2);
    }else if(tipo == "Max"){
        monstro.setHP(vidaTotal);
    }
}