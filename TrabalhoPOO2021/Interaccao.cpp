
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <cstring>
#include <limits>
#include <Windows.h>

using namespace std;

#include "Territorio.h"
#include "Territ_Inic.h"
#include "Interaccao.h"
#include "utilis.h"

int armyale = 0;

vector<string> ter = { "planicie","montanha", "fortaleza", "mina", "duna", "castelo", "refugio", "pescaria" };
vector<string> tec = { "drones militares", "misseis teleguiados", "defesas territoriais", "bolsa valores", "banco central" };

vector<string> comandos = { "carrega","cria","conquista","passa", "maisouro",
	   "maisprod", "maismilitar", "adquire", "lista", "avanca",
	   "grava", "ativa", "apaga", "toma", "modifica", "fevento", "sair"};

Interaccao::Interaccao(Mundo * aq, Territ_Inic * empire):ano(1),turno(1){
    mundo = aq;
	imperio = empire;
}



int Interaccao::verificaCom(vector<string> cm, string t) {
	int cont = 0;
	for (vector<string>::const_iterator it = cm.begin();
		it != cm.end(); ++it) {
		if (*it == t) {
			return cont;
		}cont++;
	}
	cout << "\n ******Comando nao existe ou foi mal Escrito.******\n";
	return -1;
}

void Interaccao::setAno(int i){

	ano += i;
}

int Interaccao::getAno(){
 
	return ano;
}

void Interaccao::setTurno(int i){

	turno += i;
}

int Interaccao::getTurno(){

	return turno;
}

void Interaccao::setEvent(string event) {

	evento = event;
}

int Interaccao::menu() {

	string cmdo,cmd1,tp;
	char c;
	int opcao = -1;
	int nalet = 0;
	int qut = 0;

	cout << "\n          ######################################\n";
	cout << "\n      #### Fase configuracao //conquista//passa ####\n";
	cout << "\n          ######################################\n\n";
	Sleep(3000);
	
	do {
		cout << "\n\n >>>> Digite um Comando: \n";
		fseek(stdin, 0, SEEK_END);
		getline(cin, cmdo);
		istringstream iss(cmdo);
		iss >> cmd1;
		if (cmd1 == "cria" || cmd1 == "carrega" || cmd1 == "lista" || cmd1 == "conquista" || cmd1 == "passa" || cmd1 == "sair") {
			if (cmd1 == "cria") {
				iss >> tp >> qut;
				if (!iss) {
					cout << "\n !!!! Faltam parametros para o comando cria !!!! \n";
					cout << "\n !!!! Exemplo cria duna 2 !!!! \n";
					opcao = 5;
				}
				else {
					opcaoAcrescentarTerritorio(tp, qut);
				}
			}else 
				if (cmd1 == "conquista") {
			iss >> tp ;
			if (!iss) {
				cout << "\n !!!! Faltam parametros para o comando conquista !!!! \n";
				cout << "\n !!!! Exemplo conquista duna_2//castelo_3 !!!! \n";
				opcao = 5;
			}
			else {
				opcaoConquistarTerritorio(tp);
				opcao = 5;
			}
		}

		else {
			opcao = verificaCom(comandos, cmdo);//Verifica se o comando existe ou foi escrito corretamente
		}
		}
		else
		{
			cout << "\n !!!! Não é possivel utilizar esse comando nessa fase ou foi mal digitado !!!!\n";
			opcao = 5;
		}


		switch (opcao) {

		case 0: // Carrega
		{
			criadoficheiro();

		}
		break;
	
		case 8: // <Lista>  Mostra no ecra a Informa��o do territorio inicial e dos territorios do mundo
		{   
			do {
				cout << "\n >>>> Listar todos - T, Pesquisar territorios - P: >>>>\n";
				fseek(stdin, 0, SEEK_END);
				cin >> c;
			} while (c != 'T' && c != 'P');

				 opcaoListarTerritorio(c);
		}
		break;
		case 16: // saur
		{   
			
			return 0;
		}
		break;

		}

	} while (opcao != 3);
	cout << "\n     ############################################\n";
	cout << "\n #### Fim da Fase configuracao//conquista//passa ####\n";
	cout << "\n     ############################################\n\n";
	return 1;
}

