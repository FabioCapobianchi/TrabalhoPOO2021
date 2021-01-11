
#include<sstream>
using namespace std;

#include "Mundo.h"
#include "Territorio.h"
#include "utilis.h"


Mundo::Mundo(const Mundo& orig) {
    //construtor por defeito do vector
    *this = orig;
}

Mundo::~Mundo() {
    for(Territorio * p: territ){
        delete p;
    }
}

Mundo & Mundo::operator=(const Mundo& orig) {
    // evita da auto-atribuicao
    if(this == &orig){
        return *this;
    }
    // libertar mem. din. velha
    for( int i = 0 ; i < territ.size() ; i++){
        delete territ[i];
    }
    //esvaziar o vector
    territ.clear(); 
    // copiar a informacao de orig, duplicando os objectos dinamicos Territorio
    for( int i = 0 ; i < orig.territ.size() ; i++){
        Territorio * p = orig.territ[i]->duplica();
        territ.push_back(p);
    }
    return *this;
}
bool Mundo::addTerritorio(string tipo){
	Territorio * p = Territorio::fabrica(tipo);
    if(p == nullptr){
        return false;
    }
    territ.push_back(p);
    return true;
}


Territorio* Mundo::verificavector(string str, int* resis){

    for (int i = 0; i < territ.size(); i++) {
        if (territ[i]->getTipo() == str) {
            *resis = territ[i]->getRes();
            return territ[i];
        }
    }
    return nullptr;
}

void Mundo::eliminaTerrit(string namet) {
    for (int i = 0; i < territ.size(); i++) {
        if (territ[i]->getTipo() == namet) {
     
            territ.erase(territ.begin()+i);
        }
    }
}

string Mundo::getAsString()const {
    ostringstream oss;
    oss << "\n   ==================="
        << "\n   ==     MUNDO     =="
        << "\n   ===================\n";
    for (Territorio * p : territ) {
        oss << p->getAsString();
    }
    return oss.str();
}
unsigned int Mundo::getQuantosTerritorios()const{
    return territ.size();
}