#ifndef TREINADOR_HPP
#define TREINADOR_HPP

#include <string>
#include <vector>
#include "Monstrinho.hpp"

/**
 * @file Treinador.hpp
 * @brief Definição da classe Treinador e seus métodos.
 */

/**
 * @class Treinador
 *
 * @brief Classe que representa um treinador de monstrinhos.
 *
 * A classe Treinador possui um identificador, um nome e uma equipe de monstrinhos.
 * Ela fornece métodos para obter o identificador, o nome e a equipe do treinador,
 * verificar se a equipe está completa, mudar a equipe e imprimir a equipe.
 */
class Treinador
{
protected:
    int ID;                      /**< Identificador do treinador */
    vector<Monstrinho *> equipe; /**< Equipe de monstrinhos do treinador */
    std::string nome;            /**< Nome do treinador */

public:
    /**
     * @brief Construtor da classe Treinador.
     *
     * @param ID O identificador do treinador.
     * @param nome O nome do treinador.
     * @param equipe A equipe de monstrinhos do treinador.
     */
    Treinador(int ID, std::string nome, vector<Monstrinho *> equipe);

    /**
     * @brief Obtém o identificador do treinador.
     *
     * @return O identificador do treinador.
     */
    int getID();

    /**
     * @brief Obtém o nome do treinador.
     *
     * @return O nome do treinador.
     */
    std::string getNome();

    /**
     * @brief Obtém a equipe de monstrinhos do treinador.
     *
     * @return A equipe de monstrinhos do treinador.
     */
    vector<Monstrinho *> getEquipe();

    /**
     * @brief Verifica se a equipe de monstrinhos do treinador está completa.
     *
     * @return true se a equipe estiver completa, false caso contrário.
     */
    bool verificaEquipe();

    /**
     * @brief Método virtual para mudar a equipe de monstrinhos do treinador.
     *
     * Este método deve ser implementado nas classes derivadas.
     */
    virtual bool mudaEquipe() = 0;

    /**
     * @brief Imprime a equipe de monstrinhos do treinador.
     */
    void imprimeEquipe();
    
    /**
     * @brief Coloca um monstrinho na equipe do treinador.
     *
     * @param monstrinho O monstrinho a ser colocado na equipe.
     */
    void colocaMonstrinho(Monstrinho monstrinho);
};

#endif