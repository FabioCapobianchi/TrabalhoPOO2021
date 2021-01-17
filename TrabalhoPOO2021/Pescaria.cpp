

#include "Pescaria.h"
#include "Mundo.h"


int Idpesc = 1;
char undpesc = '_';
string pesc;

string Pescaria::criaNome() {
    string type = "pescaria";
    ostringstream ostr;
    ostr << Idpesc;
    pesc = ostr.str();

    type = type + undpesc + pesc;
    Idpesc++;
    return type;
}

Pescaria::Pescaria(string tipo) :Territorio(criaNome(), 9, 2, 0, 1) {

}

Territorio* Pescaria::duplica()const {
    return new Pescaria(*this);
}
