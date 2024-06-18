#include "../HPPs/Estamina.hpp"
#include "../ERR/EstaminaError.hpp"
#include "../ERR/EscolhaError.hpp"
#include "../HPPs/Ataque.hpp"
#include <iostream>
#include <limits>

void Estamina::setEnergia(int e){
    energia = e;
}

int Estamina::getEnergia(){
    return energia;
}

void Estamina::pegarItem(){
    int dado = rand() % 100 + 1;
    setTipo("Estamina");
    if(dado>90 && dado<=100){
        setRaridade("Máx");
        setEnergia(100);
        setNome("Máx Estamina");
        setDescricao("Recupera toda a estamina de um ataque");
    }else if(dado>55 && dado<=90){
        setRaridade("Médio");
        setEnergia(10);
        setNome("Estamina média");
        setDescricao("Recupera 10 de estamina de um ataque");
    }else if(dado<=55 && dado>0){
        setRaridade("Pequena");
        setEnergia(5);
        setNome("Estamina pequena");
        setDescricao("Recupera 5 de estamina de um ataque");
    }
}

bool Estamina::usarItem(Monstrinho* monstro){
    bool erro = 0;
    do{
        try{
            if(monstro->getHPAtual() == 0){
                throw EstaminaError("O monstrinho já está morto, use um Revive ou escolha outro monstrinho");
            }
            vector<Ataque>& ataques = monstro -> getAtaques();
            int i = 1;
            int escolha;
            cout<<"--------------------------------------------------------------------------------"<<endl;
            for(auto& ataque:ataques){
                cout<<i<<"- "<<ataque.getNome()<<"Estamina: "<<ataque.getQuantidadeAtual()<<"/"<<ataque.getQuantidade()<<endl;
                i++;
            }
            cout<<i<<"- Voltar"<<endl;
            cout<<"Escolha um ataque para recuperar Estamina"<<endl;
            cout<<"--------------------------------------------------------------------------------"<<endl;
            cin>>escolha;
            if(escolha>i || escolha<1){
                throw EscolhaError("Escolha diferente do número possível de opções");
            }
            if(escolha == i){
                return true;
            }
            Ataque& ataqueRenovado = ataques[escolha-1];
            int atual = ataqueRenovado.getQuantidadeAtual();
            int maximo = ataqueRenovado.getQuantidade();
            if(maximo == atual){
                throw EscolhaError("O Ataque já apresenta estamina máxima");
            }
            int quantidade = getEnergia();
            int mudanca = quantidade + atual;
            if(mudanca > maximo){
                ataqueRenovado.setQuantidadeAtual(maximo);
            }else{
                ataqueRenovado.setQuantidadeAtual(mudanca);
            }
            int estaminaRestaurada = ataqueRenovado.getQuantidadeAtual() - atual;
            cout<<"--------------------------------------------------------------------------------"<<endl;
            cout << "A estamina do ataque "<< ataqueRenovado.getNome() <<" foi restaurada em " << estaminaRestaurada << " pontos" << endl;
            cout<<"--------------------------------------------------------------------------------"<<endl;
            erro = 0;
        }catch(EscolhaError& e){
            erro = 1;
            cout<<"--------------------------------------------------------------------------------"<<endl;  
            cout<<e.what()<<endl;
            cout<<"--------------------------------------------------------------------------------"<<endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            erro = 1;
        }
    }while(erro == 1);
    return false;
}