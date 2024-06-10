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
    // Métodos CRUD
    void criarMonstrinho(/* parâmetros */);
    void lerMonstrinho(/* parâmetros */);
    void atualizarMonstrinho(/* parâmetros */);
    void deletarMonstrinho(/* parâmetros */);

    // Adicione mais métodos conforme necessário
};