int Interaccao::menuFrecolha() {

	string aux1;
	int opcao = 0;
	char c;
	int flag = 2, flag1 = 2;

	Sleep(1500);
	cout << "\n     #############################\n";
	cout << "\n #### Fase de recolha de producao ####\n";
	cout << "\n     #############################\n";
	opcaoRecolha();
	Sleep(3000);
	cout << imperio->getAsString() << endl;
	cout << "\n#### Foram recolhidos ouro e produtos de todos territorios do imperio####\n\n";

	if (imperio->getBolsa() == true){
		   
		cout << "\n     ############ Bolsa de Valores##########=\n\n";
		cout << "\n#### Se dispor de recursos pode efetuar trocas####\n"; 
		cout << "\n       #### Digite passar para passar####\n";
		Sleep(1500);
		do {
				cout << "\n >>>> Digite um Comando:  \n";
				fseek(stdin, 0, SEEK_END);
				cin >> aux1;	
				
				if (aux1 == "passa") {
					opcao = 17;
					cout << "\n\n#### Fim da fase de recolha####\n\n";
				}

				if (aux1 == "maisouro" && flag == 2) {
					opcao = 4;
			
				}
				else if (aux1 == "maisprod" && flag1 == 2) {
					opcao = 5;
				}
				else if (aux1 == "lista") {
					opcao = 6;
				}
				else if (aux1 == "sair") {
					return 0;
				
				}
				else
				{
					cout << "\n#### maisouro//maisprod####\n";
				}
			switch (opcao) {

			case 4: //mais ouro
			{
				flag = opcaoMaisouro();
			}
			break;

			case 5: // mais produtos
			{	
				 flag1 = opcaoMaisprod();	
			}
			break;

			case 6: //lista
			{
				do {
					cout << "\n >>>> Listar todos - T, Pesquisar territorios - P: >>>>\n";
					fseek(stdin, 0, SEEK_END);
					cin >> c;
				} while (c != 'T' && c != 'P');

				opcaoListarTerritorio(c);
			}
			break;
			}
			if (flag != 2 && flag1 != 2) {
				cout << "\n\n     ########## Fim da fase de recolha ##########\n\n";
				opcao = 17;
			}
		} while (opcao != 17);
	}
	else
	{
		cout << "\n     !!!! Nao possui a Bolsa de Valores para efetuar trocas !!!!\n";
		cout << "\n\n     ##########  Fim da fase de recolha  ##########\n";
		cout <<   "\n          ####################################\n\n";
	}
	return 1;
}

int Interaccao::menuFcompra() {

	string cmd,cmd1,tip,tip1;
	string tipo;
	int opcao = 0;
	int flag = 2, flag1 = 0;
	cout << "\n          ###################################################\n";
	cout << "\n      #### Fase de Compra de unidades militares e tecnologia ####\n";
	cout << "\n          ###################################################\n";
	Sleep(3000);

	do {

		cout << "\n\n >>>> maismilitar ou adquire <tecnologia>: \n";
		fseek(stdin, 0, SEEK_END);
		getline(cin, cmd);
		istringstream iss(cmd);
		iss >> cmd1;
		if (cmd1 == "maismilitar") {
			if (flag == 2) {/////////fazer controlo de vezes a comprar
				opcao = 1;
			}
			else
			{
				cout << "\n !!!! Opcao maismilitar ja foi utilizada nesse turno !!!!\n";
			}
		}
		if (cmd1 == "lista") {
			opcao = 7;
		}
		if (cmd1 == "passa") {
			opcao = 17;
		}
		if (cmd1 == "sair") {
			return 0;
			
		}
		else{

			if (cmd1 == "adquire" && flag1 == 0) {
				iss >> tip >> tip1;
				if (!iss) {
					cout << "\n !!!! Faltam parametros para o comando adquire !!!! \n";
					cout << "\n !!!! Exemplo adquire misseis//banco central !!!! \n\n";
					opcao = 20;
				}
				else
				{
					tipo = uninome(tip, tip1);

					if (verificaTipo(tipo, tec) == 1) {
						if (tipo == "drones militares")
							opcao = 2;
						if (tipo == "misseis teleguiados")
							opcao = 3;
						if (tipo == "defesas territoriais")
							opcao = 4;
						if (tipo == "bolsa valores")
							opcao = 5;
						if (tipo == "banco central")
							opcao = 6;
					}
				
				}
			}
			if(cmd1 == "adquire" && flag1 != 0)
			{
				cout << "\n !!!! Ja foi adquirida tecnologia nesse turno !!!!\n";
				opcao = 8;
			}
	}
		
			
		switch (opcao) {
		case 1: // mais força militar
		{
		      flag = opcaoMaismilitar();
		}
		break;
		case 2: // adquire drones militares
		{
			  flag1 = opcaoAdquireDrone();
		}
		break;
		case 3: // adquire tecnologia missil
		{
			flag1 = opcaoAdquireMissil();
		}
		break;
		case 4: // adquire tecnologia defesas territoriais
		{
			flag1 = opcaoAdquireDefesa();
		}
		break;
		case 5:
		{
			flag1 = opcaoAdquireBolsa();
		}
		break;
		case 6:
		{
			flag1 = opcaoAdquireBanco();
		}
		break;
		case 7:
		{
			opcaoListarTerritorio('T');
		}
		break;
		}
		if (flag != 2 && flag1 == 1) {
			
			opcao = 17;
		}
	} while (opcao != 17);
	cout << "\n          ##########################################################\n";
	cout << "\n      #### Fim da fase de Compra de unidades militares e tecnologia ####\n";
	cout << "\n          ##########################################################\n\n";
	return 1;
}

