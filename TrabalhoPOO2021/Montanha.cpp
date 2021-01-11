
#include "Montanha.h"
#include "Mundo.h"

//int Montanha::sequencia = 1;
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

Montanha::Montanha(string tipo) :Territorio(criaNome(), 6, 1, 0, 1) {

}

//void Montanha::alimentar(int quant, Mundo* mundo) {
//    if (quant <= 0 || mundo == nullptr) {
//        return;
//    }
//    aumentaPeso(quant);
//    if (getPeso() > LIMITE_PESO) {
//        //mundo->eliminaTerritorio(getNumSerie());
//        setVivo(false);
//    }
//}


Territorio* Montanha::duplica()const {
    return new Montanha(*this);
}
