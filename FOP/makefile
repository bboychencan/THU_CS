BIN = pintu
OBJ = pintu.o picture.o game.o puzzle.o
CPP = g++
FILES = pintu.cpp picture.cpp game.cpp puzzle.cpp

$(BIN): 	$(OBJ)
	$(CPP) -o $@ $(OBJ)

pintu.o: 	pintu.cpp my_function.h
	$(CPP) -c pintu.cpp

picture.o:	picture.cpp my_function.h
	$(CPP) -c picture.cpp

game.o:		game.cpp my_function.h
	$(CPP) -c game.cpp

puzzle.o:	puzzle.cpp my_function.h
	$(CPP) -c puzzle.cpp

.PHONY:	clean
clean:
	rm $(OBJ) $(BIN)