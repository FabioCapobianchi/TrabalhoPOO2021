
#ifndef MUNDO_H
#define	MUNDO_H

#include<string>
#include<vector>
using namespace std;

class Territorio;

class Mundo {
    vector<Territorio *> territ;
	/*int pesquisaTerritorio(int numSerie)const;
	void eliminaMortos();*/
public:
    
    Mundo() = default;
    Mundo(const Mundo& orig); // costrutor por copia
    Mundo & operator=(const Mundo& orig); // operador atribuicao
    virtual ~Mundo(); // destrutor
    Territorio* verificavector(string str, int* resis);
    bool addTerritorio(string tipo);
    void eliminaTerrit(string namet);
    unsigned int getQuantosTerritorios()const;
    
    string getAsString()const;
};

#endif	/* MUNDO_H */

