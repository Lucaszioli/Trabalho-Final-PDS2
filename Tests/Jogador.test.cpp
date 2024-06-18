#include "catch2.hpp"
#include "../HPPs/Jogador.hpp"
#include "../HPPs/Monstrinho.hpp"
#include <iostream>
#include <sstream>

TEST_CASE("Muda equipe","[Jogador][Monstrinho][change][Equipe]"){
    vector<string> tipo = {"Veneno"};
    vector<Ataque> ataques;
    Monstrinho m2 = Monstrinho(2, "teste1", tipo, "teste", 100 , 100, 10, 3, {});
    Monstrinho m = Monstrinho(1, "teste", tipo, "teste", 100 , 100, 10, 3, {});
    SECTION("Mudança feita com sucesso"){
        Jogador j = Jogador(1, "teste", {&m,&m2});
        std::streambuf* cinBackup = std::cin.rdbuf();
        std::stringstream fakeInput;
        fakeInput << "2";
        std::cin.rdbuf(fakeInput.rdbuf());
        bool mudou = j.mudaEquipe();
        std::cin.rdbuf(cinBackup);
        REQUIRE(j.getEquipe()[0]->getNome() == "teste1");
        REQUIRE(mudou == true);
    }
    SECTION("Voltou"){
        Jogador j = Jogador(1, "teste", {&m,&m2});
        std::streambuf* cinBackup = std::cin.rdbuf();
        std::stringstream fakeInput;
        fakeInput << "3";
        std::cin.rdbuf(fakeInput.rdbuf());
        bool mudou = j.mudaEquipe();
        std::cin.rdbuf(cinBackup);
        REQUIRE(mudou == false);
        REQUIRE(j.getEquipe()[0]->getNome() == "teste");
    }
}