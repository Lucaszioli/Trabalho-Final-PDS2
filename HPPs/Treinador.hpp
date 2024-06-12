#include <string>
#include <vector>
#include "Monstrinho.hpp"

class Treinador
{
private:
    int ID;
    std::string nome;
    vector<Monstrinho *> equipe;
    std::string falas;

public:
    Treinador(int ID, std::string nome, vector<Monstrinho *> equipe, std::string falas);
    int getID();
    std::string getNome();
    vector<Monstrinho *> getEquipe();
    std::string getFalas();
    bool verificaEquipe();
};