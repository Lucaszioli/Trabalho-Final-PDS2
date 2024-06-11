#include <string>
#include <vector>
#include "Monstrinho.hpp"

using namespace std;

class Treinador {
private:
    int ID;
    string nome;
    vector<Monstrinho> equipe;
    string falas;

public:

    int getID();
    string getNome();
    vector<Monstrinho> getEquipe();
    string getFalas();

    void trocarMonstrinho(/* parâmetros */);

};