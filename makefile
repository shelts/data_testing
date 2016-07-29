CC = g++
CFLAGS = -std=c++11
all: output_test virial_test

DEPS = structs.h utility_functions.cpp utility_functions.h
output_test: $(DEPS) output_test.cpp pots_dens.cpp pots_dens.h 
	$(CC)  $(CFLAGS) output_test.cpp pots_dens.cpp utility_functions.cpp  -o output_test

virial_test: $(DEPS) virial_test.cpp pots_dens.cpp pots_dens.h 
	$(CC) $(CFLAGS) virial_test.cpp pots_dens.cpp  utility_functions.cpp -o virial_test


clean:
	$(RM)  *.o *~ output_test virial_test