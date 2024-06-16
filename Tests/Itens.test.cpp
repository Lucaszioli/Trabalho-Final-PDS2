#include "catch2.hpp"
#include "../HPPs/Cura.hpp"
#include "../HPPs/Estamina.hpp"
#include "../HPPs/Revive.hpp"
#include "../HPPs/Monstrinho.hpp"
#include "../ERR/CuraError.hpp"
#include "../ERR/ReviveError.hpp"
#include "../ERR/EstaminaError.hpp"
#include "../ERR/EscolhaError.hpp"
#include "../HPPs/Jogador.hpp"
#include "../ERR/BadRequestError.hpp"
#include <iostream>
#include <sstream>



TEST_CASE("Testando o recebimento da cura", "[Cura][Item][add]"){
    Cura c;
    srand(1);
    c.pegarItem();
    std::string raridade = c.getRaridade();

   if (raridade == "Pequena") {
        REQUIRE(c.getNome() == "Poção Pequena");
        REQUIRE(c.getDescricao() == "Cura até 25% da vida do seu monstrinho");
        REQUIRE(c.getCura() == 25);
    } else if (raridade == "Media") {
        REQUIRE(c.getNome() == "Poção Média");
        REQUIRE(c.getDescricao() == "Cura até 50% da vida do seu monstrinho");
        REQUIRE(c.getCura() == 50);
    } else if (raridade == "Grande") {
        REQUIRE(c.getNome() == "Poção Grande");
        REQUIRE(c.getDescricao() == "Cura até 75% da vida do seu monstrinho");
        REQUIRE(c.getCura() == 75);
    } else if (raridade == "Max"){
        REQUIRE(c.getNome() == "Poção Máxima");
        REQUIRE(c.getDescricao() == "Cura toda a vida do seu monstrinho");
        REQUIRE(c.getCura() == 100);
    }

    REQUIRE(c.getTipo() == "Cura");
}

TEST_CASE("Testando o recebimento da Estamina", "[Estamina][Item][add]"){
    Estamina e;
    srand(1);
    e.pegarItem();
    std::string raridade = e.getRaridade();

   if (raridade == "Pequena") {
        REQUIRE(e.getDescricao() == "Recupera 5 de estamina de um ataque");
        REQUIRE(e.getEnergia() == 5);
        REQUIRE(e.getNome() == "Estamina pequena");
    } else if (raridade == "Medio") {
        REQUIRE(e.getDescricao() == "Recupera 10 de estamina de um ataque");
        REQUIRE(e.getEnergia() == 10);
        REQUIRE(e.getNome() == "Estamina média");
    } else if (raridade == "Max") {
        REQUIRE(e.getDescricao() == "Recupera toda a estamina de um ataque");
        REQUIRE(e.getEnergia() == 100);
        REQUIRE(e.getNome() == "Max Estamina");
    }

    REQUIRE(e.getTipo() == "Estamina");
}

TEST_CASE("Testando o recebimento do Revive", "[Revive][Item][add]"){
    Revive r;
    srand(1);
    r.pegarItem();
    std::string raridade = r.getRaridade();
    if(raridade == "Max"){
        REQUIRE(r.getNome() == "Max Revive");
        REQUIRE(r.getDescricao() == "Revive seu monstrinho com a vida máxima");
    }else if(raridade == "Normal"){
        REQUIRE(r.getNome() == "Revive");
        REQUIRE(r.getDescricao() == "Revive seu monstrinho com 50% da vida dele");
    }

    REQUIRE(r.getTipo() == "Revive");
}

TEST_CASE("Testando o uso da Cura", "[Cura][Item][use]"){
    Cura c;
    vector<string> tipo = {"teste1","teste2"};
    vector<Ataque*> ataques = {};
    Monstrinho* m = new Monstrinho(1, "teste", "teste", tipo, 100 , 10, 10, 3, ataques);
    SECTION("Cura realizada com sucesso(Max)"){
        c.setCura(100);
        c.usarItem(m);
        REQUIRE(m->getHPAtual() == m->getHP());
    }
    SECTION("Cura realizada com sucesso(Grande)"){
        m->setHPAtual(10);
        c.setCura(75);
        c.usarItem(m);
        REQUIRE(m->getHPAtual() == 85);
    }
    SECTION("Cura realizada com sucesso(Media)"){
        m->setHPAtual(10);
        c.setCura(50);
        c.usarItem(m);
        REQUIRE(m->getHPAtual() == 60);
    }
    SECTION("Cura realizada com sucesso(Pequena)"){
        m->setHPAtual(10);
        c.setCura(25);
        c.usarItem(m);
        REQUIRE(m->getHPAtual() == 35);
    }
    SECTION("Monstro com a vida Maxima"){
        m->setHPAtual(m->getHP());
        REQUIRE_THROWS_MATCHES(c.usarItem(m), CuraError,Catch::Matchers::Message("O monstrinho já está com a vida máxima, escolha outro monstro"));
    }
    SECTION("Monstro morto"){
        m->setHPAtual(0);
        REQUIRE_THROWS_MATCHES(c.usarItem(m), CuraError, Catch::Matchers::Message("O monstrinho já está morto, use um Revive ou escolha outro monstro"));
    }
}

