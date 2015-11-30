#include<list>
#include"Pessoa.h"
#include"Midia.h"

using namespace std;

class Serie : public Midia {

private:
	list<Pessoa> atores;
	string temporada;
	string nameSerie;

public:
	Serie(int codigo, string nome, int tamanho, Genero& genero, bool possui, bool consumiu, bool deseja, double preco, list<Pessoa> atores, string temporada, string nameSerie);
	list<Pessoa> getAtores();
	string getTemporada();
	string getNomeSerie();
	
};
