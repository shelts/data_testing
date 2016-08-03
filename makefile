# /* Copyright (c) 2016 Siddhartha Shelton */
CC = g++
CFLAGS = -std=c++11
all: output_test virial_test
INC_DIR = -I/headers/
SRC_DIR = -I/src/
HEADERS = pots_dens.h dist_funcs.h
DEPS = structs.h  utility_functions.h $(HEADERS)
SRC = utility_functions.cpp pots_dens.cpp dist_funcs.cpp 



output_test: $(DEPS) output_test.cpp $(SRC) 
	$(CC)  $(CFLAGS) output_test.cpp $(SRC) -o output_test

virial_test: $(DEPS) virial_test.cpp $(SRC) 
	$(CC) $(CFLAGS) virial_test.cpp $(SRC) -o virial_test


clean:
	$(RM)  *.o *~ output_test virial_test 