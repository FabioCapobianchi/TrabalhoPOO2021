

#include "Pescaria.h"
#include "Mundo.h"

//int Pescaria::sequencia = 1;
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

Pescaria::Pescaria(string tipo) :Territorio(criaNome(), 9, 0, 1, 1) {

}

//void Pescaria::alimentar(int quant, Mundo* mundo) {
//    if (quant <= 0 || mundo == nullptr) {
//        return;
//    }
//    aumentaPeso(quant);
//    if (getPeso() > LIMITE_PESO) {
//        //mundo->eliminaTerritorio(getNumSerie());
//        setVivo(false);
//    }
//}


Territorio* Pescaria::duplica()const {
    return new Pescaria(*this);
}
