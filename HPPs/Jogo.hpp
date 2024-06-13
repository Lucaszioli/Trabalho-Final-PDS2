#include <string>
#include <vector>
#include "Monstrinho.hpp"
#include "Treinador.hpp"
#include "Jogador.hpp"
using std::vector;
using std::string;

class Jogo{
    public:
        void iniciar();
        void turnoJogador(vector<Monstrinho> equipe);
        void turnoBot();
        void geraTurno();
        void escolherMonstrinho(vector<Monstrinho> time);
        Monstrinho proximoMonstrinho(vector<Monstrinho> equipe);
        void receberItem(Jogador* jogador);
        int calculaVidaEquipe();
        int opcao;
        
        

};