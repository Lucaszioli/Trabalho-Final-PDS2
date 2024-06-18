#include "catch2.hpp"
#include "../HPPs/Monstrinho.hpp"
#include "../HPPs/Ataque.hpp"
#include <iostream>
#include <sstream>
TEST_CASE("Testes para a classe Monstrinho", "[Monstrinho]") {
    vector<string> tipos = {"Fogo", "Água"};
    vector<Ataque> ataques;
    Monstrinho monstroTeste = Monstrinho(1, "Monstrinho Teste",tipos, "Descrição do Monstrinho", 100, 50, 10, 5, ataques);

    SECTION("Testando getters", "[Monstrinho]") {
        REQUIRE(monstroTeste.getID() == 1);
        REQUIRE(monstroTeste.getNome() == "Monstrinho Teste");
        REQUIRE(monstroTeste.getDescricao() == "Descrição do Monstrinho");
        REQUIRE(monstroTeste.getTipo() == tipos);
        REQUIRE(monstroTeste.getHP() == 100);
        REQUIRE(monstroTeste.getHPAtual() == 50);
        REQUIRE(monstroTeste.getVelocidade() == 10);
        REQUIRE(monstroTeste.getTier() == 5);
    }

    SECTION("Testando setHPAtual", "[Monstrinho]") {
        monstroTeste.setHPAtual(80);
        REQUIRE(monstroTeste.getHPAtual() == 80);
    }
    
    SECTION("Testando atacar", "[Monstrinho]") {
        vector<string> tipos = {"Fogo", "Água"};
        vector<Ataque> ataques;
        ataques.push_back(Ataque(1, "Ataque 1", "Fogo", 10, "Descrição do Ataque 1", 10, 10));
        Monstrinho monstroAtacante= Monstrinho(1, "Monstrinho Atacante", tipos,"Descrição do Monstrinho Atacante",  100, 50, 10, 5, ataques);
        Monstrinho monstroAtacado = Monstrinho(2, "Monstrinho Atacado",tipos, "Descrição do Monstrinho Atacado",  100, 50, 10, 5, ataques);

        SECTION("Testando ataque válido", "[Monstrinho]") {
            monstroAtacante.atacar(&monstroAtacado, 0);
            REQUIRE(monstroAtacado.getHPAtual() < 100);
        }
    }

    SECTION("Testando construtor com valores negativos", "[Monstrinho]") {
        vector<string> tipos = {"Fogo", "Água"};
        vector<Ataque> ataques;
        Monstrinho monstroTeste = Monstrinho(-1, "Monstrinho Teste", tipos,"Descrição do Monstrinho",  -100, -50, -10, -5, ataques);

        REQUIRE(monstroTeste.getID() == -1);
        REQUIRE(monstroTeste.getNome() == "Monstrinho Teste");
        REQUIRE(monstroTeste.getDescricao() == "Descrição do Monstrinho");
        REQUIRE(monstroTeste.getTipo() == tipos);
        REQUIRE(monstroTeste.getHP() == -100);
        REQUIRE(monstroTeste.getHPAtual() == -50);
        REQUIRE(monstroTeste.getVelocidade() == -10);
        REQUIRE(monstroTeste.getTier() == -5);
    }
}

TEST_CASE("Testando escolha de ataques","[Monstrinho][Ataque][choice]"){
    vector<string> tipos = {"Fogo", "Água"};
    vector<Ataque> ataques;
    ataques.push_back(Ataque(1, "Ataque 1", "Fogo", 10, "Descrição do Ataque 1", 10, 10));
    ataques.push_back(Ataque(2, "Ataque 2", "Água", 10, "Descrição do Ataque 2", 0, 10));
    Monstrinho monstroTeste = Monstrinho(1, "Monstrinho Teste",tipos, "Descrição do Monstrinho", 100, 50, 10, 5, ataques);

    SECTION("Testando escolha de ataque válida") {
        std::stringstream input("1\n");
        std::streambuf* old = std::cin.rdbuf(input.rdbuf());
        int escolha = monstroTeste.escolhaAtaque();
        std::cin.rdbuf(old);
        REQUIRE(escolha == 0);
    }

    SECTION("Testando voltar"){
        std::stringstream input("3");
        std::streambuf* old = std::cin.rdbuf(input.rdbuf());
        int escolha = monstroTeste.escolhaAtaque();
        std::cin.rdbuf(old);
        REQUIRE(escolha == 2);
    }

    SECTION("Testando escolha de ataque inválida e depois valida") {
        
        std::streambuf* cinBackup = std::cin.rdbuf();
        std::stringstream fakeInput;
        fakeInput << "4\n\n1"; // Replace with your input
        std::cin.rdbuf(fakeInput.rdbuf());
        int escolha = monstroTeste.escolhaAtaque();
        std::cin.rdbuf(cinBackup);
        REQUIRE(escolha == 0);
    }
    SECTION("Testando escolha de ataque invalida por conta do numero de ataques") {
        std::stringstream input("2\n\n1\n");
        std::streambuf* old = std::cin.rdbuf(input.rdbuf());
        int escolha = monstroTeste.escolhaAtaque();
        std::cin.rdbuf(old);
        REQUIRE(escolha == 0);
    }
}