#include "../HPPs/Jogador.hpp"
#include <iostream>

Jogador::Jogador(int ID, string nome, vector<Monstrinho *> equipe)
    : Treinador(ID, nome, equipe) {}

void Jogador::mudaEquipe()
{
    while (true)
    {
        if (verificaEquipe())
        {
            if (equipe[0]->getHP() <= 0)
            {
                cout << "O " << equipe[0]->getNome() << " foi derrotado!" << endl;
                cout << "Escolha um monstrinho para substituir o que foi derrotado: " << endl;
            }
            else
            {
                cout << "Escolha outro monstrinho: " << endl;
            }
            imprimeEquipe();
            int escolha;
            cin >> escolha;
            if (escolha < 1 || escolha > equipe.size())
            {
                cout << "Escolha inválida!" << endl;
                continue;
            }
            if (equipe[escolha - 1]->getHP() <= 0)
            {
                cout << "Esse monstrinho está desmaiado!" << endl;
                continue;
            }
            if (equipe[escolha - 1] == equipe[0] && equipe[0]->getHP() > 0)
            {
                cout << "Esse monstrinho já está em batalha!" << endl;
                continue;
            }
            if (escolha >= 1 && escolha <= equipe.size() && equipe[escolha - 1]->getHP() > 0 && equipe[escolha - 1] != equipe[0])
            {
                equipe.push_back(equipe[0]);
                equipe[0] = equipe[escolha - 1];
                equipe.erase(equipe.begin() + escolha - 1);
                std::cout << "Agora o Montrinho: " << equipe[0]->getNome() << " está em batalha!" << std::endl;
                break;
            }
        }
    }
}