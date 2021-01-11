

#include "Planicie.h"
#include "Mundo.h"

//int Planicie::sequencia = 1;
int Idplan = 1;
char undplan = '_';
string plan;

string Planicie::criaNome() {
    string type = "planicie";
    ostringstream ostr;
    ostr << Idplan;
    plan = ostr.str();

    type = type + undplan + plan;
    Idplan++;
    return type;
}

Planicie::Planicie(string tipo):Territorio(criaNome(), 5, 1, 1, 1) {
   
}

//void Planicie::alimentar( int quant, Mundo * mundo){
//    if (quant <= 0 || mundo == nullptr) {
//        return;
//    }
//    aumentaPeso(quant);
//    if(getPeso() > LIMITE_PESO){
//		//mundo->eliminaTerritorio(getNumSerie());
//		setVivo(false);
//    }
//}


Territorio * Planicie::duplica()const{
    return new Planicie(*this);
}
