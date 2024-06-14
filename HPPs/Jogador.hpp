#ifndef JOGADOR_HPP
#define JOGADOR_HPP
#include "Treinador.hpp"

/**
 * @brief Classe que representa um jogador no jogo.
 *
 * Esta classe herda da classe Treinador e representa um jogador no jogo.
 * Um jogador possui um ID, um nome e uma equipe de monstrinhos.
 */
class Jogador : public Treinador
{
private:
    // Implementar inventário
    vector<Item> inventario;
public:
    /**
     * @brief Construtor da classe Jogador.
     *
     * @param ID O ID do jogador.
     * @param nome O nome do jogador.
     * @param equipe A equipe de monstrinhos do jogador.
     */
    Jogador(int ID, string nome, vector<Monstrinho *> equipe);

    /**
     * @brief Função que permite ao jogador mudar sua equipe de monstrinhos.
     *
     * Esta função é uma sobrescrita da função mudaEquipe da classe Treinador.
     * Ela permite ao jogador mudar sua equipe de monstrinhos.
     */
    void mudaEquipe() override;
    /**
     * @brief Função que permite o jogador receber um item aleatório ao fim de uma rodada
     */
    void receberItem();

    /**
     * @brief Função que permiter pegar o inventario do Jogador
     */
    vector<Item*> getInventario();
    
    /**
     * @brief Adiciona um Item ao inventario do jogador
     * 
     * @param item Item adicionado no inventario
     */
    void adicionarItem(Item* item);

    void usarItem();
};

#endif