TEST_CASE("Testando o uso do Revive", "[Revive][Item][use]"){
    Revive r;
    vector<string> tipo = {"teste1","teste2"};
    vector<Ataque*> ataques = {};
    Monstrinho* m = new Monstrinho(1, "teste", "teste", tipo, 100 , 0, 10, 3, ataques);
    SECTION("Revive realizado com sucesso (Max)"){
        r.setRaridade("Max");
        m->setHPAtual(0);
        r.usarItem(m);
        REQUIRE(m->getHPAtual() == m->getHP());
    }
    SECTION("Revive realizado com sucesso (Normal)"){
        r.setRaridade("Normal");
        m->setHPAtual(0);
        r.usarItem(m);
        REQUIRE(m->getHPAtual() == m->getHP()/2);
    }
    SECTION("Monstrinho ainda vivo"){
        m->setHPAtual(10);
        REQUIRE_THROWS_MATCHES(r.usarItem(m),ReviveError,Catch::Matchers::Message("Monstrinho ainda vivo, selecione outro monstro"));
    }
}

TEST_CASE("Testando o uso da Estamina", "[Estamina][Item][use]"){
    Estamina e;
    vector<string> tipo = {"teste1","teste2"};
    Ataque* a = new Ataque(1, "teste", "teste", 10, "teste",50, 10);
    vector<Ataque*> ataques;
    ataques.push_back(a);
    Monstrinho* m = new Monstrinho(1, "teste", "teste", tipo, 100 , 100, 10, 3, ataques);


    SECTION("Uso da Estamina realizado com sucesso (Max)"){
        e.setEnergia(100);
        a->setQuantidadeAtual(10);
        std::streambuf* cinBackup = std::cin.rdbuf();
        std::stringstream fakeInput;
        fakeInput << 1; // Replace with your input
        std::cin.rdbuf(fakeInput.rdbuf());

        e.usarItem(m);
        std::cin.rdbuf(cinBackup);

        REQUIRE(a->getQuantidadeAtual() == a->getQuantidade());
    }
    SECTION("Uso da Estamina realizado com sucesso (Media)"){
        e.setEnergia(10);
        a->setQuantidadeAtual(10);
        std::streambuf* cinBackup = std::cin.rdbuf();
        std::stringstream fakeInput;
        fakeInput << 1; // Replace with your input
        std::cin.rdbuf(fakeInput.rdbuf());

        e.usarItem(m);
        std::cin.rdbuf(cinBackup);

        REQUIRE(a->getQuantidadeAtual() == 20);
    }
    SECTION("Uso da Estamina realizado com sucesso (Pequena)"){
        e.setEnergia(5);
        a->setQuantidadeAtual(10);
        std::streambuf* cinBackup = std::cin.rdbuf();
        std::stringstream fakeInput;
        fakeInput << 1; // Replace with your input
        std::cin.rdbuf(fakeInput.rdbuf());

        e.usarItem(m);
        std::cin.rdbuf(cinBackup);

        REQUIRE(a->getQuantidadeAtual() == 15);
    }
    SECTION("Usuario voltou"){
        std::streambuf* cinBackup = std::cin.rdbuf();
        std::stringstream fakeInput;
        fakeInput << 2; // Replace with your input
        std::cin.rdbuf(fakeInput.rdbuf());

        bool voltar = e.usarItem(m);
        std::cin.rdbuf(cinBackup);
        
        REQUIRE(voltar == 1);
    }
    SECTION("Monstro morto"){
        m->setHPAtual(0);
        REQUIRE_THROWS_MATCHES(e.usarItem(m),EstaminaError,Catch::Matchers::Message("O monstrinho já está morto, use um Revive ou escolha outro monstro"));
    }
}

