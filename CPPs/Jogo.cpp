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

vector<Monstrinho*> Jogo :: escolherMonstrinho(){
    vector<Monstrinho*> equipe;
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
                equipe.push_back(new Monstrinho(monstrinhos[j]));
                cout<<"Monstrinho adicionado com sucesso!"<<endl;                
                break;
            }else{
                throw "Monstrinho não adicionado!";
            }
        }    
    }
    return equipe; 
    }
}

vector<Monstrinho*> Jogo :: criaEquipeBot(){
    vector<Monstrinho*> equipeBot;
    vector<Monstrinho> monstrinhos;
    monstrinhos = Monstrinho::construirMonstrinhos();
    for(int i = 0; i < 4; i++){
        int opcao;
        do{
            opcao = rand() % 40;
        }while(monstrinhos[opcao].getTier() != 1);
        
        if(monstrinhos[opcao].getTier() == 1){
            equipeBot.push_back(new Monstrinho(monstrinhos[opcao]));
            cout<<"Monstrinho adicionado com sucesso!"<<endl;                
            break;
        }else{
            throw "Monstrinho não adicionado!";
        }
           
    }
    return equipeBot;
}

void Jogo :: geraTurno(Jogador* jogador, Bot* bot, vector<Monstrinho*> monstroJogador, vector<Monstrinho*> monstroBot){
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
        if(monstroJogador[0]->getVelocidade() >= monstroBot[0]->getVelocidade()){
            monstroJogador[0]->atacar(monstroJogador[0], monstroBot[0]);
            if(monstroBot[0]->getHPAtual() <= 0){
                bot->mudaEquipe();
                jogador->receberItem();
            }else{
                monstroBot[0]->atacar(monstroBot[0], monstroJogador[0]);
            }
        }else{
            monstroBot[0]->atacar(monstroBot[0], monstroJogador[0]);
            if(monstroJogador[0]->getHPAtual() <= 0){
                jogador->mudaEquipe();
            }else{
                monstroJogador[0]->atacar(monstroJogador[0], monstroBot[0]);
            }
        }
        break;
    
    case 2:
        jogador->mudaEquipe();
        monstroBot[0]->atacar(monstroBot[0], monstroJogador[0]);
        if(monstroJogador[0]->getHPAtual() <= 0){
            jogador->mudaEquipe();
        }
        break;

    case 3:
        jogador->usarItem();
        monstroBot[0]->atacar(monstroBot[0], monstroJogador[0]);
        if(monstroJogador[0]->getHPAtual() <= 0){
            jogador->mudaEquipe();
        }
        break;
    }
    
}

void Jogo :: iniciar(){
    vector<Monstrinho*> equipe;
    vector<Monstrinho*> equipeBot;
    string nome;
    std::string start;
    cout<<"Digite start no terminal para iniciar o jogo."<<endl;
    cin>>start;

    if(start == "start"){
        do{
            cout<<"--------------------------------Bem vindo ao Monstrinhos--------------------------------"<<endl;
        
            cout<<"Escolha um nome para o seu Personagem."<<endl;
            cin>>nome;
            equipe = escolherMonstrinho();
            equipeBot = criaEquipeBot();

            Jogador* jogador = new Jogador(1, nome, equipe);
            Bot* bot = new Bot(0, "ChatGPT", equipeBot, {"facil"});
        
            while(jogador->verificaEquipe() && bot->verificaEquipe()){
                geraTurno(jogador, bot, equipe, equipeBot);
            }
            if(jogador->verificaEquipe()){
                cout<<"Parabéns você venceu!"<<endl;
            }else{
                cout<<"Você perdeu!"<<endl;
            }
            cout<<"Digite start para jogar novamente ou qualquer outra coisa para sair."<<endl;
            cin>>start;
        } while(start == "start");
       }
}