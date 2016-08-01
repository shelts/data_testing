# /* Copyright (c) 2016 Siddhartha Shelton */
CC = g++
CFLAGS = -std=c++11
all: output_test virial_test

HEADERS = ./headers/pots_dens.h ./headers/dist_funcs.h
DEPS = ./headers/structs.h  ./headers/utility_functions.h $(HEADERS)
CPPS = utility_functions.cpp pots_dens.cpp dist_funcs.cpp 


output_test: $(DEPS) output_test.cpp $(CPPS) 
	$(CC)  $(CFLAGS) output_test.cpp $(CPPS) -o output_test

virial_test: $(DEPS) virial_test.cpp $(CPPS) 
	$(CC) $(CFLAGS) virial_test.cpp $(CPPS) -o virial_test


clean:
	$(RM)  *.o *~ output_test virial_test