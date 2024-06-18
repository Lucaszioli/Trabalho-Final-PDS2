#include "catch2.hpp"
#include "../HPPs/Treinador.hpp"
#include "../HPPs/Monstrinho.hpp"
#include "../HPPs/Ataque.hpp"
#include "../HPPs/Jogador.hpp"

TEST_CASE("Testando verificação de equipe","[Treinador][Equipe][verify]"){
    SECTION("Equipe válida"){
        vector<string> tipo = {"Veneno"};
        Monstrinho m = Monstrinho(1, "teste", tipo, "teste", 100 , 100, 10, 3, {});
        Treinador* t = new Jogador(1, "teste", {&m});
        REQUIRE(t->verificaEquipe() == true);
    }
    SECTION("Equipe inválida"){
        vector<string> tipo = {"Veneno"};
        Monstrinho m = Monstrinho(1, "teste", tipo, "teste", 100 , 100, 10, 3, {});
        m.setHPAtual(0);
        Treinador* t = new Jogador(1, "teste", {&m});
        REQUIRE(t->verificaEquipe() == false);
    }
}