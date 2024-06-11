#include "Ataque.hpp"
#include <fstream>
#include <sstream>
#include <exception>
#include <stdexcept>

int Ataque::getID() {
    return ID;
}

string Ataque::getNome() {
    return nome;
}

string Ataque::getTipo() {
    return tipo;
}

int Ataque::getDano() {
    return dano;
}

string Ataque::getDescricao() {
    return descricao;
}


int Ataque::getQuantidade() {
    return quantidade;
}

vector<Ataque> Ataque::construirAtaques() {
    vector<Ataque> ataques;
    ifstream arquivo("CSVs/Ataques.csv");

    if (!arquivo.is_open()) {
        throw runtime_error("Não foi possível abrir o arquivo Ataques.csv");
    }

    string linha;
    getline(arquivo, linha); // pula a primeira linha (cabeçalho)

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
        string tipo = dados[2];
        int dano = stoi(dados[3]);
        string descricao = dados[4];
        int quantidade = stoi(dados[5]);

        ataques.push_back(Ataque(ID, nome, tipo, dano, descricao, quantidade));
    }

    arquivo.close();
    return ataques;
}