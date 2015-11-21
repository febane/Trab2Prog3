#include<string>
#include<ctime>

class Emprestimo{

private:
	Midia midia;
	String tomador;
	time_t emprestimo;
	time_t devolucao;

public:
	Emprestimo(Midia midia, string tomador, time_t emprestimo, time_t devolucao);
	Midia getMidia();
	string getTomador();
	time_h getEmprestimo();
	time_h getDevolucao();
	int compareTo(Emprestimo arg0);
	
};

/**
 * Construtor de Emprestimo
 * @param midia midia emprestada
 * @param tomador quem tomou a midia
 * @param emprestimo data de emprestimo
 * @param devolucao data de devolucao
 */
Emprestimo::Emprestimo(Midia midia, string tomador, time_t emprestimo, time_t devolucao) {
	this.midia = midia;
	this.tomador = tomador;
	this.emprestimo = emprestimo;
	this.devolucao = devolucao;
}

/**
 * Pega midia
 * @return midia
 */
Midia Emprestimo::getMidia() {
	return midia;
}

/**
 * Pega tomador
 * @return tomador
 */
string Emprestimo::getTomador() {
	return tomador;
}

/**
 * Pega data de emprestimo
 * @return data de emprestimo
 */
time_h Emprestimo::getEmprestimo() {
	return emprestimo;
}

/**
 * Pega data de devolucao
 * @return data de devolucao
 */
time_h Emprestimo::getDevolucao() {
	return devolucao;
}

int Emprestimo::compareTo(Emprestimo arg0) {
	if(this.emprestimo<arg0.getEmprestimo())
		return 1;
	else if(this.emprestimo>arg0.getEmprestimo())
		return -1;
	else
		return 0;
}
