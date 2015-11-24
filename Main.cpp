#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <list>
#include <map>
#include <cstring>
#include <string>
//#include "Midia.cpp"

using namespace std;

/**
 * Verifica se um string pertence a um vetor de strings
 * @param args vetor de strings
 * @param param string a ser procurado no vetor
 * @return indice do string no vetor ou -1 caso nao foi encontrado
 */
int isIn(char *args[], char param[]){
	
	int i;
	
	for(i=0;i<sizeof(args);i++)
		if(!strcmp(param,args[i]))
			return i;
	
	return -1;
	
}

/**
 * Metodo principal para execucao do programa
 * @param args argumentos passados por linha de comando
 * @throws IOException
 * @throws ParseException
 */
int main(int argc, char *argv[]){
	
	//list<Pessoa> p;
	//map<String,Genero> g;
	//list<Midia> m;
	//list<Emprestimo> e;
	bool ro;
	int idx;
	
	if(isIn(argv, "--write-only")!=-1){
		
		//TODO
		/*try{
			FileInputStream fis = new FileInputStream("inventario.dat");
			ois = new ObjectInputStream(fis);
			
			g =  (Map<String, Genero>) ois.readObject();
			p = ((List<Pessoa>) ois.readObject());
			m = ((List<Midia>) ois.readObject());
			e = ((List<Emprestimo>) ois.readObject());
			
			FileIO.generatorWishList(m);
			FileIO.writeMidiaPessoas(m,p);
			FileIO.generatorEstatisticas(m, g);
			FileIO.writeEmprestimos(e);
			
		}
		catch(IOException ex){
			ex.printStackTrace();
		}
		catch(Exception ex){
			ex.printStackTrace();
		}*/
		
	}
	else{
		
		if(isIn(argv, "--read-only")!=-1)
			ro = true;
		else
			ro = false;
		
		idx = isIn(argv, "-g");
		if(idx!=-1){
			
			//TODO
			//g = FileIO.readGenero(new File(".").getCanonicalPath()+"/"+args[idx+1]);
			
		}
		
		idx = isIn(argv, "-p");
		if(idx!=-1){
			
			//TODO
			//p = FileIO.readPessoa(new File(".").getCanonicalPath()+"/"+args[idx+1]);
			
		}
		
		idx = isIn(argv, "-m");
		if(idx!=-1){
			
			//TODO
			/*m = FileIO.readMidia(new File(".").getCanonicalPath()+"/"+args[idx+1],p,g);
			
			if(!ro){
				
				FileIO.generatorWishList(m);
				FileIO.writeMidiaPessoas(m,p);
				FileIO.generatorEstatisticas(m, g);
				
			}*/
			
		}
		
		idx = isIn(argv, "-e");
		if(idx!=-1){
			
			//TODO
			/*e = FileIO.readEmprestimos(new File(".").getCanonicalPath()+"/"+args[idx+1], m);
			
			if(!ro){
				
				FileIO.writeEmprestimos(e);
				
			}*/
			
		}
		
		if(ro){
			
			//TODO
			/*try{
				FileOutputStream fos = new FileOutputStream("inventario.dat");
				oos = new ObjectOutputStream(fos);
				
				oos.writeObject(g);
				oos.writeObject(p);
				oos.writeObject(m);
				oos.writeObject(e);
			}
			catch(IOException ex){
				ex.printStackTrace();
			}
			catch(Exception ex){
				ex.printStackTrace();
			}*/
			
		}
		
	}

}
