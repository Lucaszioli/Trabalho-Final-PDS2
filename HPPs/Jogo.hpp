#ifndef JOGO_HPP
#define JOGO_HPP

#include <string>
#include <vector>
#include "Monstrinho.hpp"
#include "Treinador.hpp"
#include "Jogador.hpp"
#include "Bot.hpp"

using std::vector;
using std::string;

class Jogo{
    public:
        void iniciar();
        void geraTurno(Jogador* jogador, Bot* bot);
        vector<Monstrinho*> escolherMonstrinho(Jogador* jogador);
        vector<Monstrinho*> criaEquipeBot(Bot* bot);
        int select();
        
};

#endif