#include "../HPPs/Jogador.hpp"
#include <limits>
#include <iostream>
#include "../HPPs/Cura.hpp"
#include "../HPPs/Revive.hpp"
#include "../HPPs/Estamina.hpp"
#include "../ERR/BadRequestError.hpp"
#include "../ERR/EscolhaError.hpp"
#include "../ERR/ItemError.hpp"
#include "../ERR/ReviveError.hpp"
#include <ctime>
#include <cstdlib>

Jogador::Jogador(int ID, string nome, vector<Monstrinho *> equipe)
    : Treinador(ID, nome, equipe) {}

bool Jogador::mudaEquipe()
{
    while (true)
    {
        try
        {
            if (verificaEquipe())
            {
                cout << "--------------------------------------------------------------------------------" << endl;
                if (equipe[0]->getHPAtual() <= 0)
                {
                    cout << "Escolha um monstrinho para substituir o que foi derrotado: " << endl;
                    imprimeEquipe();
                }
                else
                {
                    cout << "Escolha outro monstrinho: " << endl;
                    imprimeEquipe();
                    cout << equipe.size() + 1 << " - Voltar" << endl;
                }
                cout << "--------------------------------------------------------------------------------" << endl;
                int escolha;
                cin >> escolha;
                if (std::cin.fail())
                {                     // Se a entrada falhar (por exemplo, o usuário digitou uma string)
                    std::cin.clear(); // Limpa o estado de falha
                    throw EscolhaError("Escolha diferente do número possível de opções");
                }
                if (escolha == equipe.size() + 1 && equipe[0]->getHPAtual() > 0)
                {
                    return false;
                }
                if (escolha < 1 || escolha > equipe.size())
                {
                    cout << "Escolha inválida!" << endl;
                    continue;
                }
                if (equipe[escolha - 1]->getHPAtual() <= 0)
                {
                    cout << "Esse monstrinho está desmaiado!" << endl;
                    continue;
                }
                if (equipe[escolha - 1] == equipe[0] && equipe[0]->getHPAtual() > 0)
                {
                    cout << "Esse monstrinho já está em batalha!" << endl;
                    continue;
                }
                if (escolha >= 1 && escolha <= equipe.size() && equipe[escolha - 1]->getHPAtual() > 0 && equipe[escolha - 1] != equipe[0])
                {
                    equipe.push_back(equipe[0]);
                    equipe[0] = equipe[escolha - 1];
                    equipe.erase(equipe.begin() + escolha - 1);
                    std::cout << "Agora o Monstrinho: " << equipe[0]->getNome() << " está em batalha!" << std::endl;
                    break;
                }
            }
            else
            {
                break;
            }
        }
        catch (EscolhaError &e)
        {
            cout << "--------------------------------------------------------------------------------" << endl;
            cout << e.what() << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }
    }
    return true;
}

void Jogador::receberItem()
{
    bool erro = 0;
    do
    {
        try
        {
            vector<Item *> inventario = getInventario();
            int dado = (rand() % 100) + 1;
            Item *item;
            if (dado > 60 && dado <= 100)
            {
                item = new Cura();
                item->pegarItem();
            }
            else if (dado <= 60 && dado > 40)
            {
                item = new Revive();
                item->pegarItem();
            }
            else if (dado <= 40 && dado > 0)
            {
                item = new Estamina();
                item->pegarItem();
            }
            adicionarItem(item);
            cout << "Você recebeu: " << item->getNome() << " - " << item->getDescricao() << endl;
            ;
            erro = 0;
        }
        catch (const std::exception &e)
        {
            erro = 1;
        }
    } while (erro == 1);
}

