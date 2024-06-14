#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include "../HPPs/Jogo.hpp"
#include "../HPPs/Treinador.hpp"
#include "../HPPs/Jogador.hpp"
#include "../HPPs/Monstrinho.hpp"
#include "../HPPs/Ataque.hpp"

using std::vector;
using std::cout;
using std::endl;
using std::cin;

void Jogo :: turnoJogador(Jogador &jogador){
    int opcao;
    std::cin>>opcao;
    switch(opcao){
        case 1:
            /*Atacar*/;
            break;
        case 2:
            jogador.mudaEquipe();
            break;
        case 3:
            /*usar item*/;
            break;
    }
}
/*
void Jogo :: turnoBot(Jogador &bot){
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int opcao = std::rand() % 3 + 1;
    switch(opcao){
        case 1:
            Atacar;
            break;
        case 2:
            bot.mudaEquipe();
            break;
        case 3:
            usar item;
            break;
    }
}
*/

void Jogo :: geraTurno(Jogador &player, Jogador &bot){
    cout<<"--------------------------------Turno do Jogador--------------------------------"<<endl;
    cout<<"Escolha uma opção:"<<endl;
    cout<<"1 - Atacar"<<endl;
    cout<<"2 - Mudar monstrinho"<<endl;
    cout<<"3 - Usar item"<<endl;
    turnoJogador(player);
    cout<<"--------------------------------Turno do Bot--------------------------------"<<endl;
    turnoBot(bot);
    if(/*ataque*/){
        /*
        if(monstrinho1.velocidade >= monstrinho2.velocidade){
            gerarAtaque(1);
                if(monstrinho2.HP <= 0){
                    trocaMonstrinho(2);
                    continue;
                };
            gerarAtaque(2);
                if(monstrinho1.HP <= 0){
                    trocaMonstrinho(1);
                    continue;
                };
                
        }else{
            gerarAtaque(2);
                if(monstrinho1.HP <= 0){
                    trocaMonstrinho(1);
                    continue;
                };
            gerarAtaque(1);
                if(monstrinho2.HP <= 0){
                    trocaMonstrinho(2);
                    continue;
                };
        }
        */
           
    }
    else if(/*change*/){
        /*
        trocaMonstrinho(1);
        gerarAtaque(2);
            if(monstrinho1.HP <= 0){
                trocaMonstrinho(1);
                continue;
            };
        */
    }
    else if(/*item*/){
        /*
        usarItem(1);
        gerarAtaque(2);
        if(monstrinho1.HP <= 0){
            trocaMonstrinho(1);
            continue;
        }
        */
    }
    
}

void Jogo :: iniciar(){
    vector<Monstrinho> equipe;
    vector<Monstrinho> equipeBot;
    Jogador player(1, "Robervau", equipe);
    Jogador bot(0, "Roboto", equipeBot);
    bool state = false;
    std::string start;
    cout<<"Digite start no terminal para iniciar o jogo."<<endl;
    cin>>start;

    if(start == "start"){
       state = true;
    }
    while(state){
        cout<<"--------------------------------Bem vindo ao Monstrinhos--------------------------------"<<endl;
        escolherMonstrinho(player.equipe);
        while(player.verificaEquipe() != false && bot.verificaEquipe() != false){
            geraTurno();
        }
        state = false;
    }
}


void Jogo :: escolherMonstrinho(vector<Monstrinho> time){
    vector<Monstrinho> monstrinhos;
    monstrinhos = função da malu
    cout<<"--------------------------------Escolha seu time--------------------------------"<<endl;
    for(int i = 0; i < monstrinhos.size(); i++){
        cout<<monstrinhos[i]; //mudar para função da malu
    }
   
    int opcao;
    cout<<"Digite o ID do Monstrinho para adiciona-lo ao seu time."<<endl;
    for(int i = 0; i < 4; i++){
        cin>>opcao;
        for(int j = 0; j < monstrinhos.size(); j++){
            if(opcao == monstrinhos[j].getID()){
                time.push_back(monstrinhos[j]);
                cout<<"Monstrinho adicionado com sucesso!"<<endl;                
                break;
            }
        }    
    } 
}




