
#include "Mina.h"
#include "Mundo.h"

int Idmine = 1;
char undmine = '_';
string mine;

string Mina::criaNome() {
    string type = "mina";
    ostringstream ostr;
    ostr << Idmine;
    mine = ostr.str();

    type = type + undmine + mine;
    Idmine++;
    return type;
}

Mina::Mina(string tipo) :Territorio(criaNome(), 5, 0, 1, 1) {

}

Territorio* Mina::duplica()const {
    return new Mina(*this);
}
