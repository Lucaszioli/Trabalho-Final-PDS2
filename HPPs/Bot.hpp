#ifndef BOT_HPP
#define BOT_HPP

#include "Treinador.hpp"
#include <string>

/**
 * @class Bot
 * @brief Representa um Bot em um jogo.
 *
 * A classe Bot é uma classe derivada da classe Treinador e representa um Bot em um jogo.
 * Ela contém informações sobre o ID do Bot, nome, equipe de objetos Monstrinho e discurso.
 */
class Bot : public Treinador
{
private:
    vector<std::string> fala; /**< O discurso do Bot. */

public:
    /**
     * @brief Constrói um novo objeto Bot.
     *
     * @param ID O ID do Bot.
     * @param nome O nome do Bot.
     * @param equipe A equipe de objetos Monstrinho.
     * @param fala O discurso do Bot.
     */
    Bot(int ID, std::string nome, vector<Monstrinho *> equipe, vector<std::string> fala);

    /**
     * @brief Obtém o discurso do Bot.
     *
     * @return O discurso do Bot.
     */
    vector<std::string> getFala();

    /**
     * @brief Altera a equipe de objetos Monstrinho.
     *
     * Esta função substitui a função mudaEquipe() da classe base.
     */
    void mudaEquipe() override;
};
;

#endif