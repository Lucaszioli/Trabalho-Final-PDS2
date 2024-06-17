#include "catch2.hpp"
#include "../HPPs/Monstrinho.hpp"
#include "../HPPs/Ataque.hpp"
#include <iostream>
#include <sstream>
TEST_CASE("Testes para a classe Monstrinho", "[Monstrinho]") {
    vector<string> tipos = {"Fogo", "Água"};
    vector<Ataque> ataques;
    Monstrinho monstroTeste = Monstrinho(1, "Monstrinho Teste", "Descrição do Monstrinho", tipos, 100, 50, 10, 5, ataques);

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

    /*SECTION("Testando contruirMonstrinhos", "[Monstrinho]"){
        1- criar um csv teste

        vector<Monstrinho> monstrinhos = Monstrinho::construirMonstrinhos();
        REQUIRE(monstrinhos.size() > 0);
    }*/
    
    SECTION("Testando atacar", "[Monstrinho]") {
        vector<string> tipos = {"Fogo", "Água"};
        vector<Ataque> ataques;
        Monstrinho monstroAtacante(1, "Monstrinho Atacante", "Descrição do Monstrinho Atacante", tipos, 100, 50, 10, 5, ataques);
        Monstrinho monstroAtacado(2, "Monstrinho Atacado", "Descrição do Monstrinho Atacado", tipos, 100, 50, 10, 5, ataques);

        SECTION("Testando ataque válido", "[Monstrinho]") {
            std::streambuf* cinBackup = std::cin.rdbuf();
            std::stringstream fakeInput;
            fakeInput << 1; // Replace with your input
            std::cin.rdbuf(fakeInput.rdbuf());
            monstroAtacante.atacar(&monstroAtacante, &monstroAtacado);
            std::cin.rdbuf(cinBackup);
            REQUIRE(monstroAtacado.getHPAtual() < 100);
        }

        SECTION("Testando ataque inválido", "[Monstrinho]") {
            std::streambuf* cinBackup = std::cin.rdbuf();
            std::stringstream fakeInput;
            fakeInput << 10; // Replace with your input
            std::cin.rdbuf(fakeInput.rdbuf());
            monstroAtacante.atacar(&monstroAtacante, &monstroAtacado);
            std::cin.rdbuf(cinBackup);
            REQUIRE(monstroAtacado.getHPAtual() == 50);
        }
    }

    SECTION("Testando construtor com valores negativos", "[Monstrinho]") {
        vector<string> tipos = {"Fogo", "Água"};
        vector<Ataque> ataques;
        Monstrinho monstroTeste(-1, "Monstrinho Teste", "Descrição do Monstrinho", tipos, -100, -50, -10, -5, ataques);

        REQUIRE(monstroTeste.getID() == -1);
        REQUIRE(monstroTeste.getNome() == "Monstrinho Teste");
        REQUIRE(monstroTeste.getDescricao() == "Descrição do Monstrinho");
        REQUIRE(monstroTeste.getTipo() == tipos);
        REQUIRE(monstroTeste.getHP() == -100);
        REQUIRE(monstroTeste.getHPAtual() == -50);
        REQUIRE(monstroTeste.getVelocidade() == -10);
        REQUIRE(monstroTeste.getTier() == -5);
    }

    SECTION("Testando ataque com HP atual zero", "[Monstrinho]") {
        vector<string> tipos = {"Fogo", "Água"};
        vector<Ataque> ataques;
        Monstrinho monstroAtacante(1, "Monstrinho Atacante", "Descrição do Monstrinho Atacante", tipos, 100, 0, 10, 5, ataques);
        Monstrinho monstroAtacado(2, "Monstrinho Atacado", "Descrição do Monstrinho Atacado", tipos, 100, 50, 10, 5, ataques);
        std::streambuf* cinBackup = std::cin.rdbuf();
        std::stringstream fakeInput;
        fakeInput << 10; // Replace with your input
        std::cin.rdbuf(fakeInput.rdbuf());
        monstroAtacante.atacar(&monstroAtacante, &monstroAtacado);
        std::cin.rdbuf(cinBackup);
        REQUIRE(monstroAtacado.getHPAtual() == 50);
    }

    SECTION("Testando ataque com HP atual negativo", "[Monstrinho]") {
        vector<string> tipos = {"Fogo", "Água"};
        vector<Ataque> ataques;
        Monstrinho monstroAtacante(1, "Monstrinho Atacante", "Descrição do Monstrinho Atacante", tipos, 100, -50, 10, 5, ataques);
        Monstrinho monstroAtacado(2, "Monstrinho Atacado", "Descrição do Monstrinho Atacado", tipos, 100, 50, 10, 5, ataques);
        std::streambuf* cinBackup = std::cin.rdbuf();
        std::stringstream fakeInput;
        fakeInput << 10; // Replace with your input
        std::cin.rdbuf(fakeInput.rdbuf());
        monstroAtacante.atacar(&monstroAtacante, &monstroAtacado);
        std::cin.rdbuf(cinBackup);
        REQUIRE(monstroAtacado.getHPAtual() == 50);
    }
}