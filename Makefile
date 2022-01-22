CC=g++
CCFLAGS= -Wall -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
SRC= $(wildcard *.cc)
OBJ= $(SRC:.cc=.o)




all: 
	g++ main.cpp game.cpp Cases.cpp Joueur.cpp Personnage.cpp Humains.cpp Femmes.cpp Hommes.cpp Mutants.cpp MutantsF_plus.cpp MutantsF_minus.cpp Mutants_pm.cpp -o main -Wall -lsfml-network -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system




clean:
	rm -f $(OBJ) $(EXEC)