bool Jogador::usarItem()
{
    bool erro = 0;
    bool usou = false;
    do
    {
        try
        {

            vector<Item *> inventario = getInventario();
            int i = 1;
            if (inventario.size() == 0)
            {
                throw BadRequestError("Você não possui itens");
            }
            cout << "--------------------------------------------------------------------------------" << endl;
            for (auto &item : inventario)
            {
                cout << i << "- " << item->getNome() << endl;
                i++;
            }
            cout << i << "- Voltar" << endl;
            int escolhaItem;
            cout << "Qual item você quer usar?" << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
            cin >> escolhaItem;
            if (std::cin.fail())
            {                     // Se a entrada falhar (por exemplo, o usuário digitou uma string)
                std::cin.clear(); // Limpa o estado de falha
                throw EscolhaError("Escolha diferente do número possível de opções");
            }
            if (escolhaItem > i || escolhaItem < 1)
            {
                throw EscolhaError("Escolha diferente do número possível de opções");
            }
            if (escolhaItem != i)
            {
                Item *item = inventario[escolhaItem - 1];

                string tipo = item->getTipo();
                vector<Monstrinho *> equipe = getEquipe();
                bool voltar = 0;
                do
                {
                    int j = 1;
                    int escolhaMonstro;
                    cout << "--------------------------------------------------------------------------------" << endl;
                    for (auto &monstro : equipe)
                    {
                        cout << j << "- " << monstro->getNome() << " HP:" << monstro->getHPAtual() << "/" << monstro->getHP() << endl;
                        j++;
                    }
                    cout << j << "- Voltar" << endl;
                    cout << "Em qual monstro você deseja usar o item?" << endl;
                    cout << "--------------------------------------------------------------------------------" << endl;
                    cin >> escolhaMonstro;
                    if (std::cin.fail())
                    {                     // Se a entrada falhar (por exemplo, o usuário digitou uma string)
                        std::cin.clear(); // Limpa o estado de falha
                        throw EscolhaError("Escolha diferente do número possível de opções");
                    }
                    if (escolhaMonstro > j || escolhaMonstro < 1)
                    {
                        throw EscolhaError("Escolha diferente do numero possível de opções");
                    }
                    if (escolhaMonstro != j)
                    {
                        if (tipo == "Cura")
                        {
                            Monstrinho *monstro = equipe[escolhaMonstro - 1];
                            voltar = dynamic_cast<Cura *>(item)->usarItem(monstro);
                        }
                        else if (tipo == "Revive")
                        {
                            Monstrinho *monstro = equipe[escolhaMonstro - 1];
                            voltar = dynamic_cast<Revive *>(item)->usarItem(monstro);
                        }
                        else if (tipo == "Estamina")
                        {
                            Monstrinho *monstro = equipe[escolhaMonstro - 1];
                            voltar = dynamic_cast<Estamina *>(item)->usarItem(monstro);
                        }
                        if (voltar == false)
                        {
                            removerItem(escolhaItem - 1);
                        }
                    }
                    if (escolhaMonstro == j)
                    {
                        voltar = 0;
                        erro = 1;
                        continue;
                    }
                    erro = 0;
                    usou = true;
                } while (voltar == 1);
            }
            else if (escolhaItem == i)
            {
                erro = 0;
                usou = false;
                continue;
            }
        }
        catch (const BadRequestError &e)
        {
            cout << "--------------------------------------------------------------------------------" << endl;
            cout << e.what() << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            erro = 0;
            usou = false;
        }
        catch (const EscolhaError &e)
        {
            cout << "--------------------------------------------------------------------------------" << endl;
            cout << e.what() << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            erro = 1;
        }
        catch (const ItemError &e)
        {
            cout << "--------------------------------------------------------------------------------" << endl;
            cout << e.what() << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            erro = 1;
        }
        catch (const std::exception &e)
        {
            cout << "--------------------------------------------------------------------------------" << endl;
            cout << e.what() << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            erro = 1;
        }
    } while (erro == 1);
    return usou;
}

void Jogador::adicionarItem(Item *item)
{
    inventario.push_back(item);
}

void Jogador::removerItem(int item)
{
    inventario.erase(inventario.begin() + item);
}

vector<Item *> Jogador::getInventario()
{
    return inventario;
}
