

#include "Refugio.h"
#include "Mundo.h"

//int Refugio::sequencia = 1;
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
//
//void Refugio::alimentar(int quant, Mundo* mundo) {
//    if (quant <= 0 || mundo == nullptr) {
//        return;
//    }
//    aumentaPeso(quant);
//    if (getPeso() > LIMITE_PESO) {
//        //mundo->eliminaTerritorio(getNumSerie());
//        setVivo(false);
//    }
//}


Territorio* Refugio::duplica()const {
    return new Refugio(*this);
}
