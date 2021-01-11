
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
    Mundo* mundo = new Mundo;
    Territ_Inic* empire = new Territ_Inic;

    cout << "\n             ====================="
         << "\n             ==    Bem Vindo    =="
         << "\n             ==       ao        =="
         << "\n             ==     IMPERIO     =="
         << "\n             =====================\n";


    Interaccao interaccao(mundo, empire);
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
    cout << "aqui";
}


