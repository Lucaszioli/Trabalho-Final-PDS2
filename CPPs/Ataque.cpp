#include "../HPPs/Ataque.hpp"
#include "../HPPs/Monstrinho.hpp"
#include <fstream>
#include <sstream>
#include <exception>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <iostream>

unordered_map<string, unordered_map<string, double>> Ataque::TabelaEfetividade = Ataque::gerarTabelaEfetividade();

unordered_map<string, unordered_map<string, double>> Ataque::gerarTabelaEfetividade() {
    unordered_map<string, unordered_map<string, double>> tabela;

    tabela["Normal"]["Pedra"] = 0.5;
    tabela["Normal"]["Fantasma"] = 0.0;
    tabela["Lutador"]["Voador"] = 0.5;
    tabela["Lutador"]["Veneno"] = 0.5;
    tabela["Lutador"]["Psíquico"] = 0.5;
    tabela["Lutador"]["Inseto"] = 0.5;
    tabela["Lutador"]["Fantasma"] = 0.0;
    tabela["Lutador"]["Normal"] = 2.0;
    tabela["Lutador"]["Pedra"] = 2.0;
    tabela["Lutador"]["Gelo"] = 2.0;
    tabela["Voador"]["Pedra"] = 0.5;
    tabela["Voador"]["Aço"] = 0.5;
    tabela["Voador"]["Elétrico"] = 0.5;
    tabela["Voador"]["Grama"] = 2.0;
    tabela["Voador"]["Lutador"] = 2.0;
    tabela["Voador"]["Inseto"] = 2.0;
    tabela["Veneno"]["Fantasma"] = 0.5;
    tabela["Veneno"]["Terra"] = 0.5;
    tabela["Veneno"]["Pedra"] = 0.5;
    tabela["Veneno"]["Grama"] = 2.0;
    tabela["Veneno"]["Inseto"] = 2.0;
    tabela["Terra"]["Voador"] = 0.0;
    tabela["Terra"]["Inseto"] = 0.5;
    tabela["Terra"]["Grama"] = 0.5;
    tabela["Terra"]["Veneno"] = 2.0;
    tabela["Terra"]["Pedra"] = 2.0;
    tabela["Terra"]["Fogo"] = 2.0;
    tabela["Pedra"]["Lutador"] = 0.5;
    tabela["Pedra"]["Terra"] = 0.5;
    tabela["Pedra"]["Aço"] = 0.5;
    tabela["Pedra"]["Fogo"] = 2.0;
    tabela["Pedra"]["Gelo"] = 2.0;
    tabela["Pedra"]["Inseto"] = 2.0;
    tabela["Inseto"]["Lutador"] = 0.5;
    tabela["Inseto"]["Voador"] = 0.5;
    tabela["Inseto"]["Fantasma"] = 0.5;
    tabela["Inseto"]["Fogo"] = 0.5;
    tabela["Inseto"]["Grama"] = 2.0;
    tabela["Inseto"]["Psíquico"] = 2.0;
    tabela["Fantasma"]["Normal"] = 0.0;
    tabela["Fantasma"]["Psíquico"] = 0.0;
    tabela["Fantasma"]["Fantasma"] = 2.0;
    tabela["Fogo"]["Pedra"] = 0.5;
    tabela["Fogo"]["Fogo"] = 0.5;
    tabela["Fogo"]["Água"] = 0.5;
    tabela["Fogo"]["Dragão"] = 0.5;
    tabela["Fogo"]["Inseto"] = 2.0;
    tabela["Fogo"]["Grama"] = 2.0;
    tabela["Fogo"]["Gelo"] = 2.0;
    tabela["Água"]["Água"] = 0.5;
    tabela["Água"]["Dragão"] = 0.5;
    tabela["Água"]["Grama"] = 0.5;
    tabela["Água"]["Fogo"] = 2.0;
    tabela["Água"]["Terra"] = 2.0;
    tabela["Água"]["Pedra"] = 2.0;
    tabela["Grama"]["Grama"] = 0.5;
    tabela["Grama"]["Dragão"] = 0.5;
    tabela["Grama"]["Fogo"] = 0.5;
    tabela["Grama"]["Voador"] = 0.5;
    tabela["Grama"]["Inseto"] = 0.5;
    tabela["Grama"]["Água"] = 2.0;
    tabela["Grama"]["Terra"] = 2.0;
    tabela["Grama"]["Pedra"] = 2.0;
    tabela["Elétrico"]["Dragão"] = 0.5;
    tabela["Elétrico"]["Elétrico"] = 0.5;
    tabela["Elétrico"]["Grama"] = 0.5;
    tabela["Elétrico"]["Terra"] = 0.0;
    tabela["Elétrico"]["Água"] = 2.0;
    tabela["Elétrico"]["Voador"] = 2.0;
    tabela["Psíquico"]["Aço"] = 0.5;
    tabela["Psíquico"]["Psíquico"] = 0.5;
    tabela["Psíquico"]["Veneno"] = 2.0;
    tabela["Psíquico"]["Lutador"] = 2.0;
    tabela["Gelo"]["Fogo"] = 0.5;
    tabela["Gelo"]["Água"] = 0.5;
    tabela["Gelo"]["Aço"] = 0.5;
    tabela["Gelo"]["Gelo"] = 0.5;
    tabela["Gelo"]["Grama"] = 2.0;
    tabela["Gelo"]["Dragão"] = 2.0;
    tabela["Gelo"]["Voador"] = 2.0;
    tabela["Dragão"]["Aço"] = 0.5;
    tabela["Dragão"]["Dragão"] = 2.0;
    tabela["Aço"]["Fogo"] = 0.5;
    tabela["Aço"]["Água"] = 0.5;
    tabela["Aço"]["Elétrico"] = 0.5;
    tabela["Aço"]["Aço"] = 0.5;
    tabela["Aço"]["Gelo"] = 2.0;
    tabela["Aço"]["Pedra"] = 2.0;
    tabela["Sombrio"]["Lutador"] = 0.5;
    tabela["Sombrio"]["Psíquico"] = 2.0;
    tabela["Sombrio"]["Sombrio"] = 0.5;
    tabela["Sombrio"]["Fantasma"] = 2.0;
    tabela["Lutador"]["Sombrio"] = 2.0;
    tabela["Psíquico"]["Sombrio"] = 0.0;
    tabela["Sombrio"]["Sombrio"] = 0.5;
    tabela["Fantasma"]["Sombrio"] = 0.5;

    return tabela;
}

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

