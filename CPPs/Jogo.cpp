#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../HPPs/Jogo.hpp"
#include "../HPPs/Treinador.hpp"
#include "../HPPs/Monstrinho.hpp"
#include "../HPPs/Ataque.hpp"

using std::cout;
using std::endl;
using std::cin;

void Jogo :: turnoJogador(vector<Monstrinho> equipe){
    std::cin>>opcao;
    switch(opcao){
        case 1:
            /*Atacar*/;
            break;
        case 2:
            /*Mudar monstrinho*/;
            break;
        case 3:
            /*usar item*/;
            break;
    }
}

void turnoBot(){
    int opcao = rand() % 3 + 1;
    switch(opcao){
        case 1:
            /*Atacar*/;
            break;
        case 2:
            /*Mudar monstrinho*/;
            break;
        case 3:
            /*usar item*/;
            break;
    }
}

void geraTurno(){
    cout<<"--------------------------------Turno do Jogador--------------------------------"<<endl;
    cout<<"Escolha uma opção:"<<endl;
    cout<<"1 - Atacar"<<endl;
    cout<<"2 - Mudar monstrinho"<<endl;
    cout<<"3 - Usar item"<<endl;
    turnoJogador();
    cout<<"--------------------------------Turno do Bot--------------------------------"<<endl;
    turnoBot();
    if(/*ataque x ataque*/){
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
    else if(/*ataque x change*/){
        /*
        
        if(monstrinho1.velocidade >= monstrinho2.velocidade){
            gerarAtaque(1);
                if(monstrinho2.HP <= 0){
                    trocaMonstrinho(2);
                    continue;
                };
                
        }else{
            trocaMonstrinho(2);
            gerarAtaque(1);
                if(monstrinho2.HP <= 0){
                    trocaMonstrinho(2);
                    continue;
                };
        }
        */
    }
    else if(/*ataque x item*/){
        /*
        if(monstrinho1.velocidade >= monstrinho2.velocidade){
            gerarAtaque(1);
                if(monstrinho2.HP <= 0){
                    trocaMonstrinho(2);
                    continue;
                };
                
        }else{
            uarItem(2);
            gerarAtaque(1);
                if(monstrinho2.HP <= 0){
                    trocaMonstrinho(2);
                    continue;
                };
        }
        */
    }
    else if(/*change x ataque*/){
        /*
        trocaMonstrinho(1);
        gerarAtaque(2);
        if(monstrinho1.velocidade >= monstrinho2.velocidade){
            trocaMonstrinho(1);
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
        }
        */
    }
    else if(/*change x change*/){
        /*
        trocaMonstrinho(1);
        trocaMonstrinho(2);
        */
    }
    else if(/*change x item*/){
        /*
        if(monstrinho1.velocidade >= monstrinho2.velocidade){
            trocaMonstrinho(1);
            usarItem(2);
        }else{
            usarItem(2);
            trocaMonstrinho(1);
        }
        */
    }
    else if(/*item x ataque*/){
        /*
        if(monstrinho1.velocidade >= monstrinho2.velocidade){
            usarItem(1);
            gerarAtaque(2);
            if(monstrinho1.HP <= 0){
                trocaMonstrinho(1);
                continue;
            }
        }else{
            gerarAtaque(2);
            if(monstrinho1.HP <= 0){
                trocaMonstrinho(1);
                continue;
            }
            usarItem(1);
        }
        */
    }
    else if(/*item x change*/){
        /*
        if(monstrinho1.velocidade >= monstrinho2.velocidade){
            usarItem(1);
            trocarMonstrinho(2);
        }else{
            trocarMonstrinho(2);
            usarItem(1);
        }
        */
    }
    else if(/*item x item*/){
        /*
        usarItem(1);
        usarItem(2);
        if(monstrinho1.velocidade >= monstrinho2.velocidade){
            usarItem(1);
            usarItem(2);
        }else{
            usarItem(2);
            usarItem(1);
        }
        */
    }
    
}

void iniciar(){
    bool state = false;
    std::string start;

    cout<<"Digite start no terminal para iniciar o jogo."<<endl;
    cin>>start;

    if(start == "start"){
       state = true;
    }
    while(state){
        cout<<"--------------------------------Bem vindo ao Monstrinhos--------------------------------"<<endl;
        escolherMonstrinho();
        while(calculaVidaEquipe() > 0 && calculaVidaEquipe() > 0){
            geraTurno();
        }
        state = false;
    }
}

/*
void escolherMonstrinho(vector<Monstrinho> time){
    cout<<"--------------------------------Escolha seu time--------------------------------"<<endl;
    for(int i = 0; i < 10; i++){
        cout<<"coiso"; //mudar para função da malu
    }
   
    int opcao;
    cout<<"Digite o ID do Monstrinho para adiciona-lo ao seu time."<<endl;
    for(int i = 0; i < 4; i++){
        cin>>opcao;
        for(int j = 0; j < )
    }

    
}
*/



