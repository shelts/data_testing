CC = g++
CFLAGS = -std=c++11
all: output_test virial_test

output_test: output_test.cpp pots_dens.cpp pots_dens.h structs.h
	$(CC)  $(CFLAGS) output_test.cpp pots_dens.cpp -o output_test

virial_test: virial_test.cpp pots_dens.cpp pots_dens.h structs.h
	$(CC) $(CFLAGS) virial_test.cpp pots_dens.cpp -o virial_test



clean:
	$(RM)  *.o *~ output_test virial_test