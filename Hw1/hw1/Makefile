
GCC = g++
CXXFLAGS = -g -Wall


hw1: hw1rr.o sorting.o 
	g++ -g -o hw1  hw1rr.o sorting.o
hw1rr.o: hw1rr.cpp sorting.o
	g++ -c -g hw1rr.cpp

sorting.o:sorting.cpp sorting.h 
	g++ -c sorting.cpp

.PHONY: clean

clean:
	rm -f *.exe *.o
