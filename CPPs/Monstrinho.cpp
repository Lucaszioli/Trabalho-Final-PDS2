#include "../HPPs/Monstrinho.hpp"
#include "../HPPs/Ataque.hpp"
#include <fstream>
#include <sstream>
#include <exception>
#include <stdexcept>
#include <iostream>
#include "../ERR/EscolhaError.hpp"

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

bool Monstrinho :: atacar(Monstrinho* monstroAtacante, Monstrinho* monstroAtacado){
    int opcao;
    bool state = false;
    while(!state){
        try{
            cout<<"O Monstrinho "<<monstroAtacante->getNome()<<" esta atacando"<<endl;
            cout<<"Escolha um ataque:"<<endl;
            int i = 1;
            for(auto& ataque:monstroAtacante->getAtaques()){
                cout<<i<<"-"<<monstroAtacante->getAtaques()[i-1].getNome()<<endl;
                i++;
            }
            cout<<i<<"- Voltar"<<endl;
            cin>>opcao;    
            if(std::cin.fail()) { // Se a entrada falhar (por exemplo, o usuário digitou uma string)
                std::cin.clear(); // Limpa o estado de falha
                throw EscolhaError("Escolha diferente do numero possível de opções");
            }
            if(opcao > i || opcao < 1){
                throw EscolhaError("Escolha diferente do numero possível de opções");
            }
            else if(opcao == i){
                return false;
            }else{
                state = monstroAtacante->getAtaques()[opcao-1].fazerAtaque(monstroAtacado[0]);    
            }
                
        }catch(EscolhaError& e){
            cout<<e.what()<<endl;
            state = false;
        }catch(std::exception& e){
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
