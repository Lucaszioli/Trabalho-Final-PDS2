#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "../HPPs/Jogo.hpp"
#include "../HPPs/Itens-hpp/Cura.hpp"
#include "../HPPs/Itens-hpp/Revive.hpp"
void Jogo::receberItem(Jogador* jogador){
    try{
        vector<Item> inventario = jogador->getInventario();
        srand(static_cast<unsigned int>(std::time(0)));
        int dado = (rand() % 100) + 1;
        Item* item;
        if(dado>60 && dado<=100){
            item = new Cura();
            item -> pegarItem();
        }else if(dado<=60 && dado>40){
            item = new Revive();
            item->pegarItem();
        }
        jogador->adicionarItem(item);
    }catch(){
        
    }
}

