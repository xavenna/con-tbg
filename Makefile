CFLAGS = -Wall -fexceptions -std=c++17 -g 
OBJ = main.o usefrt.o cipstr.o exesim.o funcs.o
game.exe : $(OBJ)
	g++ -o game.exe $(OBJ)
main.o : main.cpp usefrt.h contbg.h randword.h
	g++ $(CFLAGS) -c main.cpp -o main.o
funcs.o : funcs.cpp contbg.h cipstr.h
	g++ $(CFLAGS) -c funcs.cpp -o funcs.o
exesim.o : exesim.cpp contbg.h
	g++ $(CFLAGS) -c exesim.cpp -o exesim.o
usefrt.o : usefrt.cpp usefrt.h
	g++ $(CFLAGS) -c usefrt.cpp -o usefrt.o
cipstr.o : cipstr.cpp cipstr.h
	g++ $(CFLAGS) -c cipstr.cpp -o cipstr.o
.PHONY : clean
clean :
	rm game.exe $(OBJ)
