flags=-O3 -Wall -std=c2x -fPIC -shared -ldl -D_GNU_SOURCE
ldflags=

all : clean libutils.so

libutils.so : libutils.o
		cc ${flags} $^ -o $@
libutils.o  : libutils.c
		cc $(flags) -c $^

clean:
		rm -f libutils.o libutils.so
