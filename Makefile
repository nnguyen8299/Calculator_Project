# Makefile for Calculator Project
CC 		  := g++ 
CPP_FLAGS := -std=c++11

# not sure if SRC is necessary
SRC       := C:\Users\nnguy\Documents\Calculator_Project

# compiling
a.out: main.o calculator.o
	$(CC) $(CPP_FLAGS) main.o calculator.o

main.o: main.cpp calculator.h
	$(CC) $(CPP_FLAGS) -c main.cpp 

calculator.o: calculator.cpp calculator.h
	$(CC) $(CPP_FLAGS) -c calculator.cpp