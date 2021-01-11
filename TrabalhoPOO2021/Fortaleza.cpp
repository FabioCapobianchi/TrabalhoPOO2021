

#include "Fortaleza.h"
#include "Mundo.h"

//int Fortaleza::sequencia = 1;
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

//void Fortaleza::alimentar(int quant, Mundo* mundo) {
//    if (quant <= 0 || mundo == nullptr) {
//        return;
//    }
//    aumentaPeso(quant);
//    if (getPeso() > LIMITE_PESO) {
//        //mundo->eliminaTerritorio(getNumSerie());
//        setVivo(false);
//    }
//}


Territorio* Fortaleza::duplica()const {
    return new Fortaleza(*this);
}
