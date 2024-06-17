#include "catch2.hpp"
#include "../HPPs/Ataque.hpp"
#include "../HPPs/Monstrinho.hpp"

TEST_CASE("Testando fazer os ataques","[Ataque][use]"){
    vector<string> tipo = {"Veneno"};
    vector<Ataque> ataques;
    Ataque a = Ataque(1, "teste", "Psíquico", 10 ,"teste", 10, 10);
    Ataque b = Ataque(1, "teste", "Lutador", 10 ,"teste", 10, 10);
    Monstrinho* m = new Monstrinho(1, "teste", "teste", tipo, 100 , 100, 10, 3, {});
    SECTION("Ataque funciona (2x)"){
        bool retorno = a.fazerAtaque(m[0]);
        REQUIRE(retorno == true);
        REQUIRE(m->getHPAtual() == m->getHP()-20);
        REQUIRE(a.getQuantidadeAtual() == a.getQuantidade()-1);
    }
    SECTION("Ataque Funciona (.5x)"){
        bool retorno = b.fazerAtaque(m[0]);
        REQUIRE(retorno == true);
        REQUIRE(m->getHPAtual() == m->getHP()-5);
        REQUIRE(b.getQuantidadeAtual() == b.getQuantidade()-1);
    }
    SECTION("Ataque Imune"){
        Monstrinho* m = new Monstrinho(1, "teste", "teste", {"Fantasma"}, 100 , 100, 10, 3, {});
        b.setQuantidadeAtual(b.getQuantidade());
        bool retorno = b.fazerAtaque(m[0]);
        REQUIRE(retorno == true);
        REQUIRE(m->getHPAtual() == m->getHP());
        REQUIRE(b.getQuantidadeAtual() == b.getQuantidade()-1);
    }
    SECTION("Ataque falhou"){
        Ataque c = Ataque(1, "teste", "Psíquico", 10,"teste", 10, 0);
        m->setHPAtual(m->getHP());
        bool retorno = c.fazerAtaque(m[0]);
        REQUIRE(retorno == true);
        REQUIRE(m->getHPAtual() == m->getHP());
        REQUIRE(c.getQuantidadeAtual() == c.getQuantidade()-1);
    }

    SECTION("Ataque esgotado"){
        a.setQuantidadeAtual(0);
        bool retorno = a.fazerAtaque(m[0]);
        REQUIRE(retorno == false);
    }
}