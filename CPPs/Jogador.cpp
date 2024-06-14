#include "../HPPs/Jogador.hpp"
#include <iostream>
#include "../HPPs/Itens-hpp/Cura.hpp"
#include "../HPPs/Itens-hpp/Revive.hpp"
#include "../HPPs/Itens-hpp/Estamina.hpp"
#include "../ERR/BadRequestError.hpp"
#include "../ERR/EscolhaError.hpp"
#include <ctime>
#include <cstdlib>

Jogador::Jogador(int ID, string nome, vector<Monstrinho *> equipe)
    : Treinador(ID, nome, equipe) {}

void Jogador::mudaEquipe()
{
    if (verificaEquipe())
    {
        if (equipe[0]->getHP() <= 0)
        {
            cout << "O " << equipe[0]->getNome() << " foi derrotado!" << endl;
            cout << "Escolha um monstrinho para substituir o que foi derrotado: " << endl;
            imprimeEquipe();
            int escolha;
            cin >> escolha;
            if (escolha < 1 || escolha > equipe.size())
            {
                cout << "Escolha inválida!" << endl;
                mudaEquipe();
            }
            if (equipe[escolha - 1]->getHP() <= 0)
            {
                cout << "Esse monstrinho está desmaiado!" << endl;
                mudaEquipe();
            }
            equipe.push_back(equipe[0]);
            equipe[0] = equipe[escolha - 1];
            equipe.erase(equipe.begin() + escolha - 1);
        }
    }
}


void Jogador::receberItem(){
    bool erro = 0;
    do{
        try{
            vector<Item*> inventario = getInventario();
            srand(static_cast<unsigned int>(time(0)));
            int dado = (rand() % 100) + 1;
            Item* item;
            if(dado>60 && dado<=100){
                item = new Cura();
                item -> pegarItem();
            }else if(dado<=60 && dado>40){
                item = new Revive();
                item-> pegarItem();
            }else if(dado<=40 && dado>0){
                item = new Estamina();
                item -> pegarItem();
            }
            adicionarItem(item);
            erro = 0;
        }catch(const std::exception& e){
            erro = 1; 
        }
    }while(erro == 1);
}

void Jogador::usarItem(){
    try{
        vector<Item*> inventario = getInventario();
        int i = 1;
        if(inventario.size() == 0){
            throw BadRequestError("Você não possui itens");
        }
        for(auto& item:inventario){
            cout<<i<<"- "<<item->getNome()<<endl;
            i++;
        }
        int escolhaItem;
        cout<<"Qual item você quer usar?"<<endl;
        cin>>escolhaItem;

        if(escolhaItem > i){
            throw EscolhaError("Escolha maior que o numero possível de opções");
        }

        Item* item = inventario[escolhaItem-1];

        string tipo = item -> getTipo();

        if(tipo == "Cura"){
            vector<Monstrinho *> equipe = getEquipe();
            int j = 1;
            int escolhaMonstro;
            for(auto& monstro:equipe){
                cout<<j<<"- "<<monstro->getNome()<<" HP:"<<monstro->getHPAtual()<<"/"<<monstro->getHP()<<endl;
                j++;
            }
            cout<< "Em qual monstro você deseja usar o item?"<<endl;
            cin >> escolhaMonstro;
            if(escolhaMonstro > j){
                throw EscolhaError("Escolha maior que o numero possível de opções");
            }

            Monstrinho* monstro = equipe[escolhaMonstro - 1];
            dynamic_cast<Cura*>(item)->usarItem(monstro);
            removerItem(item);
        }else if(tipo == "Revive"){
            vector<Monstrinho *> equipe = getEquipe();
            int j = 1;
            int escolhaMonstro;
            for(auto& monstro:equipe){
                cout<<j<<"- "<<monstro->getNome()<<" HP:"<<monstro->getHPAtual()<<"/"<<monstro->getHP()<<endl;
                j++;
            }
            cout<< "Em qual monstro você deseja usar o item?"<<endl;
            cin >> escolhaMonstro;
            if(escolhaMonstro > j){
                throw EscolhaError("Escolha maior que o numero possível de opções");
            }

            Monstrinho* monstro = equipe[escolhaMonstro - 1];
            dynamic_cast<Revive*>(item)->usarItem(monstro);
            removerItem(item);
        }else if(tipo == "Estamina"){
            vector<Monstrinho *> equipe = getEquipe();
            int j = 1;
            int escolhaMonstro;
            for(auto& monstro:equipe){
                cout<<j<<"- "<<monstro->getNome()<<" HP:"<<monstro->getHPAtual()<<"/"<<monstro->getHP()<<endl;
                j++;
            }
            cout<< "Em qual monstro você deseja usar o item?"<<endl;
            cin >> escolhaMonstro;
            if(escolhaMonstro > j){
                throw EscolhaError("Escolha maior que o numero possível de opções");
            }

            Monstrinho* monstro = equipe[escolhaMonstro - 1];
            dynamic_cast<Estamina*>(item)->usarItem(monstro);
            removerItem(item);
        }
    }catch(const BadRequestError& e){
        cout<<e.what()<<endl;
    }catch(const EscolhaError& e){
        cout<<e.what()<<endl;
    }
}