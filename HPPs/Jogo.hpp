#include <string>
#include <vector>
#include "Monstrinho.hpp"
#include "Treinador.hpp"

using std::vector;
using std::string;

class Jogo{
    public:
        void iniciar();
        void turnoJogador(Jogador &player);
        void turnoBot(Jogador &bot);
        void geraTurno(Jogador &player, Jogador &bot);
        void escolherMonstrinho(vector<Monstrinho> time);
};