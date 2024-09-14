flags=-O3 -Wall -std=c2x
ldflags=../libutils/libutils.o

all : clean nm-naive

nm-naive: nm-naive.o
		cc ${flags} $^ -o $@ ${ldflags}

nm-naive.o : nm-naive.c
		cc ${flags} -c $^

clean :
		rm -f *.o nm-naive
