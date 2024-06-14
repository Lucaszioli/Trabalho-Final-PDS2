#include <iostream>
#include <string>
#include <vector>
#include "../HPPs/Jogo.hpp"
#include "../HPPs/Treinador.hpp"
#include "../HPPs/Jogador.hpp"
#include "../HPPs/Monstrinho.hpp"
#include "../HPPs/Ataque.hpp"
#include "../HPPs/Bot.hpp"

using std::vector;
using std::cout;
using std::endl;
using std::cin;

vector<Monstrinho> Jogo :: escolherMonstrinho(){
    vector<Monstrinho> equipe;
    vector<Monstrinho> monstrinhos;
    monstrinhos = Monstrinho::construirMonstrinhos();
    cout<<"--------------------------------Escolha seu time--------------------------------"<<endl;
    for(int i = 0; i < monstrinhos.size(); i++){
        cout<<monstrinhos[i].getID()<<"-"<<monstrinhos[i].getNome()<<"-"<<monstrinhos[i].getTier()<<endl;
   
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
}

void Jogo :: geraTurno(Jogador &jogador, Bot &bot, Monstrinho &monstroJogador, Monstrinho &monstroBot){
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
        
        break;
    
    case 2:
        
        break;

    case 3:
        
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
            equipe = escolherMonstrinho();

            Jogador jogador(1, nome, equipe);
            Bot bot(0, "ChatGPT", equipeBot);
        
            while(jogador.verificaEquipe() && bot.verificaEquipe()){
                geraTurno(jogador, bot, equipe[0], equipeBot[0]);
            }
            if(jogador.verificaEquipe()){
                cout<<"Parabéns você venceu!"<<endl;
            }else{
                cout<<"Você perdeu!"<<endl;
            }
            cout<<"Digite start para jogar novamente ou qulquer outra coisa para sair."<<endl;
            cin>>start;
        } while(start == "start");
       }
}