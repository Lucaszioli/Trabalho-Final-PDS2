#include "../HPPs/Treinador.hpp"
#include <algorithm>
#include <iostream>

Treinador::Treinador(int ID, std::string nome, std::vector<Monstrinho *> equipe, std::string falas)
    : ID(ID), nome(nome), equipe(equipe), falas(falas) {}

int Treinador::getID()
{
    return ID;
}

std::string Treinador::getNome()
{
    return nome;
}

std::vector<Monstrinho *> Treinador::getEquipe()
{
    for (Monstrinho *monstrinho : equipe)
    {
        std::cout << monstrinho->getNome() << " Vida: " << monstrinho->getHP() << std::endl;
    }

    return equipe;
}

std::string Treinador::getFalas()
{
    return falas;
}

bool Treinador::verificaEquipe()
{
    if (std::all_of(equipe.begin(), equipe.end(), [](Monstrinho *monstrinho)
                    { return monstrinho->getHP() == 0; }))
    {
        return false;
    }

    auto it = std::find_if(equipe.begin(), equipe.end(), [](Monstrinho *monstrinho)
                           { return monstrinho->getHP() == 0; });

    if (it != equipe.end())
    {
        std::rotate(equipe.begin(), it + 1, equipe.end());
        return true;
    }

    return true;
}
