
#include<sstream>
using namespace std;

#include "Territorio.h"
#include "Duna.h"
#include "Planicie.h"
#include "Montanha.h"
#include "Fortaleza.h"
#include "Mina.h"
#include "Castelo.h"
#include "Refugio.h"
#include "Pescaria.h"
#include "utilis.h"


Territorio::Territorio(string tipo0, int res0, int prod0, int ouro0, int ptsv0):
tipo(tipo0),res(res0), prod(prod0), ouro(ouro0), ptsv(ptsv0)
        
{}
Territorio::Territorio( const Territorio & orig):
tipo(orig.tipo), res(orig.res), prod(orig.prod), ouro(orig.ouro), ptsv(orig.ptsv)
        {  
}

string Territorio::getAsString()const{
    ostringstream oss;
    oss << "\n ========================"
        << "\n  Territorio: " << tipo        
        << "\n  resistencia: " << res
        << "\n  produtos: " << prod 
        << "\n  ouro:" << ouro
        << "\n  pontos vitoria: "<< ptsv 
        << "\n ------------------------\n"
        << endl;
    return oss.str();
}
string Territorio::getTipo() const {
    return tipo;
}

int Territorio::getRes()const {
    return res;
}

int Territorio::getProd()const {
    return prod;
}

int Territorio::getOuro()const {
    return ouro;
}

int Territorio::getptsv()const {
    return ptsv;
}

Territorio * Territorio::fabrica(string tipo){
	if (tipo == "planicie") {
		return new Planicie(tipo);
	}
	else if (tipo == "duna") {
		return new Duna(tipo);
	}
    else if (tipo == "montanha") {
        return new Montanha(tipo);
    }
    else if (tipo == "fortaleza") {
        return new Fortaleza(tipo);
    }
    else if (tipo == "mina") {
        return new Mina(tipo);
    }
    else if (tipo == "castelo") {
        return new Castelo(tipo);
    }
    else if (tipo == "refugio") {
        return new Refugio(tipo);
    }
    else if (tipo == "pescaria") {
        return new Pescaria(tipo);
    }
	return nullptr;
}

ostream & operator<<(ostream & saida, const Territorio & x) {
    saida << x.getAsString();
    return saida;
}