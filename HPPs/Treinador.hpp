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
    // Métodos CRUD
    void criarTreinador(/* parâmetros */);
    void lerTreinador(/* parâmetros */);
    void atualizarTreinador(/* parâmetros */);
    void deletarTreinador(/* parâmetros */);

    // Método para trocar de monstrinho
    void trocarMonstrinho(/* parâmetros */);

    // Adicione mais métodos conforme necessário
};