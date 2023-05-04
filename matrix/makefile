Matrix(): Matrix.cpp Matrix.h
	g++ -c Matrix.cpp

p1(): p1.cpp Matrix.h
	g++ -c p1.cpp

p1: Matrix.cpp Matrix.h p1.cpp Matrix.o p1.o
	g++ -Wall -std=c++14  -pedantic-errors -c Matrix.cpp
	g++ -Wall -std=c++14  -pedantic-errors -c p1.cpp
	g++ -o p1 Matrix.o p1.o

run:
	./p1
