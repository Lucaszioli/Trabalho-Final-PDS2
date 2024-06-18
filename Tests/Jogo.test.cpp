#include "catch2.hpp"
#include "../HPPs/Jogo.hpp"
#include "../HPPs/Cura.hpp"
#include <sstream>
#include <iostream>

TEST_CASE("Testando a geração de turno","[Jogo][Turno][create]"){
    Jogo j;
    SECTION("Jogador ataca primeiro"){
        Ataque a = Ataque(1, "teste", "Psíquico", 10000 ,"teste", 10, 1000);
        vector<string> tipo = {"Veneno"};
        Monstrinho* m = new Monstrinho(1, "teste", tipo, "teste", 100 , 100, 1000, 3, {a});
        Monstrinho* m2 = new Monstrinho(2, "teste1", tipo, "teste", 100 , 100, 10, 3, {a});
        vector<Monstrinho*> equipe2 = {m2};
        vector<Monstrinho*> equipe = {m};
        Jogador* jogador = new Jogador(1, "teste", equipe);
        Bot* bot = new Bot(2, "teste", equipe2,{});
        std::streambuf* cinBackup = std::cin.rdbuf();
        std::stringstream fakeInput;
        fakeInput << "1 1 1 \n";
        std::cin.rdbuf(fakeInput.rdbuf());
        j.geraTurno(jogador, bot);
        std::cin.rdbuf(cinBackup);
        REQUIRE(m2->getHPAtual() == 0);
        REQUIRE(m->getHPAtual() == 100);
    }
    SECTION("Bot ataca primeiro"){
        Ataque a = Ataque(1, "teste", "Psíquico", 10000 ,"teste", 10, 1000);
        Monstrinho* m = new Monstrinho(1, "teste", {"Veneno"}, "teste", 100 , 100, 1000, 3, {a,a,a,a});
        Monstrinho* m2 = new Monstrinho(2, "teste1", {"Veneno"}, "teste", 100 , 100, 10, 3, {a,a,a,a});
        vector<Monstrinho*> equipe2 = {m2};
        vector<Monstrinho*> equipe = {m};
        Jogador* jogador = new Jogador(1, "teste", equipe2);
        Bot* bot = new Bot(2, "teste", equipe,{});
        std::streambuf* cinBackup = std::cin.rdbuf();
        std::stringstream fakeInput;
        fakeInput << "1 1 1 \n";
        std::cin.rdbuf(fakeInput.rdbuf());
        j.geraTurno(jogador, bot);
        std::cin.rdbuf(cinBackup);
        REQUIRE(m2->getHPAtual() == 0);
        REQUIRE(m->getHPAtual() == 100);
    }
    SECTION("Jogador Escolhe um item"){
        Ataque a = Ataque(1, "teste", "Psíquico", 10000 ,"teste", 10, 1000);
        
        Monstrinho* m = new Monstrinho(1, "teste", {"Veneno"}, "teste", 100 , 100, 1000, 3, {a,a,a,a});
        Monstrinho* m2 = new Monstrinho(2, "teste1", {"Veneno"}, "teste", 100 , 10, 100, 3, {a,a,a,a});
        vector<Monstrinho*> equipe2 = {m2};
        vector<Monstrinho*> equipe = {m};
        Jogador* jogador = new Jogador(1, "teste", equipe2);
        m2->getAtaques()[0].setQuantidadeAtual(0);
        jogador->receberItem();
        if(jogador->getInventario()[0]->getNome() == "Revive"){
            m2->setHPAtual(0);
        }
        Bot* bot = new Bot(2, "teste", equipe,{});
        std::streambuf* cinBackup = std::cin.rdbuf();
        std::stringstream fakeInput;
        fakeInput << "3 1 1 \n";
        std::cin.rdbuf(fakeInput.rdbuf());
        j.geraTurno(jogador, bot);
        std::cin.rdbuf(cinBackup);
        REQUIRE(m2->getHPAtual() == 0);
        REQUIRE(m->getHPAtual() == 100);
    }
}