int Interaccao::menuFeventos() {
	int opcao;
	int fim;
	opcao = intUniformRnd(1, 4);


	cout << "\n          #################\n";
	cout << "\n      #### Fase de Eventos ####\n";
	cout << "\n          #################\n\n";
	Sleep(3000);

	switch (opcao) {
	case 1: 
	{
		recursoabandonado();

	}
	break;
	case 2: 
	{
		fim = invasao();
		if (fim == 0) {
			cout << "\n       !!!! O imperio nao possui territorios para ser conquistados !!!!\n";
			cout << "\n     ****************** O IMPERIO foi destruido ************************\n";
			return 0;
			exit(0);
		}
	}
	break;
	case 3:
	{
		alianca();
	}
	break;
	case 4:
	{
		cout << "\n !!!! Nao houve nenhum evento !!!!\n";
		setEvent("Sem Evento");
	}
	}
	if (getTurno() == 6) {
		turno = 1;
		setAno(1);
	}
	else
	if(getTurno() < 6){
		setTurno(1);
	}
	if (getTurno() == 6 && getAno() == 2) {
		//funcao de saida
		return 0;
	}
	
	cout << "\n     ################\n";
	cout << "\n #### Fim de Eventos ####\n";
	cout << "\n     ################\n\n";

	return 1;
}

void Interaccao::opcaoRecolha() {
	imperio->recolheprod();
}

string Interaccao::getAsString()const {
    ostringstream oss;
	oss << "\n ANO: " << ano
		<< "\n Turno: " << turno
		<< "\n Ultimo evento ocorrido : " << evento << endl;

    return oss.str();
}

int Interaccao::verificaTipo(string t, vector<string> cm) {
	int cont = 0;
	
	for (vector<string>::const_iterator it = cm.begin();
		it != cm.end(); ++it) {
		if (*it == t) {
			return 1;
		}cont++;
	}
	cout << "\n ****** Tipo nao existe ou foi mal Escrito. ******\n";
	return 0;
}

int Interaccao::verificaQuant(string qt) {
	int  res = 1;
	for (unsigned int i = 0; i < qt.size(); i++) {
		if (qt[i] < '0' || qt[i]> '9')
			res = 0;
	}
	if (res == 0)
		cout << "\n ****** Numero Invalido ******\n";
	return res;
}


// recebe do utilizador o tipo de territorio e a quantidade e insere no vector de territorios
void Interaccao::opcaoAcrescentarTerritorio(string s, int qt){

	int  i, cont = 0, flag=0, flag1 = 0;


		flag = verificaTipo(s,ter);//verifica se o tipo existe
		//flag1 = verificaQuant(qt);//verifica se a quantidade é um int;
		if (flag == 1) {
			for (i = 0; i < qt; i++) {
				if (mundo->addTerritorio(s)) {
					cont++;
				}
			}
			if (cont == qt) {
				cout << "\n >>>> Criado\\s: " << qt
					<< " territorio\\s do tipo: " << s
					<< " >>>>" << endl;

			}
			
		}
		else {
			cout << "****** Tipo nao existe ******\n";
		}
}

