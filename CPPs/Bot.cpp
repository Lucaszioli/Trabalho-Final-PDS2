#include "../HPPs/Bot.hpp"
#include <iostream>

Bot::Bot(int ID, string nome, vector<Monstrinho *> equipe, vector<std::string> fala)
    : Treinador(ID, nome, equipe), fala(fala) {}

vector<std::string> Bot::getFala()
{
    return fala;
}

void Bot::mudaEquipe()
{
    if (verificaEquipe())
    {
        if (equipe[0]->getHP() <= 0)
        {
            equipe.push_back(equipe[0]);
            equipe.erase(equipe.begin());
        }
    }
}