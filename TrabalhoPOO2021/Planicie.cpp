

#include "Planicie.h"
#include "Mundo.h"

int Idplan = 1;
char undplan = '_';
string plan;

string Planicie::criaNome() {
    string type = "planicie";
    ostringstream ostr;
    ostr << Idplan;
    plan = ostr.str();

    type = type + undplan + plan;
    Idplan++;
    return type;
}

Planicie::Planicie(string tipo):Territorio(criaNome(), 5, 1, 1, 1) {
   
}

Territorio * Planicie::duplica()const{
    return new Planicie(*this);
}