//Cria uma serie de territorios a partir de um ficheiro de texto
void Interaccao::criadoficheiro() {
	int cont = -1;
	int qt = 0;
	string comand,tipo, tipoaux;

	cout << "\n >>>> Digite o nome do Ficheiro: ";
	cin >> tipoaux;

	ifstream fich1(tipoaux);
	if (!fich1) {
		cout << "\n Ocorreu um erro ao abrir o Ficheiro: " << tipoaux
			<< "\n Verifique se o nome esta correto Ex: XXXXXX.txt" << endl;
		return;
	}
	while (!fich1.eof()) {
		getline(fich1,tipo);
		istringstream iss(tipo);
		iss >> comand;
		if(comand == "cria")
			iss >> tipo >> qt;

		if (iss) {
				opcaoAcrescentarTerritorio(tipo,qt);
				cont++;
		}
		else
		{
			cout << "\n !!!! Erro na criacao dos territorios !!!!\n";
			return;
		}
		if (comand == "lista") {
			cout << imperio->getAsString() << endl;
			cout << mundo->getAsString() << endl;
		}
	}
	
	fich1.close();
}

void Interaccao::opcaoListarTerritorio(char c0) {

	if (c0 == 'T') {          //Falta fazer o cout da fase , turno etc!!!!!!!!!!!!!!!!
		cout << getAsString() << endl;
		cout << imperio->getAsString() << endl
			<< " Ultimo numero aleatorio: "
			<< armyale << endl;
			if(mundo->getQuantosTerritorios() == 0) {
				cout << "\n !!!! Os territorios ainda nao foram criados !!!!\n";
				cout << " !!!! Utilize o comando <cria> !!!!\n";
				return;
			}
			cout << mundo->getAsString() << endl;
	}
	else if (c0 == 'P') {
		opcaoPesquisarTerritorio();
	}
}


void Interaccao::opcaoPesquisarTerritorio(){
	string pesquisa;
	int res;                      
	cout << "\n >>>> Digite o nome do territorio: >>>>\n";
	cin >> pesquisa;
	const Territorio * p = mundo->verificavector(pesquisa,& res);
	if (p == nullptr) {
		cout << "\n****** Territorio escolhido nao existe ******\n";	
	}
	else {
		cout << endl << p->getAsString();
	}
}

bool Interaccao::mudaNome(string s) {
	string nova = "";
	string carater;

	for (unsigned int i = 0; i < s.length() - 1; i++)
	{
		carater = s.substr(i, 1);
		nova += carater;

	}
	if (nova == "refugio_" || nova == "pescaria_") {
		return true;
	}
	else
		return false;
}

string Interaccao::uninome(string a, string b){
	string c = " ";
	return a + c + b;
}

void Interaccao::opcaoConquistarTerritorio(string pesquisa) {

	int res;
	Territorio* paux;
	
	Territorio* p = mundo->verificavector(pesquisa, &res);

	if (p != nullptr){
		if (mudaNome(pesquisa)== true) {
			if (imperio->getMisseis() == false || imperio->getQuantosTerritorios() < 5) {
				cout << "\n !!!! Ainda nao e possivel atacar: " << p->getTipo() << endl;
				cout << " !!!! Nao possui a tecnologia de misseis ou ainda nao conquistou 5 territorios !!!!\n";
				return;
			}
		}
		paux = p;
	armyale = intUniformRnd(1, 6);
	if (res <= imperio->getArmy() + armyale) {
		imperio->conquiTerritorio(paux);
		animacao(1);
		cout << "\n !!!! Territorio Conquistado !!!!\n";
		imperio->setPontos(1);
		mundo->eliminaTerrit(pesquisa);

	}else{
		animacao(0);
			cout << "\n****** Territorio Resistiu ao ataque ******\n";
			imperio->setArmy(-1);
		}
 }else
	cout << "\n****** Territorio nao existe tente outra vez ******\n";
}

int Interaccao::opcaoMaisprod(){
	
	
		if (imperio->getArmazem() < imperio->getMaxarmazem()) {
			if (imperio->getCofre() >= 2) {
				imperio->setCofre(-2);
				imperio->setArmazem(1);
				cout << "\n ---- Trocou 2 unidades de ouro por 1 de produtos ----\n";
				return 1;
			}
			else
			{
				cout << "\n !!!! Nao possui ouro suficientes para a troca !!!!\n";
				return 0;
			}
		}
		cout << "\n !!!! O armazem esta no nivel maximo nao e possivel efetuar a troca !!!!\n";
		return 0;
	}

