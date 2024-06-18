#include "../HPPs/Cura.hpp"
#include <cstdlib>
#include "../ERR/CuraError.hpp"
#include <iostream>

bool Cura::usarItem(Monstrinho* m){
    int vidaTotal = m -> getHP();
    int vidaAtual = m -> getHPAtual(); // mudar quando tiver 2 vidas
    if (vidaAtual == vidaTotal){
        throw CuraError("O monstrinho já está com a vida máxima, escolha outro monstro");
    }
    if (vidaAtual == 0){
        throw CuraError("O monstrinho já está morto, use um Revive ou escolha outro monstro");
    }
    int vidaFinal = (vidaTotal * cura/100)+vidaAtual;
    if(vidaFinal > vidaTotal){
        vidaFinal = vidaTotal;
    } 
    m -> setHPAtual(vidaFinal);
    int vidaRestaurada = vidaFinal - vidaAtual;
    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout << "A vida do seu "<< m->getNome() <<" foi restaurada em " << vidaRestaurada << " pontos" << endl;
    cout<<"--------------------------------------------------------------------------------"<<endl;
    return false;
}

void Cura::pegarItem(){
    int dado = (rand() % 100) + 1;
    setTipo("Cura");
    if(dado>95 && dado<=100){
        setNome("Poção Máxima");
        setDescricao("Cura toda a vida do seu monstrinho");
        setCura(100);
        setRaridade("Máx");
    }else if(dado<=95 && dado>85){
        setNome("Poção Grande");
        setDescricao("Cura até 75% da vida do seu monstrinho");
        setCura(75);
        setRaridade("Grande");
    }else if(dado<=85 && dado>55){
        setNome("Poção Média");
        setDescricao("Cura até 50% da vida do seu monstrinho");
        setCura(50);
        setRaridade("Média");
    }else if(dado<=55 && dado>0){
        setNome("Poção Pequena");
        setDescricao("Cura até 25% da vida do seu monstrinho");
        setCura(25);
        setRaridade("Pequena");
    }
}

void Cura::setCura(int cura){
    this->cura = cura;
}

int Cura::getCura(){
    return cura;
}