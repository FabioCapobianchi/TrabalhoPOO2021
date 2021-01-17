
#include "Montanha.h"
#include "Mundo.h"

int Idmont = 1;
char undmont = '_';
string mont;

string Montanha::criaNome() {
    string type = "montanha";
    ostringstream ostr;
    ostr << Idmont;
    mont = ostr.str();

    type = type + undmont + mont;
    Idmont++;
    return type;
}

Montanha::Montanha(string tipo) :Territorio(criaNome(), 6, 0, 0, 1) {

}

Territorio* Montanha::duplica()const {
    return new Montanha(*this);
}
