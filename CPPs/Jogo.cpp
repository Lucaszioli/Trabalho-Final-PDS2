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

vector<Monstrinho> Jogo :: escolherMonstrinho(vector<Monstrinho> equipe){
    vector<Monstrinho> monstrinhos;
    monstrinhos = função da malu
    cout<<"--------------------------------Escolha seu time--------------------------------"<<endl;
    for(int i = 0; i < monstrinhos.size(); i++){
        cout<<monstrinhos[i]; //mudar para função da malu
    }
   
    int opcao;
    for(int i = 0; i < 4; i++){
        cout<<"Digite o ID do Monstrinho para adiciona-lo ao seu time."<<endl;
        cin>>opcao;
        for(int j = 0; j < monstrinhos.size(); j++){
            if(opcao == monstrinhos[j].getID()){
                equipe.push_back(monstrinhos[j]);
                cout<<"Monstrinho adicionado com sucesso!"<<endl;                
                break;
            }
        }    
    }
    return equipe; 
}


void Jogo :: geraTurno(Monstrinho &monstrinhoPlayer, Monstrinho &mosntrinhoBot){
    int opcao;
    cout<<"--------------------------------Turno do Jogador--------------------------------"<<endl;
    cout<<"Escolha uma opção:"<<endl;
    cout<<"1 - Atacar"<<endl;
    cout<<"2 - Mudar monstrinho"<<endl;
    cout<<"3 - Usar item"<<endl;
    cin>>opcao;
    switch (opcao)
    {
    case 1:
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
        break;
    
    case 2:
        /*
        trocaMonstrinho(1);
        gerarAtaque(2);
            if(monstrinho1.HP <= 0){
                trocaMonstrinho(1);
                continue;
            };
        */
        break;

    case 3:
        /*
        usarItem(1);
        gerarAtaque(2);
        if(monstrinho1.HP <= 0){
            trocaMonstrinho(1);
            continue;
        }
        */
        break;
    }
    
}

void Jogo :: iniciar(){
    vector<Monstrinho> equipe;
    vector<Monstrinho> equipeBot;
    string nome;
    bool state = false;
    std::string start;
    cout<<"Digite start no terminal para iniciar o jogo."<<endl;
    cin>>start;

    if(start == "start"){
        do{
            cout<<"--------------------------------Bem vindo ao Monstrinhos--------------------------------"<<endl;
        
            cout<<"Escolha um nome para o seu Personagem."<<endl;
            cin>>nome;
            equipe = escolherMonstrinho(jogador.getEquipe());

            Jogador jogador(1, nome, equipe);
            Jogador bot(0, "ChatGPT", equipeBot);
        
            while(jogador.verificaEquipe() && bot.verificaEquipe()){
                geraTurno(equipe[0], equipeBot[0]);
            }
            cout<<"Digite start para jogar ou qulquer outra coisa para sair."<<endl;
            cin>>start;
        } while(start == "start");
       }
}