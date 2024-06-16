#include <string>
#include <vector>
#include "Monstrinho.hpp"
#include "Treinador.hpp"

using std::vector;
using std::string;

class Jogo{
    public:
        void iniciar();
        void geraTurno(Jogador* jogador, Bot* bot, vector<Monstrinho*> monstroJogador, vector<Monstrinho*> monstroBot);
        vector<Monstrinho*> escolherMonstrinho();
        vector<Monstrinho*> criaEquipeBot();
        
};