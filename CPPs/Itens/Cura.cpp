#include "../../HPPs/Itens-hpp/Cura.hpp"
#include <cstdlib>
#include <stdexcept>

void Cura::usarItem(Monstrinho m){
    int vidaTotal = m.getHP();
    int vidaAtual = m.getHP(); // mudar quando tiver 2 vidas
    int vidaFinal = (vidaTotal * cura/100)+vidaAtual;
    if(vidaFinal > vidaTotal){
        vidaFinal = vidaTotal;
    } 
    m.setHP(vidaFinal);
}

void Cura::pegarCura(){
    int dado = (rand() % 100) + 1;
    if(dado>95 && dado<=100){
        setNome("Poção Máxima");
        setDescricao("Cura toda a vida do seu monstrinho");
        setCura(100);
    }else if(dado<=95 && dado>85){
        setNome("Poção Grande");
        setDescricao("Cura até 75% da vida do seu monstrinho");
        setCura(75);
    }else if(dado<=85 && dado>55){
        setNome("Poção Média");
        setDescricao("Cura até 50% da vida do seu monstrinho");
        setCura(50);
    }else if(dado<=55 && dado>0){
        setNome("Poção Pequena");
        setDescricao("Cura até 25% da vida do seu monstrinho");
        setCura(25);
    }else{
        throw std::runtime_error("Dado incorreto menor que 0 ou maior que 100");
    }
}

void Cura::setCura(int cura){
    this->cura = cura;
}

int Cura::getCura(){
    return cura;
}