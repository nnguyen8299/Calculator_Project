# Makefile for Calculator Project
CC 		  := g++ 
CPP_FLAGS := -std=c++11

# not sure if SRC is necessary
SRC       := C:\Users\nnguy\Documents\Calculator_Project

# This links the two object files into an executable "a"
a.out: main.o calculator.o
	$(CC) $(CPP_FLAGS) main.o calculator.o

# This creates the object file main.o by using main.cpp and 
# calculator.h
main.o: main.cpp calculator.h
	$(CC) $(CPP_FLAGS) -c main.cpp 

# This creates the calculator object file by using the following
# two files
calculator.o: calculator.cpp calculator.h
	$(CC) $(CPP_FLAGS) -c calculator.cpp