int Interaccao::opcaoMaisouro(){
	
	if (imperio->getCofre() < imperio->getMaxcofre()) {
		if (imperio->getArmazem() >= 2) {
			imperio->setArmazem(-2);
			imperio->setCofre(1);
			cout << "\n ---- Trocou 2 unidades de produtos por 1 de ouro ----\n";
			return 1;
		}
		else
		{
			cout << "\n !!!! Nao possui produtos suficientes para a troca !!!!\n";
			return 0;
		}
	}
	cout << "\n !!!! O cofre esta no nivel maximo nao e possivel efetuar a troca !!!!\n";
	return 0;
	}

int Interaccao::opcaoMaismilitar() {

	if (imperio->getArmy() < imperio->getMaxarmy()) {
		if (imperio->getCofre() > 0 && imperio->getArmazem() > 0) {
			imperio->setCofre(-1);
			imperio->setArmazem(-1);
			imperio->setArmy(1);
			cout << "\n Foi adicionada uma unidade militar\n";
			return 1;
		}
		else
		{
			cout << "\n !!!! Nao possui ouro ou produtos suficientes para a troca !!!!\n";
			return 0;
		}
	}
	else
	{
		cout << "\n !!!! Nao foi possivel efetuar a compra  !!!!\n";
		cout << "\n !!!! Capacidade militar no maximo possivel  !!!!\n";
		return 0;
	}

}


int Interaccao::opcaoAdquireDrone() {
		if (imperio->getCofre() >= 3 ) {
			imperio->setDrones();
			return 1;
		}
		else
		{
			cout << "\n !!!! Nao possui ouro suficiente para a compra !!!!\n";
			return 0;
		}
	}
int Interaccao::opcaoAdquireMissil() {
	if (imperio->getCofre() >= 4) {
		imperio->setMisseis();
		return 1;
	}
	else
	{
		cout << "\n !!!! Nao possui ouro suficiente para a compra !!!!\n";
		return 0;
	}
}

int Interaccao::opcaoAdquireDefesa() {
	if (imperio->getCofre() >= 4) {
		imperio->setDefesas();
		return 1;
	}
	else
	{
		cout << "\n !!!! Nao possui ouro suficiente para a compra !!!!\n";
		return 0;
	}
}

int Interaccao::opcaoAdquireBolsa() {
	if (imperio->getCofre() >= 2) {
		imperio->setBolsa();
		return 1;
	}
	else
	{
		cout << "\n !!!! Nao tem ouro suficiente !!!!\n\n";
		return 0;
	}
}

int Interaccao::opcaoAdquireBanco() {
	if (imperio->getCofre() >= 3) {


		if (imperio->getMaxcofre() < 5 || imperio->getMaxarmazem() < 5) {
			imperio->setBankctr();
			return 1;
		}
		else
		{
			cout << "\n !!!! O Banco já se encontra no limite !!!!\n";
			return 0;
		}
	}
	cout << "\n !!!! Não tem ouro suficiente !!!!\n\n";
	return 0;
}

void Interaccao::recursoabandonado() {
	cout << "\n#### As tropas emcontraram um recurso abandonado####\n";
	if (getAno() == 1) {
		if (imperio->getArmazem() < imperio->getMaxarmazem()) {
			imperio->setArmazem(1);
			cout << "\n **** Foi encontrado uma unidade de produtos e foi guardado em armazem ****\n";
		}
		else {
			cout << "\n **** Foi encontrado uma unidade de produtos mas foi disperdicada ****\n";
		}
	}
	if (getAno() == 2) {
		if (imperio->getCofre() < imperio->getMaxcofre()) {
			imperio->setCofre(1);
			cout << "\n **** Foi encontrado uma unidade de ouro e foi guardado no cofre ****\n";
		}
		else {
			cout << "\n !!!! Foi encontrado uma unidade de ouro mas foi disperdicada !!!!\n";
		}
	}
	setEvent("Recurso Abandonado");
}

int Interaccao::invasao(){

int x = imperio->fuiinvadido(getAno());
setEvent("Invasao");
return x;
}

