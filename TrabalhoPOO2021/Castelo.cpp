

#include "Castelo.h"
#include "Mundo.h"

//int Castelo::sequencia = 1;
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

//void Castelo::alimentar(int quant, Mundo* mundo) {
//    if (quant <= 0 || mundo == nullptr) {
//        return;
//    }
//    aumentaPeso(quant);
//    if (getPeso() > LIMITE_PESO) {
//        //mundo->eliminaTerritorio(getNumSerie());
//        setVivo(false);
//    }
//}


Territorio* Castelo::duplica()const {
    return new Castelo(*this);
}
