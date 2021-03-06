

#include<sstream>
using namespace std;

#include "Territ_Inic.h"
#include "Mundo.h"
#include "Territorio.h"
#include "Interaccao.h"
#include "utilis.h"



Territ_Inic::Territ_Inic() : res(9), prod1(1), ouro1(1), pontos(1), cofre(0), armazem(0), drones(false),
misseis(false), defesas(false), bolsa(false), bankctr(false),maxarmy(3),maxarmaz(3),maxcofre(3),ntec(0)
{
    army = intUniformRnd(0, maxarmy);
}

Territ_Inic::Territ_Inic(const Territ_Inic& orig) {
    //construtor por defeito do vector
    *this = orig;
}

void Territ_Inic::eliminaTerrit(string namet) {
    for (unsigned int i = 0; i < territ_I.size(); i++) {
        if (territ_I[i]->getTipo() == namet) {

            territ_I.erase(territ_I.begin() + i);
        }
    }
}

int Territ_Inic::fuiinvadido(int ano) {

    int ale = 0;
    int x,df=0;
    cout << "\n       !!!! O Imperio esta a ser atacado !!!!\n";
    if (ano == 1) {
        ale = 2;
    }if (ano == 2) {
        ale = 3;
    }
    ale += intUniformRnd(1, 6);
    if (territ_I.empty()) {
        return 0;
    } 
    x = territ_I.size();
    x--;
    if (getDefesa() == true) {
        df = 1;
    }
    if ((territ_I[x]->getRes()+df) > ale) {
        cout << "      !!!! O territorio " << territ_I[x]->getTipo() << " resistiu ao ataque !!!!\n";
        return 1;
    }
    else
    {
        cout << " !!!! O territorio " << territ_I[x]->getTipo() << " foi conquistado pelo inimigo !!!!\n";
        eliminaTerrit(territ_I[x]->getTipo());
        return 2;
    }
  

}

void Territ_Inic::setPontos(int pt) {
    pontos += pt;
}

Territ_Inic::~Territ_Inic() {
    for (Territorio* p : territ_I) {
        delete p;
    }
}

Territ_Inic& Territ_Inic::operator=(const Territ_Inic& orig) {
    // evita da auto-atribuicao
    if (this == &orig) {
        return *this;
    }
    // libertar mem. din. velha
    for (unsigned int i = 0; i < territ_I.size(); i++) {
        delete territ_I[i];
    }
    //esvaziar o vector
    territ_I.clear();
    // copiar a informacao de orig, duplicando os objectos dinamicos Territorio
    for (unsigned int i = 0; i < orig.territ_I.size(); i++) {
        Territorio* p = orig.territ_I[i]->duplica();
        territ_I.push_back(p);
    }
    return *this;
}

bool Territ_Inic::addTerritorio(string tipo) {
    Territorio* p = Territorio::fabrica(tipo);
    if (p == nullptr) {
        return false;
    }
    territ_I.push_back(p);
    return true;
}

void Territ_Inic::recolheprod() {
    if (getCofre() < maxcofre) {
        setCofre(getOuro());
    }
    if (getArmazem() < maxarmaz) {
        setArmazem(getProd());
    }

    for (unsigned int i = 0; i < territ_I.size(); i++) {
        if (getCofre() < maxcofre) {
            setCofre(territ_I[i]->getOuro());
        }
        if (getArmazem() < maxarmaz) {
            setArmazem(territ_I[i]->getProd());
        }   
    }
}

void Territ_Inic::alteraproducao(int ano, int turno) {
    string tipo;
    for (int i = 0; i < territ_I.size(); i++) {
        mudaNome(territ_I[i]->getTipo());
        if ( tipo == "planicie_" && ano == 2) {
            territ_I[i]->setProd(2);
        }
        else if (tipo == "mina_") {
            if (turno >= 3) {
                territ_I[i]->setOuro(3);
           } 
            if (turno < 3) {
               territ_I[i]->setOuro(1);
           }   
        }
        else if (tipo == "castelo_") {
            if (turno >= 2) {
                territ_I[i]->setProd(0);
         } if (turno < 2) {
             territ_I[i]->setProd(3);
         }
        }
        else if (tipo == "pescaria_" && ano == 2) {
            territ_I[i]->setProd(4);
        }
    }

}

