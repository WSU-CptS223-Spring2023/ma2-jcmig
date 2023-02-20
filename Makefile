prog: main.o
		g++ -g main.o -o MA2

main.o: main.cpp BST.h
		g++ -c -g -Wall -std=c++11 main.cpp 

clean:
		-rm *.o

run: @./MA2