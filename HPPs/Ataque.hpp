#include <string>

using namespace std;

class Ataque {
private:
    int ID;
    string nome;
    string tipo;
    int dano;
    string descricao;
    string efeito;
    int quantidade;

public:
    // Métodos CRUD
    void criarAtaque(/* parâmetros */);
    void lerAtaque(/* parâmetros */);
    void atualizarAtaque(/* parâmetros */);
    void deletarAtaque(/* parâmetros */);

};