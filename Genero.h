#include <string>
#ifndef Genero_H
#define Genero_H
using namespace std;

class Genero{

private:
	string sigla;
	string nome;
	//set<Midia> midiasGenero;

public:
	Genero(string sigla, string nome);
	string getSigla();
	string getNome();
	//void addMidiaGen(Midia m);
	int qtdGenero();
	//int compareTo(Genero o);

};

#endif