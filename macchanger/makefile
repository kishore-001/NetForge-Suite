opt = -O3 -Wall

# Define the default target
all: clean altermac

# Rule to build the executable
altermac: altermac.o
	cc ${opt} $^ -o $@

# Rule to compile the source file into an object file
altermac.o: altermac.c
	cc ${opt} -c $< -o $@

# Rule to clean up generated files
clean:
	rm -f altermac *.o

