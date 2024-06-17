#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <limits>
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
#include "../ERR/EscolhaError.hpp"

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
        cout<<monstrinhos[i].getID()<<"-"<<monstrinhos[i].getNome()<<" - Custo: "<<monstrinhos[i].getTier()<<endl;
    }
   
    int opcao;
    int moedas = 12;
    std::set<int> indicesAdicionados;
    for(int i = 0; i < 4; i++){
        bool erro = 0;
        do{
            try{
            cout<<"Digite o ID do Monstrinho para adicioná-lo ao seu time."<<endl;
            cout<<"Você tem "<<moedas<<" moedas, use-as para adicionar os Monstrinhos ao seu time"<<endl;
            cout<<"--------------------------------------------------------------------------------"<<endl;
            cin>>opcao;
            if(std::cin.fail()) { // Se a entrada falhar (por exemplo, o usuário digitou uma string)
                std::cin.clear(); // Limpa o estado de falha
                throw EscolhaError("Escolha diferente do número possível de opções");
            }
            if(opcao < 1 || opcao >monstrinhos.size()){
                throw EscolhaError("Escolha diferente do número possível de opções");
            }
            for(int j = 0; j < monstrinhos.size(); j++){
                if(opcao == monstrinhos[j].getID()){
                    if(monstrinhos[j].getTier() > moedas){
                        cout<<"Você não tem moedas o suficiente para esse monstrinho, escolha outro"<<endl;
                        cout<<"Você tem "<<moedas<<" moedas restantes"<<endl;
                        erro = 1;
                        break;
                    }else if(indicesAdicionados.find(opcao) != indicesAdicionados.end()){
                        cout<<"Você já escolheu esse monstrinho, escolha outro"<<endl;
                        erro = 1;
                        break;
                    }else{
                        jogador->colocaMonstrinho(monstrinhos[j]);
                        moedas -= monstrinhos[j].getTier();
                        indicesAdicionados.insert(opcao);
                        cout<<"Monstrinho adicionado com sucesso!"<<endl;
                        cout<<"Você tem "<<moedas<<" moedas restantes"<<endl;
                        erro = 0;             
                        break;
                    }
                }
            }
            
            }catch(EscolhaError& e){
                cout<<"------------------------------------------------------------"<<endl;  
                cout<<e.what()<<endl;
                cout<<"------------------------------------------------------------"<<endl;  
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
                erro = 1;
            }
        }while(erro == 1);
        if(moedas == 0){
            break;
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
            opcao = rand() % 42;
            if((monstrinhos[opcao].getTier() == 1 || monstrinhos[opcao].getTier() == 2) && indicesAdicionados.find(opcao) == indicesAdicionados.end() && i == 0){        
                bot->colocaMonstrinho(monstrinhos[opcao]);
                indicesAdicionados.insert(opcao);
                state = false;
            }
            else if(monstrinhos[opcao].getTier() == i+2 && indicesAdicionados.find(opcao) == indicesAdicionados.end()){        
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
    int escolha;
    while(!state){   
        int opcao;
        int ataqueBot = rand() % 4;
        float vidaBot = static_cast<float>(bot->getEquipe()[0]->getHPAtual())/bot->getEquipe()[0]->getHP(); 
        vidaBot = static_cast<int>(vidaBot * 1000) / 10.0f;
         
        cout<<"--------------------------------Turno do Jogador--------------------------------"<<endl;
        cout<<"Monstrinho adversário: " << bot->getEquipe()[0]->getNome()<<" - HP: "<<vidaBot<<"%"<<endl;
        cout<<"--------------------------------------------------------------------------------"<<endl;
        cout<<"Seu Monstrinho: " << jogador->getEquipe()[0]->getNome()<<" - HP: "<<jogador->getEquipe()[0]->getHPAtual()<<"/"<<jogador->getEquipe()[0]->getHP()<<endl;
        cout<<"--------------------------------------------------------------------------------"<<endl;
        cout<<"Escolha uma opção:"<<endl;
        cout<<"1 - Atacar"<<endl;
        cout<<"2 - Mudar monstrinho"<<endl;
        cout<<"3 - Usar item"<<endl;
        cout<<"--------------------------------------------------------------------------------"<<endl;
        cin>>opcao;
        switch (opcao)
        {
        case 1:
            escolha = jogador->getEquipe()[0]->escolhaAtaque();
            if(escolha != 4){
                if(jogador->getEquipe()[0]->getVelocidade() >= bot->getEquipe()[0]->getVelocidade()){
                    state = jogador->getEquipe()[0]->atacar(bot->getEquipe()[0],escolha);
                    if(bot->getEquipe()[0]->getHPAtual() <= 0){
                        bot->mudaEquipe();
                        jogador->receberItem();
                    }else{
                        bot->getEquipe()[0]->atacar(jogador->getEquipe()[0],ataqueBot);
                        if(jogador->getEquipe()[0]->getHPAtual() <= 0){
                            jogador->mudaEquipe();
                            cout<<jogador->getEquipe()[0]->getNome();
                        }
                    }
                   
                }else{
                    bot->getEquipe()[0]->atacar(jogador->getEquipe()[0],ataqueBot);
                    if(jogador->getEquipe()[0]->getHPAtual() <= 0){
                        jogador->mudaEquipe();
                    }else{
                        jogador->getEquipe()[0]->atacar(bot->getEquipe()[0],escolha);
                        if(bot->getEquipe()[0]->getHPAtual() <= 0){
                            bot->mudaEquipe();
                            jogador->receberItem();
                        }
                    }
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
                state = true;
            }else{
                state = false;
            }
            break;
        
        case 2:
            state = jogador->mudaEquipe();
            if(state == true){
                bot->getEquipe()[0]->atacar(jogador->getEquipe()[0],ataqueBot);
                if(jogador->getEquipe()[0]->getHPAtual() <= 0){
                    jogador->mudaEquipe();
                }
            }
            break;

        case 3:
            state = jogador->usarItem();
            if(state == true){
                bot->getEquipe()[0]->atacar(jogador->getEquipe()[0],ataqueBot);
                if(jogador->getEquipe()[0]->getHPAtual() <= 0){
                    jogador->mudaEquipe();
                }
            }
            break;
        }
    }
}

void Jogo :: iniciar(){
    system("clear");
    vector<Monstrinho*> equipe;
    vector<Monstrinho*> equipeBot;
    string nome;
    std::string start;
    cout << "___  ___                _        _       _               " << endl;
    cout << "|  \\/  |               | |      (_)     | |              " << endl;
    cout << "| .  . | ___  _ __  ___| |_ _ __ _ _ __ | |__   ___  ___ " << endl;
    cout << "| |\\/| |/ _ \\| '_ \\/ __| __| '__| | '_ \\| '_ \\ / _ \\/ __|" << endl;
    cout << "| |  | | (_) | | | \\__ \\ |_| |  | | | | | | | | (_) \\__ \\" << endl;
    cout << "\\_|  |_/\\___/|_| |_|___/\\__|_|  |_|_| |_|_| |_|\\___/|___/" << endl;
    cout << "                                                         " << endl;
    cout << "Um Projeto por: Otávio Serafim, Malu Lauar, Lucas Zioli, Matheus Gregor e Henrique Joaquim!" << endl;
    cout <<endl;
    cout << "Digite 'start' para iniciar o jogo." << endl;
    cin >> start;

    if(start == "start"){
        do{
            cout<<"----------------------------Bem vindo ao Monstrinhos----------------------------"<<endl;
        
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