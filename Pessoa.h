#include <set>
#include <string>
#include "Midia.h"

#ifndef Pessoa_H
#define Pessoa_H

using namespace std;
class Midia;

class Pessoa {

private:
	int codigo;
	string nome;
	//set<Midia> trabalhos;
	
public:
	Pessoa(int codigo, string nome);
	//Pessoa();
	int getCodigo();
	string getNome();
	void addMidia(Midia m);
	// int qtdTrabalhos();
	//set<Midia> getTrabalhos();
	//int compareTo(Pessoa o);
	
};

#endif
