#include "../HPPs/Item.hpp"
#include <stdexcept>
#include <cstdlib>
#include <ctime>

string Item::getDescricao(){
    return descricao;
}

string Item::getNome(){
    return nome;
}

void Item::setDescricao(string d){
    descricao = d;
}

void Item::setNome(string n){
    nome = n;
}

void Item::setTipo(string t){
    tipo = t;
}

string Item::getTipo(){
    return tipo;
}

string Item::getRaridade(){
    return raridade;
}

void Item::setRaridade(string r){
    raridade = r;
}
