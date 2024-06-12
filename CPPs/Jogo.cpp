#include <iostream>
#include "../HPPs/Jogo.hpp"
#include "../HPPs/Treinador.hpp"
#include "../HPPs/Monstrinho.hpp"

using std::cout;
using std::endl;

void Jogo :: usarIten(Monstrinho monstrinho){
    cout<<"Usar item"<<endl;
}

int Jogo :: geraCombate(){
    cout<<"Combate"<<endl;
    return 0;
}


void Jogo :: iniciaTurno(Monstrinho monstrinho, vector<Monstrinho> equipe){
    std::cin>>opcao;
    switch(opcao){
        case 0:
            geraCombate();
            break;
        case 1:
            proximoMonstrinho(equipe);
            break;
        case 2:
            usarIten(monstrinho);
            break;
    }
}

void Jogo :: escolheAtaque(){
    std::cin>>opcao;
    switch(opcao){
        case 0:
            ;
            break;
        case 1:
            ;
            break;
        case 2:
            ;
            break;
        case 3:
            ;
            break;
    }
}