int Ataque::getQuantidadeAtual() {
    return quantidadeAtual;
}

void Ataque::setQuantidadeAtual(int valor) {
    if (valor < 0) {
        throw std::invalid_argument("Valor não pode ser negativo");
    } else if (valor > quantidade) {
        throw std::invalid_argument("Valor não pode ser maior que a quantidade total");
    } else {
        quantidadeAtual = valor;
    }
}

double Ataque::getChanceAcerto() {
    return chanceAcerto;
}

vector<Ataque> Ataque::construirAtaques() {
    vector<Ataque> ataques;
    ifstream arquivo("../CSVs/Ataques.csv");

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
        double chanceAcerto = stod(dados[6]);

        ataques.push_back(Ataque(ID, nome, tipo, dano, descricao, quantidade, chanceAcerto));
    }

        arquivo.close();
        return ataques;
    }

bool Ataque::fazerAtaque(Monstrinho &inimigo) {
    double chance = static_cast<double>(rand()) / RAND_MAX;

    if (chance <= chanceAcerto) {
        vector<string> tiposInimigo = inimigo.getTipo();
        cout << "Tipo do Ataque" << tipo << endl;
        for(auto& tipo:tiposInimigo){
            cout<<"Tipo Inimigo: "<<tipo<<" ";
        }
        cout<<endl;
        double multiplicador = calcularEfetividade(tipo, tiposInimigo);
            cout << getNome() << "!";
        cout << "Multiplicador" << multiplicador << endl;
        if (multiplicador > 1.0) {
            cout << " E foi super efetivo!" << endl;
        } 
        else if (multiplicador == 0.0) {
            cout << " " << inimigo.getNome() << " é imune a esse tipo de ataque!" << endl;
        }
        else if (multiplicador < 1.0) {
            cout << " mas foi pouco efetivo..." << endl;
        }
        else{
            cout << endl;
        }
        cout << dano << endl;
        int danoTotal = static_cast<int>(dano * multiplicador);
        int hpAtualInimigo = inimigo.getHPAtual();
        cout << endl;
        inimigo.setHPAtual(hpAtualInimigo - danoTotal);
        cout << inimigo.getNome() << " perdeu " << danoTotal << " de HP!" << endl;
        if (inimigo.getHPAtual() <= 0) {
            cout << "O " <<inimigo.getNome()<< " foi derrotado!" << endl;
            inimigo.setHPAtual(0);
        }
        quantidadeAtual--;
        return true;
    } else {
        cout << "O ataque errou!" << endl;
        quantidadeAtual--;
        return true;
    }
}

double Ataque::calcularEfetividade(string tipoAtaque, vector<string> tiposMonstrinho) {
    double multiplicador = 1.0;

    for (const auto& tipoMonstrinho : tiposMonstrinho) {
        if (TabelaEfetividade[tipoAtaque].find(tipoMonstrinho) != TabelaEfetividade[tipoAtaque].end()) {
            multiplicador *= TabelaEfetividade[tipoAtaque][tipoMonstrinho];
        }
    }

    return multiplicador;
}