int Interaccao::alianca() {
	setEvent("Alianca Militar");
	if (imperio->getArmy() < imperio->getMaxarmy()) {
		imperio->setArmy(1);
		cout << "\n !!!! Foi feita uma Alianca Militar !!!!\n";
		cout << "\n !!!! Forca Militar mais uma unidade \n\n";
		return 1;
	}
	cout << "\n **** Foi feita uma Alianca Militar  ****\n";
	cout << "\n **** Mas a Forca Militar nao suporta mais unidades ****\n\n";
	return 0;
}

void Interaccao::inicio() {
	
	cout << endl;
	cout << "   ##   ###     ###  ######   ######  ######   ##  ######\n";
	Sleep(300);
	cout << "   ##   ####   ####  ##   ##  ##      ##   ##  ##  ##  ##\n";
	Sleep(300);
	cout << "   ##   ## ## ## ##  ######   ####    ######   ##  ##  ##\n";
	Sleep(300);
	cout << "   ##   ##   #   ##  ##       ##      ##   ##  ##  ##  ##\n";
	Sleep(300);
	cout << "   ##   ##       ##  ##       ######  ##   ##  ##  ######\n"; 
	Sleep(300);

}

void Interaccao::fim() {
	cout << "\n\n\n            ######   ##   ###     ###\n";
	Sleep(300);
	cout << "            ##       ##   ####   ####\n";
	Sleep(300);
	cout << "            ####     ##   ## ## ## ##\n";
	Sleep(300);
	cout << "            ##       ##   ##   #   ##\n";
	Sleep(300);
	cout << "            ##       ##   ##       ##\n";
}

void Interaccao::animacao(int vd) {

	system("cls");
	Sleep(800);
	cout << "\n";
	cout << ">###>                                  ###  ###  ###\n";
	cout << "                                       ###  ###  ###\n";
	cout << "                                       #############\n";
	cout << "                                       #############\n";
	cout << "                                       #############\n";
	Sleep(800);
	system("cls");
	cout << "\n";
	cout << "     >###>                             ###  ###  ###\n";
	cout << "                                       ###  ###  ###\n";
	cout << "                                       #############\n";
	cout << "                                       #############\n";
	cout << "                                       #############\n";
	Sleep(800);
	system("cls");
	cout << "\n";
	cout << "          >###>                        ###  ###  ###\n";
	cout << "                                       ###  ###  ###\n";
	cout << "                                       #############\n";
	cout << "                                       #############\n";
	cout << "                                       #############\n";
	Sleep(800);
	system("cls");
	cout << "\n";
	cout << "                >###>                  ###  ###  ###\n";
	cout << "                                       ###  ###  ###\n";
	cout << "                                       #############\n";
	cout << "                                       #############\n";
	cout << "                                       #############\n";
	Sleep(800);
	system("cls");
	cout << "\n";
	cout << "                     >###>             ###  ###  ###\n";
	cout << "                                       ###  ###  ###\n";
	cout << "                                       #############\n";
	cout << "                                       #############\n";
	cout << "                                       #############\n";
	Sleep(800);
	system("cls");
	cout << "\n";
	cout << "                                       ###  ###  ###\n";
	cout << "                         >###>         ###  ###  ###\n";
	cout << "                                       #############\n";
	cout << "                                       #############\n";
	cout << "                                       #############\n";
	Sleep(800);
	system("cls");
	cout << "\n";
	cout << "                                       ###  ###  ###\n";
	cout << "                                       ###  ###  ###\n";
	cout << "                               >###>   #############\n";
	cout << "                                       #############\n";
	cout << "                                       #############\n";
	Sleep(800);
	system("cls");
	cout << "\n";
	cout << "                                       ###  ###  ###\n";
	cout << "                                       ###  ###  ###\n";
	cout << "                                       #############\n";
	cout << "                                   >################\n";
	cout << "                                       #############\n";
	if (vd == 1) {
		Sleep(800);
		system("cls");
		cout << "                                                 ###\n";
		cout << "                                            ###  ###\n";
		cout << "                                             ### ###\n";
		cout << "                                          # ########\n";
		cout << "                               #   # #  ############\n";
	}
	if (vd == 0) {
		Sleep(800);
		system("cls");
		cout << "\n";
		cout << "                                       ###  ###  ###\n";
		cout << "                                       ###  ###  ###\n";
		cout << "                                       #############\n";
		cout << "                                       #############\n";
		cout << "                                       #############\n";
	}
}