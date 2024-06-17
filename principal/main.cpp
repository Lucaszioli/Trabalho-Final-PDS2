#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "../HPPs/Jogo.hpp"
#include "../HPPs/Treinador.hpp"
#include "../HPPs/Jogador.hpp"
#include "../HPPs/Monstrinho.hpp"
#include "../HPPs/Ataque.hpp"
#include "../HPPs/Bot.hpp"
#include "../HPPs/Item.hpp"
#include "../HPPs/Cura.hpp"
#include "../HPPs/Revive.hpp"
#include "../HPPs/Estamina.hpp"

int main(){
    srand(static_cast<unsigned int>(time(0)));
    std::cout<<"Foi"<<std::endl;
    Jogo jogo;
    jogo.iniciar();
}