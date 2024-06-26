#include "../HPPs/Treinador.hpp"
#include <algorithm>
#include <iostream>

Treinador ::Treinador(int ID, string nome, vector<Monstrinho *> equipe)
    : ID(ID), nome(nome), equipe(equipe) {}

int Treinador::getID()
{
    return ID;
}

string Treinador::getNome()
{
    return nome;
}

vector<Monstrinho *> Treinador::getEquipe()
{
    return equipe;
}

bool Treinador::verificaEquipe()
{
    return count_if(equipe.begin(), equipe.end(), [](Monstrinho *monstrinho)
                    { return monstrinho->getHPAtual() > 0; }) > 0;
}

void Treinador::imprimeEquipe()
{
    for (int i = 0; i < equipe.size(); i++)
    {
        cout << i + 1 << " - " << equipe[i]->getNome() << " | Vida: " << equipe[i]->getHPAtual() << "/" << equipe[i]->getHP()<< endl;
    }
}

void Treinador :: colocaMonstrinho(Monstrinho monstrinho){
    equipe.push_back(new Monstrinho(monstrinho));
}