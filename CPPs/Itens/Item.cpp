#include "../../HPPs/Itens-hpp/Item.hpp"
#include "../../HPPs/Itens-hpp/Cura.hpp"
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
