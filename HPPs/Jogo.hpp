#include <string>
#include <vector>
#include "Monstrinho.hpp"
#include "Treinador.hpp"

using std::vector;
using std::string;

class Jogo{
    public:
        void iniciar();
        void geraTurno(Jogador &jogador, Bot &bot, Monstrinho &monstroJogador, Monstrinho &monstroBot);
        vector<Monstrinho> escolherMonstrinho();
        
};