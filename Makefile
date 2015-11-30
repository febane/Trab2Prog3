CC=g++
FLAGS= $(WARN) -O2 $G
WARN= -Wall -Wextra
SOURCES= Main.cpp Midia.cpp Genero.cpp FileIO.cpp Pessoa.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXEC=trab2

all:
	$(CC) -o $(EXEC) $(SOURCES) $(FLAGS) 

clean:
	rm -f $(EXEC)

debug:
	$(CC) -o $(EXEC) $(SOURCES) $(FLAGS) -g
