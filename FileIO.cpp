#include <iostream>
#include <cstdlib>
#include <list>
#include <map>
#include <fstream>
#include <cstring>
#include "Filme.h"
#include "Livro.h"
#include "Serie.h"
#include "Emprestimo.h"
#include <vector>
#include <cstring>
#include <algorithm>
#include <ctime>

using namespace std;

class Genero;
class Pessoa;
class Midia;
class Emprestimo;

/**
 * [StringSplit description]
 * @param  str     [description]
 * @param  delim   [description]
 * @param  results [description]
 * @return         [description]
 */
void static StringSplit(string str, string delim, vector<string>& results)
{
  int cutAt;
  while((cutAt = str.find_first_of(delim)) != str.npos)
  {
    if(cutAt >= 0) {
      results.push_back(str.substr(0,cutAt));
    }
    str = str.substr(cutAt+1);
  }
  if(str.length() >= 0) {
    results.push_back(str);
  }
}

/**
 * [readGenero description]
 * @param  file [description]
 * @return      [description]
 */
map<string,Genero> static readGenero(char *file)
{
	// char *ptr;
	map<string,Genero> g;
	ifstream inFile(file);
	string line;
	vector<string> partes;

	if(!inFile) 
	{
		cout << "Não foi possivel abrir o arquivo de entrada : " << file << " Saindo do programa!\n";
		return g;
	}

	getline(inFile,line);
	
	while(!inFile.eof())
	{
		getline(inFile,line);			
//		cout << line << endl;
		StringSplit(line,";",partes);
		g.insert(pair<string,Genero>(partes[0],Genero(partes[0],partes[1])));	
		// count +=2;

		partes.clear();
	}

	inFile.close();
	return g;
 
}


/**
 * [readPessoa description]
 * @param  file [description]
 * @return      [description]
 */
map<int,Pessoa> static readPessoa(char *file)
{
	map<int,Pessoa> p;
	ifstream inFile(file);
	string line;
	vector<string> partes;
	// unsigned int count = 0;

	if(!inFile) 
	{
		cout << "Não foi possivel abrir o arquivo de entrada : " << file << " Saindo do programa!\n";
		return p;
	}

	getline(inFile,line);

	while(!inFile.eof())
	{
		getline(inFile,line);	
		// cout << line << endl;		
		StringSplit(line,";",partes);
		// if(count < partes.size())
			p.insert(pair<int,Pessoa>(atoi(partes[0].c_str()),Pessoa(atoi(partes[0].c_str()),partes[1])));	
		partes.clear();
	}	

		//cout << count << endl;		
	inFile.close();
	return p;
}

/**
 * [createlAtores description]
 * @param  codAutores [description]
 * @param  l          [description]
 * @return            [description]
 */
list<Pessoa> static createlAtores(string codAutores, map<int,Pessoa> l)
{
	list<Pessoa> autores;
	vector<string> partes;
	StringSplit(codAutores,",",partes);
	//cout << codAutores << "\n";
	for(unsigned int i = 0; i < partes.size();i++)
	{
	 	int idPessoa = atoi(partes[i].c_str());
	 	//cout << idPessoa << "\n";
	 	autores.push_back(l.find(idPessoa)->second);
	}

	return autores;
}

/**
 * [readMidia description]
 * @param  file     [description]
 * @param  lPessoas [description]
 * @param  lGenero  [description]
 * @return          [description]
 */