TEST_CASE("Jogador recebeu o item","[Item][Jogador][add]"){
    Jogador j = Jogador(1, "teste",{});
    SECTION("Adicionou o item com sucesso"){
        j.receberItem();
        int tamanho = j.getInventario().size();
        REQUIRE(tamanho == 1);
    }
}

TEST_CASE("Jogador usa o item","[Item][Jogador][use]"){
    vector<string> tipo = {"teste1","teste2"};
    Ataque* a = new Ataque(1, "teste", "teste", 10, "teste",50, 10);
    vector<Ataque*> ataques;
    ataques.push_back(a);
    Monstrinho* m = new Monstrinho(1, "teste", "teste", tipo, 100 , 10, 10, 3, ataques);
    Jogador j = Jogador(1, "teste",{m});
    Item* c;
    SECTION("Jogador usa o item (Cura)"){
        c = new Cura();
        dynamic_cast<Cura*>(c)->setCura(100);
        c->setTipo("Cura");
        j.adicionarItem(c);
        std::streambuf* cinBackup = std::cin.rdbuf();
        std::stringstream fakeInput;
        fakeInput << "1 1"; // Replace with your input
        std::cin.rdbuf(fakeInput.rdbuf());

        bool usou = j.usarItem();
        std::cin.rdbuf(cinBackup);

        REQUIRE(m->getHPAtual() == m->getHP());
        REQUIRE(j.getInventario().size() == 0);
        REQUIRE(usou == 1);
    }
    SECTION("Jogador usa o item (Revive)"){
        c = new Revive();
        dynamic_cast<Revive*>(c)->setRaridade("Max");
        c->setTipo("Revive");
        m->setHPAtual(0);
        j.adicionarItem(c);
        std::streambuf* cinBackup = std::cin.rdbuf();
        std::stringstream fakeInput;
        fakeInput << "1 1"; // Replace with your input
        std::cin.rdbuf(fakeInput.rdbuf());

        bool usou = j.usarItem();
        std::cin.rdbuf(cinBackup);

        REQUIRE(m->getHPAtual() == m->getHP());
        REQUIRE(j.getInventario().size() == 0);
        REQUIRE(usou == 1);
    }
    SECTION("Jogador usa o item (Estamina)"){
        c = new Estamina();
        dynamic_cast<Estamina*>(c)->setEnergia(100);
        c->setTipo("Estamina");
        m->setHPAtual(100);
        a->setQuantidadeAtual(5);
        j.adicionarItem(c);
        std::streambuf* cinBackup = std::cin.rdbuf();
        std::stringstream fakeInput;
        fakeInput << "1 1 1"; // Replace with your input
        std::cin.rdbuf(fakeInput.rdbuf());

        bool usou = j.usarItem();
        std::cin.rdbuf(cinBackup);

        REQUIRE(a->getQuantidadeAtual() == a->getQuantidade());
        REQUIRE(j.getInventario().size() == 0);
        REQUIRE(usou == 1);
    }
    SECTION("O Jogador voltou"){
        j.adicionarItem(c);
        std::streambuf* cinBackup = std::cin.rdbuf();
        std::stringstream fakeInput;
        fakeInput << "2"; // Replace with your input
        std::cin.rdbuf(fakeInput.rdbuf());
        bool usou = j.usarItem();
        REQUIRE(usou == 0);
        REQUIRE(j.getInventario().size() == 1);
    }
    SECTION("Jogador voltou da estamina"){
        c = new Estamina();
        dynamic_cast<Estamina*>(c)->setEnergia(100);
        c->setTipo("Estamina");
        m->setHPAtual(100);
        a->setQuantidadeAtual(5);
        j.adicionarItem(c);
        std::streambuf* cinBackup = std::cin.rdbuf();
        std::stringstream fakeInput;
        fakeInput << "1 1 2 2 2"; // Replace with your input
        std::cin.rdbuf(fakeInput.rdbuf());

        bool usou = j.usarItem();
        std::cin.rdbuf(cinBackup);

        REQUIRE(j.getInventario().size() == 1);
        REQUIRE(usou == 0);
    }
    SECTION("Jogador não possui itens"){
           std::stringstream output;
    auto coutBackup = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    j.usarItem();

    std::cout.rdbuf(coutBackup);

    std::string errorMessage = output.str();
    errorMessage.erase(std::remove(errorMessage.begin(), errorMessage.end(), '\n'), errorMessage.end());
    REQUIRE(errorMessage == "Você não possui itens");
    }
}