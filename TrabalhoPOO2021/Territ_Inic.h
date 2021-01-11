
#ifndef TERRIT_INIC_H
#define	TERRIT_INIC_H

#include<string>
#include<vector>
using namespace std;


class Territorio;

class Territ_Inic {
    vector<Territorio*> territ_I;
    int res;
    int army;
    int prod1;
    int ouro1;
    int armazem;
    int cofre;
    int pontos;
    bool drones;
    bool misseis;
    bool defesas;
    bool bolsa;
    bool bankctr;
    int maxarmy ;
    int maxcofre;
    int maxarmaz;
 
public:
  
    Territ_Inic() ;
    Territ_Inic(const Territ_Inic& orig); // costrutor por copia
    Territ_Inic& operator=(const Territ_Inic& orig); // operador atribuicao
    void eliminaTerrit(string namet);
    virtual ~Territ_Inic(); // destrutor
    void recolheprod();
    bool addTerritorio(string tipo);
    bool conquiTerritorio(Territorio * ter);
    int fuiinvadido(int ano);
    unsigned int getQuantosTerritorios()const;

    string getAsString()const;
    int getOuro()const;
    int getProd()const;
    void setCofre(int i);
    int getCofre()const;
    void setArmazem(int i);
    int getArmazem()const;
    int getMaxarmy()const;
    void setMaxarmy(int x);
    int getMaxarmazem()const;
    void setMaxarmazem(int x);
    int getMaxcofre()const;
    void setMaxcofre(int x);
    void setArmy(int x);
    int getArmy()const;
    void setPontos(int pt);
    void setDrones();
    bool getDrones()const;
    void setMisseis();
    bool getMisseis()const;
    int setDefesas();
    bool getDefesa()const;
    void setBolsa();
    bool getBolsa()const;
    void setBankctr();
    bool getBankctr()const;
};

#endif	/* TERRIT_INIC_H */

