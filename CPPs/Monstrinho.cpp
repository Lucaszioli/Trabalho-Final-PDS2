#include "../HPPs/Monstrinho.hpp"
#include "../HPPs/Ataque.hpp"
#include <fstream>
#include <sstream>
#include <exception>
#include <stdexcept>
#include <iostream>

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

void Monstrinho :: atacar(Monstrinho* monstroAtacante, Monstrinho* monstroAtacado){
    int opcao;
    cout<<"Escolha um ataque:"<<endl;
    for(int i = 0; i < monstroAtacante->getAtaques().size(); i++){
        cout<<monstroAtacante->getAtaques()[i].getID()<<"-"<<monstroAtacante->getAtaques()[i].getNome()<<endl;
    }
    cin>>opcao;    
    for(int i = 0; i < monstroAtacante->getAtaques().size(); i++){
        if(opcao == monstroAtacante->getAtaques()[i].getID()){
            monstroAtacante->getAtaques()[i].fazerAtaque(monstroAtacado[0]);
            break;
        }
    }
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
        string descricao = dados[2];
        vector<string> tipo;
        stringstream ssTipo(dados[3]);
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
        


        monstrinhos.push_back(Monstrinho(ID, nome, descricao, tipo, HP, HPAtual, velocidade, tier, ataques));
    }

    return monstrinhos;
}
