#ifndef TREINADOR_HPP
#define TREINADOR_HPP

#include <string>
#include <vector>
#include "Monstrinho.hpp"

class Treinador
{
protected:
    int ID;
    vector<Monstrinho *> equipe;
    std::string nome;

public:
    Treinador(int ID, std::string nome, vector<Monstrinho *> equipe);
    int getID();
    std::string getNome();
    vector<Monstrinho *> getEquipe();
    bool verificaEquipe();
    virtual void mudaEquipe();
    void imprimeEquipe();
};

#endif