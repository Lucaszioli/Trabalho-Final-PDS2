#include <string>
#include <vector>
#include "Ataque.hpp"

using namespace std;


class Monstrinho {
private:
    int ID;
    string nome;
    string descricao;
    string tipo;
    int HP;
    int velocidade;
    vector<Ataque> ataques;

public:
    
        int getID();
        string getNome();
        string getDescricao();
        string getTipo();
        int getHP();
        void setHP(int hp);
        int getVelocidade();
        vector<Ataque> getAtaques();
    
        void atacar(/* parâmetros */);

    
};