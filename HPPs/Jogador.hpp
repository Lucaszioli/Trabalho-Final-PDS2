#include <string>
#include <vector>
#include "Monstrinho.hpp"
#include "Treinador.hpp"
#include "Itens-hpp/Item.hpp"
using namespace std;

class Jogador : public Treinador {
private:
    // Adicione atributos específicos do Jogador aqui, se houver
    vector<Item> inventario;
public:
    // Adicione métodos específicos do Jogador aqui, se houver
    vector<Item> getInventario();
    void adicionarItem(Item* item);
    // Sobrescreva métodos de Treinador aqui, se necessário
};