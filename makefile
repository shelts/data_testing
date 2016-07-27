CC = g++
CFLAGS  = -I -std=c++11

DEPS = pots_dens.h
OBJ = output_test.o virial_test.o pots_dens.o 
default: output_test

%.o: %.c $(DEPS) #all the object files depend on their .c files and the headers in DEPS
	$(CC) -c -o $@ $< $(CFLAGS)
#The rule then says that to generate the .o file, 
#make needs to compile the .c file using the compiler defined in the CC macro. 
#The -c flag says to generate the object file, the -o $@ says to put the output 
#of the compilation in the file named on the left side of the :, the $< is the first item in the dependencies list

output_test:  $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(CFLAGS)

clean: 
	$(RM) count *.o *~