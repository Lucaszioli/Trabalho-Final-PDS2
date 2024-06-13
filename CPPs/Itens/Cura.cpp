#include "../../HPPs/Itens-hpp/Cura.hpp"
#include <cstdlib>
#include <../../ERR/CuraError.hpp>

void Cura::usarItem(Monstrinho m){
    int vidaTotal = m.getMaxHP();
    int vidaAtual = m.getHP(); // mudar quando tiver 2 vidas
    if (vidaAtual == vidaTotal){
        throw CuraError("O monstrinoho já está com a vida máxima, escolha outro");
    }
    int vidaFinal = (vidaTotal * cura/100)+vidaAtual;
    if(vidaFinal > vidaTotal){
        vidaFinal = vidaTotal;
    } 
    m.setHP(vidaFinal);
}

void Cura::pegarItem(){
    int dado = (rand() % 100) + 1;
    if(dado>95 && dado<=100){
        setNome("Poção Máxima");
        setDescricao("Cura toda a vida do seu monstrinho");
        setCura(100);
        setTipo("Cura");
    }else if(dado<=95 && dado>85){
        setNome("Poção Grande");
        setDescricao("Cura até 75% da vida do seu monstrinho");
        setCura(75);
        setTipo("Cura");
    }else if(dado<=85 && dado>55){
        setNome("Poção Média");
        setDescricao("Cura até 50% da vida do seu monstrinho");
        setCura(50);
        setTipo("Cura");
    }else if(dado<=55 && dado>0){
        setNome("Poção Pequena");
        setDescricao("Cura até 25% da vida do seu monstrinho");
        setCura(25);
        setTipo("Cura");
    }
}

void Cura::setCura(int cura){
    this->cura = cura;
}

int Cura::getCura(){
    return cura;
}