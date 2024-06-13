#ifndef ATAQUE_HPP
#define ATAQUE_HPP
/**
 * @file Ataque.hpp
 * @brief Definição da classe Ataque e seus métodos.
 */

#include <string>
#include <vector>

using namespace std;

/**
 * @class Ataque
 * @brief Representa um ataque em um jogo.
 * 
 * Cada ataque tem um ID, nome, tipo, dano, descrição e quantidade.
 */
class Ataque {
private:
    int ID; ///< O ID do ataque.
    string nome; ///< O nome do ataque.
    string tipo; ///< O tipo do ataque.
    int dano; ///< O dano causado pelo ataque.
    string descricao; ///< A descrição do ataque.
    int quantidade; ///< A quantidade de vezes que o ataque pode ser usado.
    
    double chanceAcerto; ///< A chance de acerto do ataque.

public:
    /**
     * @brief Constrói um novo objeto Ataque.
     * 
     * @param ID O ID do ataque.
     * @param nome O nome do ataque.
     * @param tipo O tipo do ataque.
     * @param dano O dano causado pelo ataque.
     * @param descricao A descrição do ataque.
     * @param quantidade A quantidade de vezes que o ataque pode ser usado.
     * @param chanceAcerto A chance de acerto do ataque.
     */
    Ataque(int ID, string nome, string tipo, int dano, string descricao, int quantidade, double chanceAcerto)
        : ID(ID), nome(nome), tipo(tipo), dano(dano), descricao(descricao), quantidade(quantidade), chanceAcerto(chanceAcerto) {}

    int getID(); ///< Retorna o ID do ataque.
    string getNome(); ///< Retorna o nome do ataque.
    string getTipo(); ///< Retorna o tipo do ataque.
    int getDano(); ///< Retorna o dano causado pelo ataque.
    string getDescricao(); ///< Retorna a descrição do ataque.
    int getQuantidade(); ///< Retorna a quantidade de vezes que o ataque pode ser usado.
    double getChanceAcerto(); ///< Retorna a chance de acerto do ataque.

    /**
     * @brief Constrói uma lista de ataques a partir de um arquivo CSV.
     * 
     * @return Um vetor com todos os ataques do arquivo CSV.
     */
    static vector<Ataque> construirAtaques();
    bool checarAcerto();
    // void causarDano(Monstrinho &inimigo);
};

#endif