string Territ_Inic::mudaNome(string a) {
    string nova = "";
    string carater;

    for (unsigned int i = 0; i < a.length() - 1; i++)
    {
        carater = a.substr(i, 1);
        nova += carater;

    }return nova;
  
}

bool Territ_Inic::conquiTerritorio(Territorio * ter) {
    Territorio* p = ter;
    if (p == nullptr) {
        return false;
    }
    territ_I.push_back(p);
    return true;
}

string Territ_Inic::getAsString()const {
    ostringstream oss;
    oss << "\n #####################"
        << "\n ##     IMPERIO     ##"
        << "\n #####################\n"
        << "\n Resitencia: " << res
        << "\n Forca militar: " << army
        << "\n Armazem: " << armazem
        << "\n Cofre: " << cofre
        << "\n Pontos: " << pontos
        << "\n Drones Militares: " << drones
        << "\n Misseis Teleguiados: " << misseis
        << "\n Defesas Territorias: " << defesas
        << "\n Bolsa de Valores: " << bolsa
        << "\n Banco Central: " << bankctr 
        << "\n Numero de Tecnologia adquiridas: " << ntec
        << "\n #####################"<< endl << endl;

    for (Territorio* p : territ_I) {
        oss << p->getAsString();
    }
    return oss.str();
}

unsigned int Territ_Inic::getQuantosTerritorios()const {
    return territ_I.size();
}
//Altera o valor da forca militar
void Territ_Inic::setArmy(int x) {
   army += x;
   if (army < 0) {
       army = 0;
   }
      
}
// retorna a potencia militar do terrirtorio inicial
int Territ_Inic::getArmy()const {
    return army;
}

int Territ_Inic::getOuro()const {
    return ouro1;
}

int Territ_Inic::getProd()const {
    return prod1;
}

void Territ_Inic::setCofre(int i) {
    
        cofre += i;
        if (getCofre() < 0) {
            cofre = 0;
        }
}

int Territ_Inic::getCofre()const {
    return cofre;
}

void Territ_Inic::setArmazem(int i) {
    
        armazem += i;
        if (getArmazem() < 0) {
            armazem = 0;
        }
}

int Territ_Inic::getArmazem()const {
    return armazem;
}

void Territ_Inic::setDrones(int i) {
    if (i == 0) {
        drones = true;
        maxarmy = 5;
        setCofre(-3);
    }
    else
    {
        drones = true;
    }
}

bool Territ_Inic::getDrones()const {
    return drones;
}

void Territ_Inic::setMisseis(int i) {
    if (i == 0) {
        misseis = true;
        setCofre(-4);
    }
    else
    {
        misseis = true;
    }
  
}

bool Territ_Inic::getMisseis()const {
    return misseis;
}

int Territ_Inic::setDefesas(int i){
    if (i == 0) {
        defesas = true;
        setCofre(-4);
        return 1;
    }
    else
    {
        defesas = true;
        return 1;
    }
   
}

bool Territ_Inic::getDefesa()const{
    return defesas;
}

void Territ_Inic::setBolsa(int i) {
    if (i == 0) {
        bolsa = true;
        setCofre(-2);
    }
    else
    {
        bolsa = true;
    }
   
}

bool Territ_Inic::getBolsa()const{
    return bolsa;
}

void Territ_Inic::setBankctr(int i) {
    if (i == 0) {
        bankctr = true;
        maxcofre = 5;
        maxarmaz = 5;
        setCofre(-3);
    }
    else
    {
        bankctr = true;
    }
   
}

bool Territ_Inic::getBankctr()const {
    
    return bankctr;

}

int Territ_Inic::getMaxarmy()const{
    return maxarmy;
}

void Territ_Inic::setMaxarmy(int x){
    maxarmy += x;

}

int Territ_Inic::getMaxcofre()const{

    return maxcofre;
}

void Territ_Inic::setMaxcofre(int x){

    maxcofre += x;
}

int Territ_Inic::getMaxarmazem()const {

    return maxarmaz;
}

void Territ_Inic::setMaxarmazem(int x) {

    maxarmaz += x;
}

int Territ_Inic::getTec()const {
    return ntec;
}

void Territ_Inic::setTec() {
    ntec += 1;
}