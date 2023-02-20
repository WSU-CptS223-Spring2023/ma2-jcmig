prog: main.o
		g++ -g main.o -o MA2

main.o: main.cpp BST.h
		g++ -g -Wall -std=c++11

clean:
		-rm *.o

run: @./MA2