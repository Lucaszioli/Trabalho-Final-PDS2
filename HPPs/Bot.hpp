#ifndef BOT_HPP
#define BOT_HPP

#include "Treinador.hpp"
#include <string>

class Bot : public Treinador
{
private:
    std::string fala;

public:
    Bot(int ID, std::string nome, vector<Monstrinho *> equipe, std::string fala);
    std::string getFala();
    void mudaEquipe() override;
};

#endif