
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
    // libertar memoria dinamica velha
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

string Mundo::mudaNome(string a) {
    string nova = "";
    string carater;

    for (unsigned int i = 0; i < a.length() - 1; i++)
    {
        carater = a.substr(i, 1);
        nova += carater;

    }return nova;

}

void Mundo::alteraproducao(int ano, int turno) {
    string tipo;
    for (int i = 0; i < territ.size(); i++) {
        mudaNome(territ[i]->getTipo());
        if (tipo == "planicie_" && ano == 2) {
            territ[i]->setProd(2);
        }
        else if (tipo == "mina_") {
            if (turno >= 3) {
                territ[i]->setOuro(3);
            }
            if (turno < 3) {
                territ[i]->setOuro(1);
            }
        }
        else if (tipo == "castelo_") {
            if (turno >= 2) {
                territ[i]->setProd(0);
            } if (turno < 2) {
                territ[i]->setProd(3);
            }
        }
        else if (tipo == "pescaria_" && ano == 2) {
            territ[i]->setProd(4);
        }
    }

}