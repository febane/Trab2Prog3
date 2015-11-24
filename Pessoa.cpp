#include<set>
#include<string>

using namespace std;

class Pessoa {

private:
	int codigo;
	string nome;
	set<Midia> trabalhos;
	
public:
	Pessoa(int codigo, string nome);
	Pessoa();
	int getCodigo();
	string getNome();
	void addMidia(Midia m);
	int qtdTrabalhos();
	set<Midia> getTrabalhos();
	int compareTo(Pessoa o);
	
};

/**
 * Construtor de Pessoa
 * @param codigo codigo da pessoa
 * @param nome nome da pessoa
 */
Pessoa::Pessoa(int codigo, string nome) {
	this.codigo = codigo;
	this.nome = nome;
}

/**
 * Construtor de Pessoa
 */
Pessoa::Pessoa(){}

/**
 * Pegar codigo de Pessoa
 * @return codigo da pessoa
 */
int Pessoa::getCodigo() {
	return codigo;
}

/**
 * Pegar nome de Pessoa
 * @return nome da pessoa
 */
string Pessoa::getNome() {
	return nome;
}

/**
 * Adicionar midia a pessoa
 * @param m midia a ser adicionada
 */
void Pessoa::addMidia(Midia m)
{
	this.trabalhos.insert(m);
}

/**
 * Pegar quantidade de midias relacionadas a pessoa
 * @return quantidade de trabalhos realizados
 */
int Pessoa::qtdTrabalhos()
{
	return this.trabalhos.size();
}

/**
 * Pega lista de midias feitas pela pessoa
 * @return conjunto de midias realizadas por pessoa
 */
set<Midia> Pessoa::getTrabalhos() {
	return trabalhos;
}

int Pessoa::compareTo(Pessoa o) {
	locale br = setlocale(LC_ALL, "Portuguese");
	collate collator = use_facet<collate<char> >(br);
	try{
		return collator.compare(this.getNome(), this.getNome()+this.getNome().length(), o.getNome(), o.getNome()+o.getNome().length());
	}
	catch(Exception ex){
		ex.printStackTrace();
	}
	return 0;
}
