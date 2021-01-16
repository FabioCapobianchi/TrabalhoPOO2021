

#include "Refugio.h"
#include "Mundo.h"

int Idrefug = 1;
char undrefug = '_';
string refug;

string Refugio::criaNome() {
    string type = "refugio";
    ostringstream ostr;
    ostr << Idrefug;
    refug = ostr.str();

    type = type + undrefug + refug;
    Idrefug++;
    return type;
}

Refugio::Refugio(string tipo) :Territorio(criaNome(), 9, 0, 1, 1) {

}

Territorio* Refugio::duplica()const {
    return new Refugio(*this);
}
