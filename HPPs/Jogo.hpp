#include <string>
#include <vector>
#include "Monstrinho.hpp"
#include "Treinador.hpp"

using std::vector;
using std::string;

class Jogo{
    public:
        void iniciar();
        void geraTurno(Monstrinho &monstrinhoPlayer, Monstrinho &mosntrinhoBot);
        vector<Monstrinho> escolherMonstrinho(vector<Monstrinho> equipe);
};