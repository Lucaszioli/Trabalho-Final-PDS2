#include "../HPPs/Monstrinho.hpp"
#include "../HPPs/Ataque.hpp"
#include <fstream>
#include <limits>
#include <sstream>
#include <exception>
#include <stdexcept>
#include <iostream>
#include "../ERR/EscolhaError.hpp"
#include "../ERR/AtaqueError.hpp"

int Monstrinho::getID() {
    return ID;
}

string Monstrinho::getNome() {
    return nome;
}

string Monstrinho::getDescricao() {
    return descricao;
}

vector<string> Monstrinho::getTipo() {
    return tipo;
}

int Monstrinho::getHP() {
    return HP;
}

int Monstrinho::getHPAtual() {
    return HPAtual;
}

void Monstrinho::setHPAtual(int HPAtual) {
    this->HPAtual = HPAtual;
}

int Monstrinho::getVelocidade() {
    return velocidade;
} 

int Monstrinho::getTier() {
    return tier;
}

vector<Ataque>& Monstrinho::getAtaques() {
    return this->ataques;
}

bool Monstrinho :: atacar(Monstrinho* monstroAtacado, int escolha){
    bool state = false;
    while(!state){
        try{
            cout<<"--------------------------------------------------------------------------------"<<endl;
            cout<<getNome()<<" usou ";
            state = getAtaques()[escolha].fazerAtaque(monstroAtacado[0]);
        cout<<"--------------------------------------------------------------------------------"<<endl;
        }   catch(std::exception& e){
                cout<<e.what()<<endl;
                state = false;
            }
    }
    return state;
}

vector <Monstrinho> Monstrinho::construirMonstrinhos() {
    vector<Monstrinho> monstrinhos;
    ifstream arquivo("../CSVs/Monstrinhos.csv");

    if (!arquivo.is_open()) {
        throw runtime_error("Não foi possível abrir o arquivo Monstrinhos.csv");
    }

    string linha;
    getline(arquivo, linha); 

    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        vector<string> dados;

        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            dados.push_back(substr);
        }

        int ID = stoi(dados[0]);
        string nome = dados[1];
        vector<string> tipo;
        stringstream ssTipo(dados[2]);
        string descricao = dados[3];
        string tipoStr;
        while (getline(ssTipo, tipoStr, ';')) { // Separa os tipos
            tipo.push_back(tipoStr); // Adiciona cada tipo ao vetor de tipos
        }
        int HP = stoi(dados[4]);
        int velocidade = stoi(dados[5]);
        int tier = stoi(dados[6]);
        vector<Ataque> ataques;
        int HPAtual = HP;

        vector<Ataque> todosAtaques = Ataque::construirAtaques();

        stringstream ssAtaques(dados[7]);
        string ataqueStr;
        while (getline(ssAtaques, ataqueStr, ';')) { // Separa os IDs dos ataques
            for (Ataque ataque : todosAtaques) { // Procura os ataques com os IDs
                if (ataque.getID() == stoi(ataqueStr)) { // Se o ID do ataque for igual ao ID do ataqueStr
                    ataques.push_back(ataque); // Adiciona o ataque ao vetor de ataques
                }
            }
        }
        


        monstrinhos.push_back(Monstrinho(ID, nome, tipo, descricao, HP, HPAtual, velocidade, tier, ataques));
    }

    return monstrinhos;
}


int Monstrinho::escolhaAtaque(){
    int opcao;
    bool erro;
    do{
        try{
            cout<<"--------------------------------------------------------------------------------"<<endl;
            cout<<"O Monstrinho "<<getNome()<<" esta atacando"<<endl;
            cout<<"Escolha um ataque:"<<endl;
            int i = 1;
            for(auto& ataque:getAtaques()){
                cout<<i<<"-"<<getAtaques()[i-1].getNome()<<" - Estamina: "<<getAtaques()[i-1].getQuantidadeAtual()<<"/"<<getAtaques()[i-1].getQuantidade()<<" Dano:"<<getAtaques()[i-1].getDano()<<endl;
                i++;
            }
            cout<<i<<"- Voltar"<<endl;
            cout<<"--------------------------------------------------------------------------------"<<endl;
            cin>>opcao;    
            if(std::cin.fail()) { // Se a entrada falhar (por exemplo, o usuário digitou uma string)
                std::cin.clear(); // Limpa o estado de falha
                throw EscolhaError("Escolha diferente do número possível de opções");
            }
            if(opcao > i || opcao < 1){
                erro = 1;
                throw EscolhaError("Escolha diferente do número possível de opções");
            }
            if(getAtaques()[opcao-1].getQuantidadeAtual()<=0 && opcao != i ){
                throw AtaqueError("Ataque sem energia, por favor escolha outro");
            }
            erro = false;
        }catch(EscolhaError& e){
            cout<<"--------------------------------------------------------------------------------"<<endl; 
            cout<<e.what()<<endl;
            cout<<"--------------------------------------------------------------------------------"<<endl; 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            erro = 1;
        }catch(AtaqueError& e){
            cout<<"--------------------------------------------------------------------------------"<<endl; 
            cout<<e.what()<<endl;
            cout<<"--------------------------------------------------------------------------------"<<endl;  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            erro = 1;
        }
    }while(erro == 1);
    
    return opcao-1;
}