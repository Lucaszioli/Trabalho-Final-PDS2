#ifndef ATAQUE_HPP
#define ATAQUE_HPP

#include <vector>
#include <unordered_map>
#include "Monstrinho.hpp"

using namespace std;
/**
 * @file Ataque.hpp
 * @brief Definição da classe Ataque e seus métodos.
 */

class Monstrinho; // Declaração antecipada da classe Monstrinho para evitar dependência circular

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
    int quantidadeAtual; ///< A quantidade atual de vezes que o ataque pode ser usado.
    double chanceAcerto; ///< A chance de acerto do ataque.
    static unordered_map<string, unordered_map<string, double>> TabelaEfetividade; ///< A tabela de efetividade dos tipos de ataques.
    static unordered_map<string, unordered_map<string, double>> gerarTabelaEfetividade(); ///< Gera a tabela de efetividade dos tipos de ataques.


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
        : ID(ID), nome(nome), tipo(tipo), dano(dano), descricao(descricao), quantidade(quantidade), quantidadeAtual(quantidade), chanceAcerto(chanceAcerto) {}

    /**
     * @brief Retorna o ID do ataque.
     * 
     * @return int O ID do ataque.
     */
    int getID();

    /**
     * @brief Retorna o nome do ataque.
     * 
     * @return string O nome do ataque.
     */
    string getNome();

    /**
     * @brief Retorna o tipo do ataque.
     * 
     * @return string O tipo do ataque.
     */
    string getTipo();

    /**
     * @brief Retorna o dano causado pelo ataque.
     * 
     * @return int O dano causado pelo ataque.
     */
    int getDano();

    /**
     * @brief Retorna a descrição do ataque.
     * 
     * @return string A descrição do ataque.
     */
    string getDescricao();

    /**
     * @brief Retorna a quantidade máxima de vezes que o ataque pode ser usado.
     * 
     * @return int A quantidade de vezes que o ataque pode ser usado.
     */
    int getQuantidade();

    /**
     * @brief Retorna a quantidade atual de vezes que o ataque pode ser usado.
     * 
     * @return int A quantidade atual de vezes que o ataque pode ser usado.
     */
    int getQuantidadeAtual();

    /**
     * @brief Define a quantidade atual de vezes que o ataque pode ser usado.
     * 
     * @param valor A nova quantidade atual de vezes que o ataque pode ser usado.
     */
    void setQuantidadeAtual(int valor);
    /**
     * @brief Retorna a chance de acerto do ataque.
     * 
     * @return double A chance de acerto do ataque.
     */
    double getChanceAcerto();

    /**
     * @brief Constrói uma lista de ataques a partir de um arquivo CSV.
     * 
     * @return vector<Ataque> Um vetor com todos os ataques do arquivo CSV.
     */
    static vector<Ataque> construirAtaques();

    /**
     * @brief Realiza um ataque em um monstrinho.
     * 
     * @param inimigo O monstrinho que será atacado.
     * @return bool true se o monstrinho conseguiu realizar o ataque, false caso contrário.
     */
    bool fazerAtaque(Monstrinho &inimigo);

    /**
     * @brief Calcula a efetividade de um ataque.
     * 
     * @param tipoAtaque O tipo do ataque.
     * @param tiposMonstrinho Os tipos do monstrinho que será atacado.
     * @return double A efetividade do ataque.
     */
    static double calcularEfetividade(string tipoAtaque, vector<string> tiposMonstrinho);
};


#endif