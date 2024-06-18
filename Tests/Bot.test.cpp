#include "catch2.hpp"
#include "../HPPs/Bot.hpp"



TEST_CASE("Bot muda equipe","[Bot][Equipe][change]"){
    vector<string> tipo = {"Veneno"};
    Monstrinho* m = new Monstrinho(1, "teste", tipo, "teste", 100 , 100, 10, 3, {});
    Monstrinho* m2 = new Monstrinho(2, "teste1", tipo, "teste", 100 , 100, 10, 3, {});
    vector<Monstrinho*> equipe = {m,m2};
    Bot* bot = new Bot(2, "teste", equipe,{});
    SECTION("Bot muda equipe"){
        m->setHPAtual(0);
        bot->mudaEquipe();
        REQUIRE(bot->getEquipe()[0]->getID() == 2);
        REQUIRE(bot->getEquipe()[1]->getID() == 1);
    }
    SECTION("Bot não muda equipe"){
        m->setHPAtual(100);
        bot->mudaEquipe();
        REQUIRE(bot->getEquipe()[0]->getID() == 1);
        REQUIRE(bot->getEquipe()[1]->getID() == 2);
    }
}