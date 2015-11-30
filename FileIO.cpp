#include <iostream>
#include <cstdlib>
#include <list>
#include <map>
#include <fstream>
#include <cstring>
#include "Midia.h"
#include "Genero.h"
#include <vector>
#include <cstring>
#include "Pessoa.h"

using namespace std;

class Genero;
class Pessoa;

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
    if(cutAt > 0) {
      results.push_back(str.substr(0,cutAt));
    }
    str = str.substr(cutAt+1);
  }
  if(str.length() > 0) {
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
	int count = 0;

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
		g.insert(pair<string,Genero>(partes[count],Genero(partes[count],partes[count+1])));	
		count +=2;
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
	int count = 0;

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
		if(count < partes.size())
			p.insert(pair<int,Pessoa>(atoi(partes[count].c_str()),Pessoa(atoi(partes[count].c_str()),partes[count+1])));	

		count +=2;
	}	

		//cout << count << endl;		

	inFile.close();
	return p;
}

/*
map<int,Midia> static readMidia(char *file, map<int,Pessoa> lPessoas, map<string,Genero> lGenero)
{
	map<int,Midia> m;
	ifstream inFile(file);
	string line;
	vector<string> partes;
	int count = 0;

	if(!inFile) 
	{
		cout << "Não foi possivel abrir o arquivo de entrada : " << file << " Saindo do programa!\n";
		return g;
	}

	getline(inFile,line);

	while(!inFile.eof())
	{
		getline(inFile,line);	
		StringSplit(line,";",partes);


	}




}*/
