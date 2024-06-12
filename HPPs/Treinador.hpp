#include <string>
#include <vector>
#include "Monstrinho.hpp"

class Treinador
{
private:
    std::string falas;

protected:
    int ID;
    vector<Monstrinho *> equipe;
    std::string nome;

public:
    Treinador(int ID, std::string nome, vector<Monstrinho *> equipe, std::string falas);
    int getID();
    std::string getNome();
    vector<Monstrinho *> getEquipe();
    std::string getFalas();
    virtual bool verificaEquipe();
};