map<int,Midia> static readMidia(char *file, map<int,Pessoa> lPessoas, map<string,Genero> lGenero)
{
	map<int,Midia> m;
	list<Pessoa> elenco; 
	ifstream inFile(file);
	string line;
	vector<string> partes;
	// int count = 0;

	if(!inFile) 
	{
		cout << "Não foi possivel abrir o arquivo de entrada : " << file << " Saindo do programa!\n";
		return m;
	}

	getline(inFile,line);

	while(!inFile.eof())
	{
		Pessoa diretor;
		getline(inFile,line);
		StringSplit(line,";",partes);
		int codigo = atoi(partes[0].c_str());
		string nome = partes[1];
		char type = partes[2].at(0);
		string dir = partes[3];
		if(dir.length()>0)
		{
		 	int id = atoi(dir.c_str());
		 	diretor = lPessoas.find(id)->second;
		}
		 //string lAutores = partes[4];		 
		/** LER LISTA DE AUTORES */
		if(partes[4].length()>0)
			elenco = createlAtores(partes[4],lPessoas);
		int tamanho = atoi(partes[5].c_str());
		string gen = partes[6];
		string serie = partes[7];
		string temporada = partes[8];
		bool possui = !partes[9].compare("x");
		bool consumiu = !partes[10].compare("x") ;
		bool deseja = !partes[11].compare("x");
		replace(partes[12].begin(),partes[12].end(),',','.');
		double preco = atof(partes[12].c_str());

		switch(type)
		{
			case 'L':
				m.insert(pair<int,Midia>(codigo,Livro(codigo,nome,tamanho,lGenero.find(gen)->second,possui,consumiu,deseja,preco,elenco)));
				break;
			case 'F':
				m.insert(pair<int,Midia>(codigo,Filme(codigo,nome,tamanho,lGenero.find(gen)->second,possui,consumiu,deseja,preco,diretor,elenco)));
				break;
			case 'S': 
				m.insert(pair<int,Midia>(codigo,Serie(codigo,nome,tamanho,lGenero.find(gen)->second,possui,consumiu,deseja,preco,elenco,temporada,serie)));
				break;
		}
		elenco.clear();		
		partes.clear();
	}
	inFile.close();

	return m;

}

/**
 * [readEmprestimo description]
 * @param  file [description]
 * @param  m    [description]
 * @return      [description]
 */
map<int,Emprestimo> static readEmprestimo(char *file)
{
	time_t t;
	time_t f;
	map<int,Emprestimo> e;
	ifstream inFile(file);
	string line;
	vector<string> partes;
	vector<string>data;
	tm *dateEmp, *dateDev;

	getline(inFile,line);
	time(&t);
	while(!inFile.eof())
	{
		getline(inFile,line);
		StringSplit(line,";",partes);
		int codigo = atoi(partes[0].c_str());
		string nome = partes[1];
		StringSplit(partes[2],"/",data);
		
		dateEmp = localtime(&t);
		dateEmp->tm_year = atoi(data[2].c_str());
		dateEmp->tm_mon = atoi(data[1].c_str());
		dateEmp->tm_mday = atoi(data[0].c_str());
		data.clear();
		StringSplit(partes[3],"/",data);
		dateDev = localtime(&f);
		dateDev->tm_year = atoi(data[2].c_str());
		dateDev->tm_mon = atoi(data[1].c_str());
		dateDev->tm_mday = atoi(data[0].c_str());
		data.clear();
		mktime(dateEmp);
		mktime(dateEmp);
		//cout << codigo << " - " << dateEmp->tm_mday << "/" << dateEmp->tm_mon << "/" << dateEmp->tm_year << endl;
		cout << codigo << " - " << dateDev->tm_mday << "/" << dateDev->tm_mon << "/" << dateDev->tm_year << endl;
		e.insert(pair<int,Emprestimo>(codigo,Emprestimo(codigo,nome,dateEmp,dateDev)));
		partes.clear();
	}
	inFile.close();
	return e;
}

vector<Midia> static mapToVectorMidia(map<int,Midia>m,vector<Midia>& l)
{
	for (map<int,Midia>::iterator it=m.begin(); it!=m.end(); ++it)
		l.push_back(it->second);
	
	return l;
}


void static generatorWishList(map<int,Midia> m)
{
	ofstream outFile("4-wishlist.csv");
	vector<Midia> lMidias;
	outFile << "Tipo;Mídia;Gênero;Preço" << endl;
	mapToVectorMidia(m,lMidias);

	/* TEMOS QUE ORDENAR O VETOR DA FORMA QUE O PROFESSOR QUER !!! */
	for(unsigned int i = 0; i < lMidias.size(); i++)
	{
		if(lMidias[i].isDeseja())
		{
			switch(lMidias[i].getType())
			{
				case 'L': outFile << "Livro;" << lMidias[i].getNome() <<";"<< lMidias[i].getGenero().getNome()<<";"<<lMidias[i].getPreco()<< endl;
					break;
				case 'F': outFile << "Filme;" << lMidias[i].getNome() <<";"<< lMidias[i].getGenero().getNome()<<";"<<lMidias[i].getPreco() << endl;
					break;
				case 'S': outFile << "Série;" << lMidias[i].getNome() <<";"<< lMidias[i].getGenero().getNome()<<";"<<lMidias[i].getPreco() << endl;
					break;
				
			}
		}
	}

	outFile.close();

}
