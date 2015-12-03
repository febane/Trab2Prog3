#include <vector>
#include "Pessoa.h"
#include "Midia.h"

using namespace std;

class Serie : public Midia {

private:
	vector<Pessoa> atores;
	string temporada;
	string nameSerie;

public:
	Serie(int codigo, string nome, int tamanho, Genero& genero, bool possui, bool consumiu, bool deseja, double preco, vector<Pessoa> atores, string temporada, string nameSerie);
	vector<Pessoa> getAtores();
	string getTemporada();
	string getNomeSerie();
	
};
