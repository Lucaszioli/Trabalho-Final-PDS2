#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "../HPPs/Jogo.hpp"
#include "../HPPs/Treinador.hpp"
#include "../HPPs/Jogador.hpp"
#include "../HPPs/Monstrinho.hpp"
#include "../HPPs/Ataque.hpp"
#include "../HPPs/Bot.hpp"
#include "../HPPs/Item.hpp"
#include "../HPPs/Cura.hpp"
#include "../HPPs/Revive.hpp"
#include "../HPPs/Estamina.hpp"


using std::vector;
using std::cout;
using std::endl;
using std::cin;

vector<Monstrinho*> Jogo :: escolherMonstrinho(Jogador* jogador){
    vector<Monstrinho*> equipe;
    vector<Monstrinho> monstrinhos;
    monstrinhos = Monstrinho::construirMonstrinhos();
    cout<<"--------------------------------Escolha seu time--------------------------------"<<endl;
    for(int i = 0; i < monstrinhos.size(); i++){
        cout<<monstrinhos[i].getID()<<"-"<<monstrinhos[i].getNome()<<"-"<<monstrinhos[i].getTier()<<endl;
    }
   
    int opcao;
    
    for(int i = 0; i < 4; i++){
        cout<<"Digite o ID do Monstrinho para adiciona-lo ao seu time."<<endl;
        cin>>opcao;
        for(int j = 0; j < monstrinhos.size(); j++){
            if(opcao == monstrinhos[j].getID()){
                jogador->colocaMonstrinho(monstrinhos[j]);
                //equipe.push_back(new Monstrinho(monstrinhos[j]));
                cout<<"Monstrinho adicionado com sucesso!"<<endl;                
                break;
            }
        }    
    }
    return equipe; 
}

vector<Monstrinho*> Jogo :: criaEquipeBot(Bot* bot){
    vector<Monstrinho*> equipeBot;
    vector<Monstrinho> monstrinhos;
    monstrinhos = Monstrinho::construirMonstrinhos();
    std::set<int> indicesAdicionados;
    for(int i = 0; i < 4; i++){
        bool state = true;
        int opcao;
        while(state){
            opcao = rand() % 40;
            if(monstrinhos[opcao].getTier() == 1 && indicesAdicionados.find(opcao) == indicesAdicionados.end()){        
                bot->colocaMonstrinho(monstrinhos[opcao]);
                indicesAdicionados.insert(opcao);
                state = false;
            }          
        }    
    }  
    return equipeBot;
}



void Jogo :: geraTurno(Jogador* jogador, Bot* bot){
    bool state = false;
    while(!state){   
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
            if(jogador->getEquipe()[0]->getVelocidade() >= bot->getEquipe()[0]->getVelocidade()){
                state = jogador->getEquipe()[0]->atacar(jogador->getEquipe()[0], bot->getEquipe()[0]);
                if(bot->getEquipe()[0]->getHPAtual() <= 0){
                    bot->mudaEquipe();
                    jogador->receberItem();
                }else{
                    bot->getEquipe()[0]->atacar(bot->getEquipe()[0], jogador->getEquipe()[0]);
                    if(jogador->getEquipe()[0]->getHPAtual() <= 0){
                        jogador->mudaEquipe();
                        cout<<jogador->getEquipe()[0]->getNome();
                    }
                }
            }else{
                bot->getEquipe()[0]->atacar(bot->getEquipe()[0], jogador->getEquipe()[0]);
                if(jogador->getEquipe()[0]->getHPAtual() <= 0){
                    jogador->mudaEquipe();
                }else{
                    jogador->getEquipe()[0]->atacar(jogador->getEquipe()[0], bot->getEquipe()[0]);
                    if(bot->getEquipe()[0]->getHPAtual() <= 0){
                        bot->mudaEquipe();
                        jogador->receberItem();
                    }
                }
            }
            break;
        
        case 2:
            state = jogador->mudaEquipe();
            if(state = true){
                bot->getEquipe()[0]->atacar(bot->getEquipe()[0], jogador->getEquipe()[0]);
                if(jogador->getEquipe()[0]->getHPAtual() <= 0){
                    jogador->mudaEquipe();
                }
            }
            break;

        case 3:
            state = jogador->usarItem();
            if(state == true){
                bot->getEquipe()[0]->atacar(bot->getEquipe()[0], jogador->getEquipe()[0]);
                if(jogador->getEquipe()[0]->getHPAtual() <= 0){
                    jogador->mudaEquipe();
                }
            }
            break;
        }
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
            Jogador* jogador = new Jogador(1, nome, equipe);
            Bot* bot = new Bot(0, "ChatGPT", equipeBot, {"facil"});
            
            escolherMonstrinho(jogador);
            criaEquipeBot(bot);
            for(int i = 0; i < bot->getEquipe().size(); i++){
                cout<<bot->getEquipe()[i]->getNome()<<endl;
            }
            while(jogador->verificaEquipe() && bot->verificaEquipe()){
                geraTurno(jogador, bot);
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