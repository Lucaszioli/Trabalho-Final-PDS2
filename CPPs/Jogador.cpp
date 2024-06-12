#include "../HPPs/Jogador.hpp"
#include <iostream>

Jogador::Jogador(int ID, string nome, vector<Monstrinho *> equipe)
    : Treinador(ID, nome, equipe) {}

void Jogador::imprimeEquipe()
{
    for (int i = 0; i < equipe.size(); i++)
    {
        cout << equipe[i]->getNome() << " vida: " << equipe[i]->getHP() << endl;
    }
}

void Jogador::mudaEquipe()
{
    if (verificaEquipe())
    {
        if (equipe[0]->getHP() <= 0)
        {
            cout << "O " << equipe[0]->getNome() << " foi derrotado!" << endl;
            equipe.push_back(equipe[0]);

            cout << "Escolha um monstrinho para substituir o que foi derrotado: " << endl;
            for (int i = 0; i < equipe.size(); i++)
            {
                if (equipe[i]->getHP() > 0)
                {
                    cout << i + 1 << ": " << equipe[i]->getNome() << endl;
                }
            }
            int escolha;
            cin >> escolha;
            equipe[0] = equipe[escolha - 1];
            equipe.erase(equipe.begin() + escolha - 1);
        }
    }
}