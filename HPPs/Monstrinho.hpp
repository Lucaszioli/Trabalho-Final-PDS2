#ifndef MONSTRINHO_HPP
#define MONSTRINHO_HPP

#include <string>
#include <vector>
#include "Ataque.hpp"

using namespace std;
class Ataque; // Declaração antecipada da classe Ataque para evitar dependência circular.

/**
 * @class Monstrinho
 * 
 * @brief Classe que representa um monstrinho.
 * 
 * A classe Monstrinho representa um monstrinho com suas características, como ID, nome, descrição, tipo, HP, HP atual, velocidade e ataques.
 * Ela também possui métodos para acessar e modificar essas características.
 * Além disso, possui um método estático para construir uma lista de monstrinhos a partir de um arquivo CSV.
 */
class Monstrinho {
private:
    int ID; ///< O ID do monstrinho.
    string nome; ///< O nome do monstrinho.
    string descricao; ///< A descrição do monstrinho.
    vector<string> tipo; ///< O tipo do monstrinho.
    int HP; ///< A quantidade de HP do monstrinho.
    int HPAtual; ///< A quantidade de HP atual do monstrinho.
    int velocidade; ///< A velocidade do monstrinho. 
    int tier; ///< O tier do monstrinho (de 1 a 5).
    vector<Ataque> ataques; ///< Os ataques do monstrinho.

public:
    /**
     * @brief Construtor da classe Monstrinho.
     * 
     * @param ID O ID do monstrinho.
     * @param nome O nome do monstrinho.
     * @param descricao A descrição do monstrinho.
     * @param tipo O tipo do monstrinho.
     * @param HP A quantidade de HP do monstrinho.
     * @param HPAtual A quantidade de HP atual do monstrinho.
     * @param velocidade A velocidade do monstrinho.
     * 
     * @param ataques Os ataques do monstrinho.
     */
    Monstrinho(int ID, string nome, string descricao, vector<string> tipo, int HP, int HPAtual, int velocidade, int tier, vector<Ataque> ataques)
        : ID(ID), nome(nome), descricao(descricao), tipo(tipo), HP(HP), HPAtual(HPAtual), velocidade(velocidade), tier(tier), ataques(ataques) {}

    /**
     * @brief Obtém o ID do monstrinho.
     * 
     * @return O ID do monstrinho.
     */
    int getID();

    /**
     * @brief Obtém o nome do monstrinho.
     * 
     * @return O nome do monstrinho.
     */
    string getNome();

    /**
     * @brief Obtém a descrição do monstrinho.
     * 
     * @return A descrição do monstrinho.
     */
    string getDescricao();

    /**
     * @brief Obtém o tipo do monstrinho.
     * 
     * @return O tipo do monstrinho.
     */
    vector<string> getTipo();

    /**
     * @brief Obtém a quantidade de HP do monstrinho.
     * 
     * @return A quantidade de HP do monstrinho.
     */
    int getHP();

    /**
     * @brief Obtém a quantidade de HP atual do monstrinho.
     * 
     * @return A quantidade de HP atual do monstrinho.
     */
    int getHPAtual();

    /**
     * @brief Define a quantidade de HP atual do monstrinho.
     * 
     * @param HPAtual A quantidade de HP atual do monstrinho.
     */
    void setHPAtual(int HPAtual);

    /**
     * @brief Obtém a velocidade do monstrinho.
     * 
     * @return A velocidade do monstrinho.
     */
    int getVelocidade();

    /**
     * @brief Obtém o tier do monstrinho.
     * 
     * @return O tier do monstrinho.
     */
    int getTier();

    /**
     * @brief Obtém os ataques do monstrinho.
     * 
     * @return Os ataques do monstrinho.
     */
    vector<Ataque>& getAtaques();

    /**
     * @brief Ataca um monstrinho.
     * 
     * @param monstroAtacante O monstrinho que está atacando.
     * @param monstroAtacado O monstrinho que está sendo atacado.
     */
    void atacar(Monstrinho* monstroAtacante, Monstrinho* monstroAtacado);

    /**
     * @brief Constrói uma lista de monstrinhos a partir de um arquivo CSV.
     * 
     * @return Um vetor com todos os monstrinhos do arquivo CSV.
     */
    static vector<Monstrinho> construirMonstrinhos();
};

#endif