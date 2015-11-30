#include<list>
#include"Midia.h"
#include"Pessoa.h"

using namespace std;

class Livro : public Midia {

private:
	list<Pessoa> autores;
	
public:
	Livro(int codigo, string nome, int tamanho, Genero& genero, bool possui, bool consumiu, bool deseja, double preco, list<Pessoa> autores);
	list<Pessoa> getAutores();
	
};
