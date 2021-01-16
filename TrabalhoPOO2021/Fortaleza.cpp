

#include "Fortaleza.h"
#include "Mundo.h"

int Idfort = 1;
char undfort = '_';
string fort;

string Fortaleza::criaNome() {
    string type = "fortaleza";
    ostringstream ostr;
    ostr << Idfort;
    fort = ostr.str();

    type = type + undfort + fort;
    Idfort++;
    return type;
}

Fortaleza::Fortaleza(string tipo) :Territorio(criaNome(), 8, 0, 0, 1 ) {

}


Territorio* Fortaleza::duplica()const {
    return new Fortaleza(*this);
}
