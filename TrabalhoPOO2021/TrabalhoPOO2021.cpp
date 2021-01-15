
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
 
    do
    {
        i = interaccao.menu();
        if(i == 1)
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


