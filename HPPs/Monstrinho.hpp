#ifndef MONSTRINHO_HPP
#define MONSTRINHO_HPP

#include <string>
#include <vector>
#include "Ataque.hpp"

using namespace std;

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
    string tipo; ///< O tipo do monstrinho.
    int HP; ///< A quantidade de HP do monstrinho.
    int HPAtual; ///< A quantidade de HP atual do monstrinho.
    int velocidade; ///< A velocidade do monstrinho. 
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
     * @param ataques Os ataques do monstrinho.
     */
    Monstrinho(int ID, string nome, string descricao, string tipo, int HP, int HPAtual, int velocidade, vector<Ataque> ataques)
        : ID(ID), nome(nome), descricao(descricao), tipo(tipo), HP(HP), HPAtual(HPAtual), velocidade(velocidade), ataques(ataques) {}

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
    string getTipo();

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
     * @brief Obtém os ataques do monstrinho.
     * 
     * @return Os ataques do monstrinho.
     */
    vector<Ataque> getAtaques();

    /**
     * @brief Constrói uma lista de monstrinhos a partir de um arquivo CSV.
     * 
     * @return Um vetor com todos os monstrinhos do arquivo CSV.
     */
    static vector<Monstrinho> construirMonstrinhos();
};

#endif