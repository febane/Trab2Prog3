#include"Genero.h"

using namespace std;

/**
 * Construtor de Genero
 * @param sigla sigla do genero
 * @param nome nome do genero
 */
Genero::Genero(string sigla, string nome) {
	this->sigla = sigla;
	this->nome = nome;
}

/**
 * Pega sigla do genero
 * @return sigla do genero
 */
string Genero::getSigla() {
	return sigla;
}

/**
 * Pega nome do genero
 * @return nome do genero
 */
string Genero::getNome() {
	return nome;
}

/**
 * Adiciona midia com genero correspondente
 * @param m midia a ser adicionada
 */
//void Genero::addMidiaGen(Midia m)
//{
//	midiasGenero.insert(m);
//}

// /**
//  * Retorna quantidade de generos
//  * @return quantidade de generos
//  */
// int Genero::qtdGenero()
// {
// 	return midiasGenero.size();
// }
//
//
// int Genero::compareTo(Genero o) {
// 	locale br = setlocale(LC_ALL, "Portuguese");
// 	collate collator = use_facet<collate<char> >(br);
// 	if(this.midiasGenero.size() > o.midiasGenero.size())
// 	{
// 		return -1;
// 	}else if(this.midiasGenero.size() < o.midiasGenero.size())
// 	{
// 		return 1;
// 	}else {
// 		return collator.compare(this.getNome(), this.getNome()+this.getNome().length(), o.getNome(), o.getNome()+o.getNome().length());
// 	}
// }
