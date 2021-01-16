

#include "Castelo.h"
#include "Mundo.h"

int Idcast = 1;
char undcast = '_';
string cast;

string Castelo::criaNome() {
    string type = "castelo";
    ostringstream ostr;
    ostr << Idcast;
    cast = ostr.str();

    type = type + undcast + cast;
    Idcast++;
    return type;
}

Castelo::Castelo(string tipo) :Territorio(criaNome(), 7, 3, 1, 1) {

}


Territorio* Castelo::duplica()const {
    return new Castelo(*this);
}
