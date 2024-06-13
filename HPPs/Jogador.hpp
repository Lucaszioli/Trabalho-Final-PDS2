#ifndef JOGADOR_HPP
#define JOGADOR_HPP
#include "Treinador.hpp"

class Jogador : public Treinador
{
private:
    // Implementar inventário
public:
    Jogador(int ID, string nome, vector<Monstrinho *> equipe);
    void mudaEquipe() override;
};

#endif