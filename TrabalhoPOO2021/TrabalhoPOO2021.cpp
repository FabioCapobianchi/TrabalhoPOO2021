
#include <cstdlib>
#include<string>
#include<sstream>
#include<iostream>
using namespace std;

#include "Territorio.h"
#include "Territ_inic.h"
#include "Mundo.h"
#include "Interaccao.h"
#include "utilis.h"

int main() {

    initRandom();
    int i = 1;
    int opcao = 0;
    int qut = 0;
    string cmdo,cmd1,tp;
    Mundo* mundo = new Mundo;
    Territ_Inic* empire = new Territ_Inic;

    Interaccao interaccao(mundo, empire);

    interaccao.inicio();
    //fase de comandos


    cout << "\n\n >>>> Introduza um Comando: \n";
    fseek(stdin, 0, SEEK_END);
    getline(cin, cmdo);
    istringstream iss(cmdo);
    iss >> cmd1;
    if (cmd1 == "modifica" || cmd1 == "sair") {
        if (cmd1 == "modifica") {
            iss >> tp >> qut;
            if (!iss) {
                cout << "\n !!!! Faltam parametros para o comando modifica !!!! \n";
                cout << "\n !!!! Exemplo modifica ouro 2 !!!! \n";

            }
            if (cmd1 == "modifica" && tp == "ouro") {
               // opcaoModificaOuro(qut);
                cout << "\n !!!! modifica ouro !!!!\n";
            }
            else if (cmd1 == "modifica" && tp == "prod") {
                //opcaoModificaProd(qut);
                cout << "\n !!!! modifica prod!!!!\n";
            }
            else
            {
                cout << "\n !!!! Não é possivel utilizar esse comando nessa fase ou foi mal digitado !!!!\n";

            }

        }
    }
    /*
    int opcaoModificaOuro(){

        if (imperio->getCofre() < imperio->getMaxcofre()) {
            imperio->setCofre(qut);
        }
    }
    
    int opcaoModificaProd(){
    
        if (imperio->getArmazem() < imperio->getMaxarmazem()) {
            imperio->setArmazem(qut);
        }
    }

    */

    do
    {
        i = interaccao.menu();
        if(i == 1)
        {
            i = interaccao.menuFrecolha(); 
        }
        if (i == 1)
        {
            i = interaccao.menuFrecolha();
        }
        if (i == 1)
        {
            i = interaccao.menuFcompra();
        }
        if (i == 1)
        {
            i = interaccao.menuFeventos();
        }

    } while (i == 1);


    delete mundo;
    delete empire;
    interaccao.fim();                  
}


