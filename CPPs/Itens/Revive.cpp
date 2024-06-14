#include "../../HPPs/Itens-hpp/Revive.hpp"
#include "../../ERR/ReviveError.hpp"
#include <iostream>
using std::cout;
string Revive::getRaridade(){
    return raridade;
}

void Revive::setRaridade(string raridade){
    this->raridade = raridade;
}


void Revive::pegarItem(){
    int dado = (rand() % 100) + 1;
    setTipo("Revive");
    if(dado>90 && dado<=100){
        setNome("Max Revive");
        setDescricao("Revive seu mostrinho com a vida máxima");
        setRaridade("Max");
    }else if(dado<=90 && dado>0){
        setNome("Revive");
        setDescricao("Revive seu monstrinho com 50% da vida dele");
        setRaridade("Normal");
    }
}

bool Revive::usarItem(Monstrinho* monstro){
    if(monstro->getHPAtual() > 0){
        throw ReviveError("Selecione outro monstro");
    }
    int vidaTotal = monstro->getHP();
    string raridade = getRaridade();
    if(raridade == "Normal"){
        monstro->setHPAtual(vidaTotal/2);
    }else if(raridade == "Max"){
        monstro->setHPAtual(vidaTotal);
    }
    return false;
}