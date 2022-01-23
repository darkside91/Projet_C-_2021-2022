CC=g++
CCFLAGS= -Wall -std=c++11 -g
LIBFLAGS= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)
OBJ_SRC = $(filter-out testcases.o, $(OBJ))
TST= $(wildcard $(TST_DIR)/*.cpp)
OBJ_TEST = $(filter-out main.o, $(OBJ)) $(TST:.cpp=.o)
EXEC= Last_Earth


all: $(EXEC)

testcases: testcases.cpp $(OBJ_SRC)
	 $(CC) $(CCFLAGS) -c testcases.cpp ; $(CC) $(CCFLAGS) -o $@ $(OBJ_TEST) $(LIBFLAGS)

$(EXEC): $(OBJ_SRC)
	$(CC) $(OBJ_SRC) -o $@  $(LIBFLAGS)

%.o: %.cc
	$(CC) $(CCFLAGS) -o $@ -c $<  $(LIBFLAGS)


clean:
	rm -f $(OBJ_SRC) $(EXEC)

cleantest:
	rm -f testcases.o testcases



