#include <string>
#include <vector>
#include "Monstrinho.hpp"
#include "Treinador.hpp"

using std::vector;
using std::string;

class Jogo{
    public:
        void iniciar();
        Monstrinho proximoMonstrinho(vector<Monstrinho> equipe);
        int calculaVidaEquipe();
    private:
        int opcao;
        void iniciaTurno(Monstrinho monstrinho, vector<Monstrinho> equipe);
        void escolheAtaque();
        int geraCombate();
        void usarIten(Monstrinho monstrinho);

};