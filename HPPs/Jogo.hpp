#ifndef JOGO_HPP
#define JOGO_HPP

#include <string>
#include <vector>
#include "Monstrinho.hpp"
#include "Treinador.hpp"
#include "Jogador.hpp"
#include "Bot.hpp"

using std::vector;
using std::string;
/**
 * @class Jogo
 * @file Jogo.hpp
 * @brief Classe que representa toda a lógica do jogo.
 * 
 * A classe cria as equipes de cada treinador e gera os turnos de batalha 
 * Em cada turno você pode escolher qual monstrinho atacar e qual ataque usar, bem como trocar de monstrinho e usar itens ganhos nas vitórias
 */
class Jogo{
    public:
        /**
         * @brief Função que inicia o jogo
         *
        */
        void iniciar();

        /**
         * @brief Função que gera um turno de batalha
         *
         * @param jogador Ponteiro para o jogador
         * @param bot Ponteiro para o bot
         * @return void
        */
        void geraTurno(Jogador* jogador, Bot* bot);
        
        /**
         * @brief Cria a equipe para o jogador
         *
         * @param jogador Ponteiro para o jogador
         * @return Retorna um vetor de ponteiros do tipo Monstrinho
        */
        vector<Monstrinho*> escolherMonstrinho(Jogador* jogador);
        
        /**
         * @brief Cria a equipe para o bot
         *
         * @param bot Ponteiro para o bot
         * @return Retorna um vetor de ponteiros do tipo Monstrinho
        */
        vector<Monstrinho*> criaEquipeBot(Bot* bot);
        
        
        
};

#endif