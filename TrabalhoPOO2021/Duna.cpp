#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <climits>
#include <stdlib.h>
#include<stdio.h>

#include "Duna.h"
#include "Mundo.h"

int Iddun = 1;
char unddun = '_';
string dun;

string Duna::criaNome() {
    string type = "duna";
    ostringstream ostr;
    ostr << Iddun;
    dun = ostr.str();

    type = type + unddun + dun;
    Iddun++;
    return type;
}

Duna::Duna(string tipo) : Territorio(criaNome(), 4, 1, 0, 1) {
}


Territorio * Duna::duplica()const {
    return new Duna(*this);
}


