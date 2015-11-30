#include "FileIO.cpp"

using namespace std;

/**
 * Verifica se um string pertence a um vetor de strings
 * @param args vetor de strings
 * @param param string a ser procurado no vetor
 * @return indice do string no vetor ou -1 caso nao foi encontrado
 */
int isIn(char *args[], char param[], int argc)
{
	
	int i;
	//int n = sizeof(args);
	
	for(i=0;i<argc;i++)
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
	
	map<int,Pessoa> p;
	map<string,Genero> g;
	list<Midia> m;
	//list<Emprestimo> e;
	bool ro;
	int idx;
	
	if(isIn(argv, (char*)"--write-only",argc)!=-1){
		
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
		
		if(isIn(argv, (char*)"--read-only",argc)!=-1)
			ro = true;
		else
			ro = false;
		
		idx = isIn(argv, (char*)"-g",argc);
		if(idx!=-1){
			
			//TODO
			//g = FileIO.readGenero(new File(".").getCanonicalPath()+"/"+args[idx+1]);
			//cout << "OLA MUNDO\n" << endl;
			g = readGenero(argv[idx+1]);
			cout << g.find("CA")->second.getNome() << "\n";
			
		}
		
		idx = isIn(argv, (char*)"-p",argc);
		if(idx!=-1){
			
			//TODO
			
			p = readPessoa(argv[idx+1]);
			cout << p.find(30)->second.getNome() << "\n";
		}
		
		idx = isIn(argv, (char*)"-m",argc);
		if(idx!=-1){
			
			//TODO
			/*m = FileIO.readMidia(new File(".").getCanonicalPath()+"/"+args[idx+1],p,g);
			
			if(!ro){
				
				FileIO.generatorWishList(m);
				FileIO.writeMidiaPessoas(m,p);
				FileIO.generatorEstatisticas(m, g);
				
			}*/
			
		}
		
		idx = isIn(argv, (char*)"-e",argc);
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
