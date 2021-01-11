#ifndef INTERACCAO_H
#define INTERACCAO_H

#include <vector>
#include <string>
#include <cstring>

using namespace std;

#include "Mundo.h"
#include "Territ_Inic.h"

class Interaccao {
	Mundo * mundo;
    Territ_Inic* imperio;
    int ano;
    int turno;
    string evento;

public:
    Interaccao(Mundo * aq, Territ_Inic * empire);
    string getAsString()const;
    //int lerInt(string msg);
    //int escolheOpcao(vector<string> opcoes);
    int verificaQuant(string qt);
    int verificaTipo(string t, vector<string> cm);
    int verificaCom(vector<string> cm, string t);
    void setAno(int i);
    int getAno();
    void setTurno(int i);
    int getTurno();
    void setEvent(string event);
    int menu();
    int menuFrecolha();
    int menuFcompra();
    int menuFeventos();
    void opcaoRecolha();
    int opcaoMaisouro();
    int opcaoMaisprod();
    int opcaoMaismilitar();
    int opcaoAdquireDrone();
    int opcaoAdquireMissil();
    int opcaoAdquireDefesa();
    int opcaoAdquireBolsa();
    int opcaoAdquireBanco();
    void opcaoAcrescentarTerritorio(string s, int qt);
    void criadoficheiro();
    void opcaoPesquisarTerritorio();
    void opcaoListarTerritorio(char c);
    void opcaoConquistarTerritorio(string pesquisa);
    bool mudaNome(string s);
    string uninome(string a, string b);
    void animacao(int vd);
    void recursoabandonado();
    int invasao();
    int alianca();
};

#endif /* INTERACCAO_H */